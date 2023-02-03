#ifndef ENIGMAENGINE_INTERFACE_HPP
#define ENIGMAENGINE_INTERFACE_HPP

#include "tangara.h"

namespace Tangara {

    class Interface {
    public:
        Interface() = default;

        ~Interface() = default;

        tgOPtr AddOffset(int offset);
        [[nodiscard]] tgOPtr GetSize() const { return _offset; }
    private:
        tgOPtr _offset = 0;
    };

}

#endif //ENIGMAENGINE_INTERFACE_HPP
