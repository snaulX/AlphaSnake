#include "dlload.h"
#include "tangara.h"
#include "AlphaEngine.hpp"

int main() {
    tgPtr heap = AlphaEngine::Setup();
    // load RenderSystem
    DLIB renderLib = dlload("RenderSystem");
    tgLoadFunc load_render = (tgLoadFunc)dlfunc(renderLib, "tgLoad");
    load_render(heap);
    tgPtr render_system = tgHeapGet(heap, "RenderSystem");
    AlphaEngine::AddUpdatable(render_system);
    AlphaEngine::MainLoop();
    AlphaEngine::Destroy();
    return 0;

    //tgFunc render_ctor = tgTypeGetFunc(render_system, 0);
    // make stack and work with it
    tgPtr stack = tgCreateStack();
    //render_ctor(stack);
    tgPtr render_instance = tgStackPop(stack);
    for (int i = 0; i < 60; i++) // imagine here infinite game loop
    {
        tgStackPush(stack, render_instance);
        //update_render(stack);
    }
    tgFreeStack(stack);
    tgFreeHeap(heap);
    return 0;
}
