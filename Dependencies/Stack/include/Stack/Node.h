#ifndef STACK_STACKNODE_H
#define STACK_STACKNODE_H

namespace Stack
{
    template <typename T>
    class StackNode
    {
    public:
        T data;
        StackNode* prev;

        explicit StackNode(T& data)
        {
            this->data = data;
            this->prev = nullptr;
        }

        ~StackNode() = default;
    };
}


#endif //STACK_STACKNODE_H
