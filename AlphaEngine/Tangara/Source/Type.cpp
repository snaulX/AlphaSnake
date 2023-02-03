#include <cstdlib>
#include "Type.hpp"
#include "Heap.hpp"

namespace Tangara {
    tgOPtr Type::AddFunc(tgFunc func) {
        tgOPtr result = _funcs.size();
        _funcs.push_back(func);
        return result;
    }

    tgFunc Type::GetFunc(tgOPtr index) {
        return _funcs[index];
    }

    tgOPtr Type::BeginParent(std::string name) {
        _parents[name] = _funcs.size();
        return _funcs.size();
    }

    tgOPtr Type::GetParent(std::string name) {
        return _parents[name];
    }

    void Type::EndWrite() {
        _funcs.shrink_to_fit();
    }

    Type::Type() = default;

    Type::~Type() {
        _funcs.clear();
    }

    tgOPtr Type::AddVSize(tgOPtr size) {
        tgOPtr prev = _size;
        _size += size;
        return prev;
    }
}

using namespace Tangara;

tgOPtr tgTypeExposeParent(tgPtr type, tgStr name) {
    return ((Type*)type)->GetParent(name);
}
tgPtr tgCreateType(tgPtr heap, tgStr name) {
    tgPtr type = new Type();
    ((Heap*)heap)->AddPtr(name, type);
    return type;
}
tgOPtr tgTypeAddPtr(tgPtr type) {
    return ((Type*)type)->AddVSize(sizeof(tgPtr));
}
tgOPtr tgTypeAddStr(tgPtr type) {
    return ((Type*)type)->AddVSize(sizeof(tgStr));
}
tgOPtr tgTypeAddInt(tgPtr type) {
    return ((Type*)type)->AddVSize(sizeof(int));
}
tgOPtr tgTypeAddFunc(tgPtr type, tgFunc func) {
    return ((Type*)type)->AddFunc(func);
}
tgFunc tgTypeGetFunc(tgPtr type, tgOPtr func_offset) {
    return ((Type*)type)->GetFunc(func_offset);
}
tgOPtr tgTypeBeginParent(tgPtr type, tgStr name) {
    return ((Type*)type)->BeginParent(name);
}
void tgEndType(tgPtr type) {
    ((Type*)type)->EndWrite();
}