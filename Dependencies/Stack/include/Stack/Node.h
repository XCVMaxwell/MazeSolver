#ifndef STACK_NODE_H
#define STACK_NODE_H

namespace Stack
{
    template <typename T>
    class Node
    {
    public:
        T data;
        Node* prev;

        explicit Node(T& data)
        {
            this->data = data;
            this->prev = nullptr;
        }

        ~Node() = default;
    };
}


#endif //STACK_NODE_H
