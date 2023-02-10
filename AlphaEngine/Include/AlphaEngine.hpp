#ifndef ALPHASNAKE_ALPHAENGINE_HPP
#define ALPHASNAKE_ALPHAENGINE_HPP
#include "tangara.h"

namespace AlphaEngine {
    tgPtr Setup();
    void AddUpdatable(tgPtr type);
    void AddSystem(tgPtr type);
    void MainLoop();
    void Quit();
    void Destroy();
}

extern "C"
{
    void AlphaEngine_Quit(tgPtr stack);
}

#endif //ALPHASNAKE_ALPHAENGINE_HPP
