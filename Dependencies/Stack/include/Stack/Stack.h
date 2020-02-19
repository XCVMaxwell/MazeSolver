#ifndef STACK_STACK_H
#define STACK_STACK_H


#include "Node.h"

namespace Stack
{
    template <typename T>
    class Stack
    {
    private:
        Node<T>* last;

    public:
        Stack();

        ~Stack();

        void push(T& data);

        bool pop();

        bool isEmpty() const;

        int size() const;

        Node<T>* top() const;
    };

    template<typename T>
    Stack<T>::Stack() : last(nullptr) {}

    template<typename T>
    Stack<T>::~Stack()
    {
        Node<T>* currNode = last;
        Node<T>* tempNode = nullptr;

        while (currNode != nullptr) {
            tempNode = currNode->prev;
            delete currNode;
            currNode = tempNode;
        }
    }

    template<typename T>
    void Stack<T>::push(T& data)
    {
        auto* node = new Node<T>(data);

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
            Node<T>* temp = last->prev;

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
        Node<T>* node = last;

        int count = 0;
        while (node != nullptr) {
            count++;

            node = node->prev;
        }

        return count;
    }

    template<typename T>
    Node<T>* Stack<T>::top() const
    {
        return last;
    }
}

#endif //STACK_STACK_H
