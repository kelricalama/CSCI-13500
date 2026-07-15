#include "Snake.h"
#include <iostream>

Snake::Snake() {
    head_ = nullptr;
    tail_ = nullptr;
    length_ = 0;
    id_ = 0;

    for (int i = 0; i < STARTING_LENGTH; i++) {
        Node* newNode = new Node;

        newNode->body_part_ = id_;
        id_++;

        newNode->next_ = nullptr;

        if (head_ == nullptr) {
            head_ = newNode;
            tail_ = newNode;
        }
        else {
            tail_->next_ = newNode;
            tail_ = newNode;
        }

        length_++;
    }
}

Snake::~Snake() {
    while (head_ != nullptr) {
        Node* temp = head_;
        head_ = head_->next_;
        delete temp;
    }

    tail_ = nullptr;
    length_ = 0;
}

int Snake::Kill(int count) {
    int killed = 0;

    while (head_ != nullptr && killed < count) {
        Node* temp = head_;

        head_ = head_->next_;

        delete temp;

        length_--;
        killed++;
    }
    
    if (head_ == nullptr) {
        tail_ = nullptr;
    }

    return killed;
}

void Snake::Regenerate(int count) {
    for (int i = 0; i < count; i++) {
        Node* newNode = new Node;

        newNode->body_part_ = id_;
        id_++;

        newNode->next_ = nullptr;

        if (head_ == nullptr) {
            head_ = newNode;
            tail_ = newNode;
        }
        else {
            tail_->next_ = newNode;
            tail_ = newNode;
        }

        length_++;
    }
}

void Snake::PrintSnake() const {
    std::cout << "Snake: ";

    const Node* current = head_;

    if (current == nullptr) {
        std::cout << "(dead)" << std::endl;
        return;
    }

    while (current != nullptr) {
        std::cout << "[" << current->body_part_ << "]";

        if (current->next_ != nullptr) {
            std::cout << " -> ";
        }

        current = current->next_;
    }

    std::cout << std::endl;
    
}

int Snake::GetLength() const {
    return length_;
}
