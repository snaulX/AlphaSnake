#include <vector>
#include "AlphaEngine.hpp"
#include "JobSystem.hpp"

namespace AlphaEngine {
    tgPtr heap;
    const tgStr updatable_name = "AlphaEngine.IUpdatable";
    tgOPtr update_function_offset = 0;
    std::vector<tgFunc> update_functions;
    std::vector<uint32_t> updatable_indexes;
    std::vector<tgPtr> systems;
    JobSystem *jobSystem;

    // Init functions
    tgPtr Setup()
    {
        heap = tgCreateHeap();
        // Make IUpdatable
        tgPtr updatable = tgCreateInterface(heap, updatable_name);
        update_function_offset = tgInterfaceAddPtr(updatable);

        // Make AlphaEngine
        tgPtr alphaEngine = tgCreateType(heap, "AlphaEngine");
        tgTypeAddFunc(alphaEngine, AlphaEngine_Quit);

        jobSystem = new JobSystem();
        return heap;
    }

    void AddUpdatable(tgPtr type) {
        updatable_indexes.push_back(systems.size()); // add to know what index in 'systems' for this updatable
        AddSystem(type);
        tgOPtr updatable_impl = tgTypeExposeParent(type, updatable_name);
        update_functions.push_back(tgTypeGetFunc(type, updatable_impl + update_function_offset));
    }

    void AddSystem(tgPtr type) {
        systems.push_back(type);
    }

    // Work with main loop and stack
    bool is_working = false;
    tgPtr stack;
    std::vector<tgPtr> system_instances;

    void update_one(JobDispatchArgs args) {
        uint32_t index = args.jobIndex+args.groupIndex;
        tgStackPush(stack, system_instances[
                updatable_indexes[index] // get index in 'system_instances' for this IUpdatable
                ]); // push system instance before call Update
        update_functions[index](stack);
    }

    void MainLoop() {
        is_working = true;
        stack = tgCreateStack();
        // Create all instances of systems
        system_instances = std::vector<tgPtr>(systems.size());
        for (int i = 0; i < systems.size(); i++) {
            tgFunc ctor = tgTypeGetFunc(systems[i], 0);
            jobSystem->Execute([i, ctor]() {
                printf_s("Object start creating\n");
                ctor(stack);
                printf_s("Object was created\n");
                system_instances[i] = tgStackPop(stack);
            });
        }
        jobSystem->Wait();
        // Start main loop
        while (is_working) {
            auto start = std::chrono::system_clock::now();
            update_functions[0](stack);
            jobSystem->Dispatch(update_functions.size(), 1, update_one);
            jobSystem->Wait();
            auto end = std::chrono::system_clock::now();
            printf_s("Frame time: %d\n", std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
        }
        tgFreeStack(stack);
    }

    void Quit() {
        is_working = false;
    }

    // End functions

    void Destroy() {
        delete jobSystem;
        tgFreeHeap(heap);
    }
}

void AlphaEngine_Quit(tgPtr stack) {
    AlphaEngine::Quit();
}