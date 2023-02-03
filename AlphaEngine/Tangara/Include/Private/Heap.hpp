#ifndef ENIGMAENGINE_HEAP_HPP
#define ENIGMAENGINE_HEAP_HPP

#include <unordered_map>
#include <string>
#include "tangara.h"

namespace Tangara {

    class Heap {
    public:
        Heap();

        ~Heap();

        void AddPtr(std::string name, tgPtr data);
        tgPtr GetPtr(std::string name);
    private:
        std::unordered_map<std::string, tgPtr> _table;
    };

} // Tangara

#endif //ENIGMAENGINE_HEAP_HPP
