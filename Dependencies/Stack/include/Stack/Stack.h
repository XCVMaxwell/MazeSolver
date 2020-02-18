#ifndef STACK_STACK_H
#define STACK_STACK_H


#include "Node.h"

namespace Stack
{
    template <typename T>
    class Stack
    {
    private:
        StackNode<T>* last;

    public:
        Stack();

        virtual ~Stack();

        void push(T& data);

        bool pop();

        bool isEmpty() const;

        int size() const;

        StackNode<T>* top() const;
    };

    template<typename T>
    Stack<T>::Stack() : last(nullptr) {}

    template<typename T>
    Stack<T>::~Stack() = default;

    template<typename T>
    void Stack<T>::push(T& data)
    {
        auto* node = new StackNode<T>(data);

        if (last == nullptr) {
            last = node;
        }
        else {
            node->prev = last;
            last = node;
        }
    }

    template<typename T>
    bool Stack<T>::pop()
    {
        if (last == nullptr) {
            return false;
        }
        else {
            StackNode<T>* temp = last->prev;

            delete last;

            last = temp;

            return true;
        }
    }

    template<typename T>
    bool Stack<T>::isEmpty() const
    {
        return last == nullptr;
    }

    template<typename T>
    int Stack<T>::size() const
    {
        StackNode<T>* node = last;

        int count = 0;
        while (node != nullptr) {
            count++;

            node = node->prev;
        }

        return count;
    }

    template<typename T>
    StackNode<T>* Stack<T>::top() const
    {
        return last;
    }
}

#endif //STACK_STACK_H
