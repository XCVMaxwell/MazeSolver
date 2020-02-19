#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H


#include <iosfwd>
#include "Node.h"
#include "iostream"

namespace LinkedList {
    template<typename T>
    class LinkedList
    {
    private:
        Node<T>* first;

    public:
        LinkedList();

        ~LinkedList();

        void add(T data);

        void deleteByValue(T data);

        void deleteByIndex(int index);

        void insertAfterValue(T data, T oldData);

        void insertBeforeIndex(int index, T data);

        int size() const;

        T get(int index) const;

        void set(int index, T newData);

        bool contains(T& data) const;

        template<T> friend std::ostream& operator<<(std::ostream& output, const LinkedList<T>& list);
    };

    template<typename T>
    LinkedList<T>::LinkedList() : first(nullptr) {}

    template<typename T>
    LinkedList<T>::~LinkedList()
    {
        Node<T>* currNode = first;
        Node<T>* tempNode = nullptr;

        while (currNode != nullptr) {
            tempNode = currNode->next;
            delete currNode;
            currNode = tempNode;
        }
    }

    template<typename T>
    void LinkedList<T>::add(T data)
    {
        auto* node = new Node<T>(data);

        if (first == nullptr) {
            first = node;
        }
        else {
            Node<T>* currNode = first;
            Node<T>* prevNode = nullptr;

            while (currNode != nullptr) {
                prevNode = currNode;
                currNode = currNode->next;
            }

            if (prevNode != nullptr)
                prevNode->next = node;
        }
    }

    template<typename T>
    void LinkedList<T>::deleteByValue(T data)
    {
        Node<T>* node = first;
        Node<T>* prev = nullptr;

        while (node != nullptr) {
            if (node->data == data)
                break;

            prev = node;
            node = node->next;
        }

        if (node != nullptr) {
            if (node == first)
                first = node->next;
            else
                prev->next = node->next;

            delete node;
        }
    }

    template<typename T>
    void LinkedList<T>::deleteByIndex(int indexToDelete)
    {

        Node<T>* node = first;
        Node<T>* prev = nullptr;

        int index = 0;
        while (node != nullptr) {
            if (index == indexToDelete) {
                break;
            }

            prev = node;
            node = node->next;
            index++;
        }

        if (index >= 0) {
            if (node == first)
                first = node->next;
            else
                prev->next = node->next;

            delete node;
        }
    }

    template<typename T>
    void LinkedList<T>::insertAfterValue(T value, T newData)
    {
        auto* node = new Node<T>(newData);

        Node<T>* prev = first;

        while (prev != nullptr) {
            if (prev->data == value)
                break;

            prev = prev->next;
        }

        if (first == nullptr) {
            first = node;
        }
        else {
            if (prev != nullptr) {
                node->next = prev->next;
                prev->next = node;
            }
            else {
                add(newData);
            }
        }
    }

    template<typename T>
    void LinkedList<T>::insertBeforeIndex(int nodeIndex, T data)
    {
        auto* newNode = new Node<T>(data);

        Node<T>* node = first;
        Node<T>* prev = nullptr;

        int index = 0;
        while (node != nullptr) {
            if (index == nodeIndex) {
                break;
            }

            prev = node;
            node = node->next;
            index++;
        }

        if (first == nullptr) {
            first = newNode;
        }
        else {
            if (node != nullptr) {
                prev->next = newNode;
                newNode->next = node;
            }
            else {
                add(data);
            }
        }
    }

    template<typename T>
    int LinkedList<T>::size() const
    {
        Node<T>* node = first;

        int count = 0;
        while (node != nullptr) {
            count++;
            node = node->next;
        }

        return count;
    }

    template<typename T>
    T LinkedList<T>::get(int index) const
    {
        Node<T>* node = first;

        int i = 0;
        while (node != nullptr) {
            if (i == index) {
                return node;
            }

            node = node->next;
            i++;
        }
    }

    template<typename T>
    void LinkedList<T>::set(int index, T newData)
    {
        Node<T>* node = first;

        int i = 0;
        while (node != nullptr) {
            if (i == index) {
                node->data = newData;
                return;
            }

            node = node->next;
            i++;
        }
    }

    template<typename T>
    bool LinkedList<T>::contains(T& data) const
    {
        Node<T>* node = first;

        while (node != nullptr) {
            if (node->data == data) {
                return true;
            }

            node = node->next;
        }

        return false;
    }

    template<typename T>
    std::ostream& operator<<(std::ostream& output, const LinkedList<T>& list)
    {
        Node<T>* node = list.first;

        while (node != nullptr) {
            output << node->data << endl;
            node = node->next;
        }

        return output << endl;
    }
}

#endif //LINKEDLIST_LINKEDLIST_H
