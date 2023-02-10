#ifndef RENDERSYSTEM_RENDERSYSTEM_H
#define RENDERSYSTEM_RENDERSYSTEM_H
#include "tangara.h"

void RenderSystem_new(tgPtr stack);
void RenderSystem_Prepare(tgPtr stack);
void RenderSystem_DrawRect(tgPtr stack);
void RenderSystem_DrawPoint(tgPtr stack);
void RenderSystem_Update(tgPtr stack);

#endif //RENDERSYSTEM_RENDERSYSTEM_H
