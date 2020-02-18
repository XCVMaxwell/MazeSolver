#ifndef LINKEDLIST_LLNODE_H
#define LINKEDLIST_LLNODE_H


namespace LinkedList {
    template<class T>
    class Node
    {
    public:
        T data;
        Node* next;

        explicit Node(T& data);
    };

    template<class T>
    Node<T>::Node(T& data)
    {
        this->data = data;
        this->next = nullptr;
    }
}


#endif //LINKEDLIST_LLNODE_H
