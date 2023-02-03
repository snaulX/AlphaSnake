#include "Heap.hpp"

namespace Tangara {
    Heap::Heap() = default;

    Heap::~Heap() = default;

    void Heap::AddPtr(std::string name, tgPtr data) {
        _table[name] = data;
    }

    tgPtr Heap::GetPtr(std::string name) {
        return _table[name];
    }
}

using namespace Tangara;

tgPtr tgCreateHeap() {
    return new Heap();
}

void tgFreeHeap(tgPtr heap) {
    delete ((Heap*)heap);
}

tgPtr tgPtrGet(tgPtr ptr, tgOPtr offset) {
    return (tgPtr)((char*)ptr+offset);
}

tgPtr tgObjectGet(tgPtr obj, tgOPtr offset) {
    return *((tgPtr*)((char*)obj+offset)); // certified shit-code moment
}

void tgObjectSet(tgPtr obj, tgOPtr offset, tgPtr value) {
    *((tgPtr*)tgPtrGet(obj, offset)) = value;
}

tgPtr tgHeapGet(tgPtr heap, tgStr name) {
    return ((Heap*)heap)->GetPtr(name);
}