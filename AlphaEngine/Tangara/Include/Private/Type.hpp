#ifndef ENIGMAENGINE_TYPE_HPP
#define ENIGMAENGINE_TYPE_HPP

#include <string>
#include <unordered_map>
#include "tangara.h"
#include "Interface.hpp"

namespace Tangara {
    class Type {
    public:
        Type();

        ~Type();

        tgOPtr AddVSize(tgOPtr size);
        tgOPtr AddFunc(tgFunc func);
        tgFunc GetFunc(tgOPtr index);
        tgOPtr BeginParent(std::string name);
        tgOPtr GetParent(std::string name);
        void EndWrite();
        [[nodiscard]] tgOPtr GetSize() const { return _size; }
    private:
        std::vector<tgFunc> _funcs;
        std::unordered_map<std::string, tgOPtr> _parents;
        tgOPtr _size = sizeof(tgPtr);
    };
}

#endif //ENIGMAENGINE_TYPE_HPP
