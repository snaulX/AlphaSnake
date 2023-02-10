#include "RenderSystem.h"
#include <stdlib.h>
#include <string.h> // for memset
#include <stdio.h>

#if defined(_WIN32) || defined(__WIN32__)
#define RENDERSYSTEM_EXPORT __declspec(dllexport)
#elif defined(linux) || defined(__linux)
#define RENDERSYSTEM_EXPORT
#endif

struct {
    tgPtr type;
    tgOPtr ctor0_offset;
    tgOPtr Prepare_offset;
    tgOPtr DrawRect_offset;
    tgOPtr DrawPoint_offset;
} RenderSystem;
struct {
    tgPtr type;
    tgFunc Quit;
} AlphaEngine;

RENDERSYSTEM_EXPORT void tgLoad(tgPtr heap)
{
    RenderSystem.type = tgCreateType(heap, "RenderSystem");
    RenderSystem.ctor0_offset = tgTypeAddFunc(RenderSystem.type, RenderSystem_new);
    RenderSystem.Prepare_offset = tgTypeAddFunc(RenderSystem.type, RenderSystem_Prepare);
    RenderSystem.DrawRect_offset = tgTypeAddFunc(RenderSystem.type, RenderSystem_DrawRect);
    RenderSystem.DrawPoint_offset = tgTypeAddFunc(RenderSystem.type, RenderSystem_DrawPoint);
    tgTypeBeginParent(RenderSystem.type, "AlphaEngine.IUpdatable");
    tgTypeAddFunc(RenderSystem.type, RenderSystem_Update);
    tgEndType(RenderSystem.type);

    AlphaEngine.type = tgHeapGet(heap, "AlphaEngine");
    AlphaEngine.Quit = tgTypeGetFunc(AlphaEngine.type, 0);
}

typedef struct {
    int w;
    int h;
    char** field;
} RenderPlot;

void RenderSystem_new(tgPtr stack) {
    const size_t size = sizeof(RenderPlot);
    RenderPlot *plot = malloc(size);
    memset(plot, 0, size);
    tgStackNewObj(stack, plot, RenderSystem.type);
}

struct Prepare_Args {
    RenderPlot *plot;
    int w;
    int h;
};
void RenderSystem_Prepare(tgPtr stack) {
    struct Prepare_Args args = *(struct Prepare_Args*)tgStackPop(stack);
    char **field = (char**)calloc(args.h, sizeof(char*));
    *field = (char*)calloc(args.w, sizeof(char));
    for (int i = 0; i < args.h; i++) {
        for (int j = 0; j < args.w; j++) {
            field[i][j] = ' ';
        }
    }
    free(args.plot); // Clean it if for some reason RenderPlot was ready
    args.plot = malloc(sizeof(RenderPlot));
    args.plot->w = args.w;
    args.plot->h = args.h;
    args.plot->field = field;
}

struct DrawRect_Args {
    RenderPlot *plot;
    char ch;
    int x;
    int y;
    int w;
    int h;
};
void RenderSystem_DrawRect(tgPtr stack) {
    struct DrawRect_Args args = *(struct DrawRect_Args*)tgStackPop(stack);
    if (args.x + args.w >= args.plot->w || args.x < 0)  {
        perror("Wrong horizontal coord for drawing point");
        return;
    }
    else if (args.y + args.h >= args.plot->h || args.y < 0) {
        perror("Wrong vertical coord for drawing point");
        return;
    }
}

struct DrawPoint_Args {
    RenderPlot *plot;
    char ch;
    int x;
    int y;
};
void RenderSystem_DrawPoint(tgPtr stack) {
    struct DrawPoint_Args args = *(struct DrawPoint_Args*)tgStackPop(stack);
    if (args.x >= args.plot->w || args.x < 0)  {
        perror("Wrong X coord for drawing point");
        return;
    }
    else if (args.y >= args.plot->h || args.y < 0) {
        perror("Wrong Y coord for drawing point");
        return;
    }
    args.plot->field[args.y][args.x] = args.ch;
}

void RenderSystem_Update(tgPtr stack) {
    RenderPlot *plot = (RenderPlot*)tgStackPop(stack);
    int a;
    scanf_s("%d", &a);
    printf_s("a is %d\n", a);
    if (a == 0)
        AlphaEngine.Quit(stack);
    system("cls"); // clear console
    for (int i = 0; i < plot->h; i++) {
        for (int j = 0; j < plot->w; j++) {
            printf("%c", plot->field[i][j]);
        }
        printf("\n");
    }
}
