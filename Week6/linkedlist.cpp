#include "linkedlist.hpp"

// Constructor
LinkedList::LinkedList() {
    head_ = nullptr;
    size_ = 0;
}

// Insert a node at the end of the list
void LinkedList::InsertNode(const int value) {
    Node* new_node = new Node(value);

    // Empty list
    if (head_ == nullptr) {
        head_ = new_node;
    }
    else {
        Node* current = head_;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = new_node;
    }

    size_++;
}

// Insert a node at the beginning of the list
void LinkedList::InsertNodeFront(const int value) {
    Node* new_node = new Node(value);

    new_node->next = head_;
    head_ = new_node;

    size_++;
}

// Search for a value
bool LinkedList::Contains(const int value) const {
    Node* current = head_;

    while (current != nullptr) {
        if (current->value == value) {
            return true;
        }

        current = current->next;
    }

    return false;
}

// Remove
bool LinkedList::Remove(const int position) {
    if (position < 1 || position > size_) {
        return false;
    }

    // Remove the first node
    if (position == 1) {
        Node* temp = head_;
        head_ = head_->next;
        delete temp;
        size_--;
        return true;
    }

    Node* current = head_;
    for (int i = 1; i < position - 1; i++) {
        current = current->next;
    }

    Node* temp = current->next;
    current->next = temp->next;

    delete temp;
    size_--;

    return true;
}

// PrintValues
void LinkedList::PrintValues() const {
    Node* current = head_;

    while (current != nullptr) {
        std::cout << current->value << " -> ";
        current = current->next;
    }

    std::cout << "nullptr" << std::endl;
}

// PrintAddresses
void LinkedList::PrintAddresses() const {
    Node* current = head_;
    int position = 1;

    while (current != nullptr) {
        std::cout << position << " " << current << std::endl;
        current = current->next;
        position++;
    }
}

// GetValueAtPosition
int LinkedList::GetValueAtPosition(const int position) const {
    if (position < 1 || position > size_) {
    throw std::out_of_range("Invalid position");
  }

  Node* current = head_;

  for (int i = 1; i < position; i++) {
    current = current->next;
  }

  return current->value;
}

// ReverseList
LinkedList* LinkedList::ReverseList() {
    Node* previous = nullptr;
  Node* current = head_;

  while (current != nullptr) {
    Node* next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }

  LinkedList* reversed = new LinkedList();

  reversed->head_ = previous;
  reversed->size_ = size_;

  head_ = nullptr;
  size_ = 0;

  return reversed;
}

// InsertNodeAt
void LinkedList::InsertNodeAt(const int value, const int position) {
    if (position < 1 || position > size_ + 1) {
    throw std::out_of_range("Invalid position");
  }
  
  if (position == 1) {
    InsertNodeFront(value);
    return;
  }

  if (position == size_ + 1) {
    InsertNode(value);
    return;
  }

  Node* new_node = new Node(value);

  Node* current = head_;

  for (int i = 1; i < position - 1; i++) {
    current = current->next;
  }

  new_node->next = current->next;
  current->next = new_node;

  size_++;
}

// GetSize
int LinkedList::GetSize() const {
    return size_;
}

// MergeIntertwine
LinkedList* LinkedList::MergeIntertwine(const LinkedList& second_list) const {
    LinkedList* merged = new LinkedList();
    
    Node* first = head_;
    Node* second = second_list.head_;
    
    while (first != nullptr || second != nullptr) {
        if (first != nullptr) {
            merged->InsertNode(first->value);
            first = first->next;
        }
        
        if (second != nullptr) {
            merged->InsertNode(second->value);
            second = second->next;
        }
    }
    return merged;
}


// Destructor
LinkedList::~LinkedList() {
    Node* current = head_;
    
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    
    head_ = nullptr;
    size_ = 0;
}