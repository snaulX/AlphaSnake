#ifndef ENIGMAENGINE_STACK_HPP
#define ENIGMAENGINE_STACK_HPP

#include "tangara.h"
#include <stack>
#include <vector>
#include <string>

namespace Tangara {

    class Stack {
    public:
        Stack() = default;

        ~Stack() = default;

        void Push(tgPtr ptr);
        tgPtr Top();
        tgPtr Pop();
    private:
        std::stack<tgPtr> _stack;
    };
}

#endif //ENIGMAENGINE_STACK_HPP
