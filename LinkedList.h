#pragma once
#include <iostream>
#include "Node.h"

// Solution file. Lab 3's LinkedList plus addBack, getFront, isEmpty, size.
// tail_ is back so addBack is O(1). size_ is new so size() is O(1).

template <typename T>
class LinkedList : public List<T> {
public:
    LinkedList() : head_(nullptr), size_(0) {}

    void addFront(T* value) override {
        Node<T>* fresh = new Node<T>(value);
        fresh->next = head_;
        head_ = fresh;
        ++size_;
    }

    void addBack(T* value) override {
        Node<T>* fresh = new Node<T>(value);

        if (head_ == nullptr) {
            head_ = fresh;          // first node is both head and tail
            ++size_;
            return;
        }
        Node<T>* current = head_;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = fresh;
        ++size_;
    }

    void deleteFront() override {
        if (head_ == nullptr) {
            std::cout << "LinkedList is empty." << std::endl;
            return;
        }
        Node<T>* doomed = head_;
        head_ = head_->next;
        if (head_ == nullptr) {
            tail_ = nullptr;        // list is empty again
        }
        delete doomed->data;
        delete doomed;
        --size_;
    }

    T* getFront() const override {
        if (head_ == nullptr) {
            return nullptr;
        }
        return head_->data;
    }

    bool isEmpty() const override {
        return head_ == nullptr;
    }

    int size() const override {
        return size_;
    }

    bool search(T* value) const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            if (*current->data == *value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void print() const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            std::cout << *current->data << ", ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void addAnywhere(int position, T* value) override {
        if (position < 0 || position > size_) {
            std::cout << "position invalid funny guy" << std::endl;
            return;
        }
        if (position == 0) {
            addFront(value);
            return;
        }
        Node<T>* fresh = new Node<T>(value);
        Node<T>* current = head_;

        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        fresh->next = current->next;
        current->next = fresh;
        size_++;
    }

    void deleteAnywhere(int position) override {
        if (position < 0 || position >= size_) {
            std::cout << "position invalid funny guy" << std::endl;
            return;
        }
        if (position == 0) {
            deleteFront();
            return;
        }

        Node<T>* current = head_;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        Node<T>* doomed = current->next;
        current->next = doomed->next;
        delete doomed-> data;
        delete doomed;
        size_--;
    }

    void reverse() override {
        Node<T>* previous = nullptr;
        Node<T>* current = head_;
        Node<T>* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head_ = previous;
    }

    void concat(List<T>* other) override {
        LinkedList<T>* otherList = dynamic_cast<LinkedList<T>*>(other);
        if (otherList == nullptr) {
            return;
        }
        if (head_ == nullptr) {
            head_ = otherList->head_;
            size_ = otherList->size_;
            otherList->size_ = 0;
            otherList->head_ = nullptr;
            return;
        }

        Node<T>* current = head_;
        while (current -> next != nullptr) {
            current = current->next;
        }

        current->next = otherList->head_;
        size_ += otherList->size_;

        otherList->head_ = nullptr;
        otherList->size_ = 0;
    }

    ~LinkedList() override {
        while (head_ != nullptr) {
            Node<T>* doomed = head_;
            head_ = head_->next;
            delete doomed->data;
            delete doomed;
        }
    }

private:
    Node<T>* head_;
    Node<T>* tail_;
    int size_;
};
