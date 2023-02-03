#include "Stack.hpp"
#include "tangara.h"
#include "Type.hpp"

namespace Tangara {

    void Stack::Push(tgPtr ptr) {
        _stack.push(ptr);
    }

    tgPtr Stack::Top() {
        return _stack.top();
    }

    tgPtr Stack::Pop() {
        tgPtr top = _stack.top();
        _stack.pop();
        return top;
    }
}

using namespace Tangara;

void tgFreeStack(tgPtr stack) {
    delete ((Stack*)stack);
}

void tgStackPush(tgPtr stack, tgPtr ptr) {
    ((Stack*)stack)->Push(ptr);
}

tgPtr tgStackPop(tgPtr stack) {
    return ((Stack*)stack)->Pop();
}

tgPtr tgStackNewObj(tgPtr stack, tgPtr type, tgPtr data) {
    tgPtr* _newObj = (tgPtr*)malloc(((Type*)type)->GetSize());
    _newObj[0] = data;
    ((Stack*)stack)->Push(_newObj);
    return _newObj;
}

tgPtr tgCreateStack() {
    return new Stack();
}
