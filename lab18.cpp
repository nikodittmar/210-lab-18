// COMSC-210 | Lab 18 | Niko Dittmar
#include <iostream>

using namespace std;

struct Node {
    double rating;
    string review;
    Node * next;
};

Node* addFront(Node*, Node*);
Node* addBack(Node*, Node*);

int main() {

    cout << "Hello 210";

    return 0;
}

// addFront() adds a node to the front of a linked list.
// arguments: head - a pointer to the head of the linked list, toAdd - a pointer to the node to add.
// returns: a pointer to the head of the linked list.
Node* addFront(Node* head, Node* toAdd) {
    toAdd->next = head;

    return toAdd;
}

// addBack() adds a node to the back of a linked list.
// arguments: head - a pointer to the head of the linked list, toAdd - a pointer to the node to add.
// returns: a pointer to the head of the linked list.
Node* addBack(Node* head, Node* toAdd) {
    Node* current = head;

    while (current -> next) {
        current = current -> next;
    }

    current->next = toAdd;

    return head;
}



