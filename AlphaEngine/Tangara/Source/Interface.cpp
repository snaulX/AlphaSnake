#include "Interface.hpp"
#include "Heap.hpp"

namespace Tangara {
    tgOPtr Interface::AddOffset(int offset) {
        tgOPtr result = _offset;
        _offset += offset;
        return result;
    }
}

using namespace Tangara;

tgOPtr tgInterfaceAddPtr(tgPtr iface) {
    return ((Interface*)iface)->AddOffset(sizeof(tgPtr));
}
tgOPtr tgInterfaceAddInt(tgPtr iface) {
    return ((Interface*)iface)->AddOffset(sizeof(int));
}
tgOPtr tgInterfaceAddStr(tgPtr iface) {
    return ((Interface*)iface)->AddOffset(sizeof(tgStr));
}

tgPtr tgCreateInterface(tgPtr heap, tgStr name) {
    tgPtr iface = new Interface();
    ((Heap*)heap)->AddPtr(name, iface);
    return iface;
}