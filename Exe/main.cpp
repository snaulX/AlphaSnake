#include "dlload.h"
#include "tangara.h"

int main() {
    tgPtr heap = tgCreateHeap();
    // Make IUpdatable
    tgStr updatable_name = "AlphaEngine.IUpdatable";
    tgPtr updatable = tgCreateInterface(heap, updatable_name);
    tgOPtr update = tgInterfaceAddPtr(updatable);
    // Make example WindowSystem
    tgPtr windowsystem_type = tgCreateType(heap, "EnigmaWindow.WindowSystem");
    tgEndType(windowsystem_type);
    // load RenderSystem
    DLIB renderLib = dlload("RenderSystem");
    tgLoadFunc load_render = (tgLoadFunc)dlfunc(renderLib, "tgLoad");
    load_render(heap);
    tgPtr render_system = tgHeapGet(heap, "EnigmaRender.RenderSystem");
    tgOPtr updatable_render = tgTypeExposeParent(render_system, updatable_name);
    tgFunc update_render = tgTypeGetFunc(render_system, updatable_render + update);
    tgFunc render_ctor = tgTypeGetFunc(render_system, 0);
    // make stack and work with it
    tgPtr stack = tgCreateStack();
    render_ctor(stack);
    tgPtr render_instance = tgStackPop(stack);
    for (int i = 0; i < 60; i++) // imagine here infinite game loop
    {
        tgStackPush(stack, render_instance);
        update_render(stack);
    }
    tgFreeStack(stack);
    tgFreeHeap(heap);
    return 0;
}
