/* This program shows how a singly linked list is coded */

#include <iostream>

class Node {
    /* The main element in a linked list */

    public:
        int d;
        Node* next;
        
        // Constructor
        Node(int d, Node* next = nullptr) : d(d), next(next) {}
};

class LinkedList {
    /* The full structure */
    Node* head;
    Node* cursor;
    
    public:

    // Constructor
    LinkedList() : head(nullptr), cursor(nullptr) {}
    ~LinkedList() {
        for (cursor = head; cursor != 0;) {
            cursor = head->next;
            delete head;
            head = cursor;
        }
        std::cout << "Destroyed Linked-List object.";
    }

    // Methods
    
    void prepend(int n) {
        /* Add an element to the front of the list */

        if (head == nullptr) {
            cursor = head = new Node(n, head);
        } else {
            head = new Node (n, head);
        }
    };

    int get_element() { return cursor->d; }
    void advance() { cursor = cursor->next; }
    
    void print() {
        /* Prints the linked list an its entirety to the console */

        Node* h = head;
        while (h != nullptr) {
            std::cout << h->d << ", ";
            h = h->next;
        }
        std::cout << "###" << std::endl;
    }

};

int main() {
    LinkedList* list = new LinkedList();
    list->print();
    
    for (int i = 0; i < 25; i++) {
        list->prepend(i);
    }

    list->print();

    delete list;
}
