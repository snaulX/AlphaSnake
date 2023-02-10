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
    AlphaEngine::MainLoop();
    AlphaEngine::Destroy();
    return 0;
}
