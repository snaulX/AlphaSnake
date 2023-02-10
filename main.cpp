#include "dlload.h"
#include "tangara.h"
#include "AlphaEngine.hpp"

int main() {
    tgPtr heap = AlphaEngine::Setup();
    // load RenderSystem
    DLIB renderLib = dlload("bin/RenderSystem");
    tgLoadFunc load_render = (tgLoadFunc)dlfunc(renderLib, "tgLoad");
    load_render(heap);
    tgPtr render_system = tgHeapGet(heap, "RenderSystem");
    AlphaEngine::AddUpdatable(render_system);
    // load InputSystem
    //CSharpLoad("bin/InputSystem.dll", heap);
    //tgPtr input_system = tgHeapGet(heap, "InputSystem");
    //AlphaEngine::AddUpdatable(input_system);
    // load Game
    //LuaLoad("Game.lua", heap);
    AlphaEngine::MainLoop();
    AlphaEngine::Destroy();
    return 0;
}
