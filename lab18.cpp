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

    cout << "Which linked list method should we use?" << endl;
    cout << "   [1] New nodes are added at the head of the linked list" << endl;
    cout << "   [2] New nodes are added at the tail of the linked list" << endl;

    int mode;
    cout << "   Choice: ";
    cin >> mode;

    if (mode != 1 || mode != 2) {
        cout << "ERROR, " << mode << " is not a valid method!" << endl;
        return 1;
    }

    Node* head = nullptr;

    bool addingReviews = true;

    while(addingReviews) {
        Node* current = new Node;
        cout << "Enter review rating 0-5: ";
        cin >> current->rating;

        if (current->rating < 0 || current->rating > 5) {
            cout << "ERROR, " << current->rating << " is not within the range [0,5]!" << endl;
            return 1;
        }

        cout << "Enter review comments: " ;
        getline(cin, current->review);

        string addMore;
        cout << "Enter another review? Y/N: ";
        cin >> addMore;
        
        if (addMore == "y" || addMore == "Y") {
            addingReviews = true;
        } else if (addMore == "n" || addMore == "N") {
            addingReviews = false;
        } else {
            cout << "ERROR, " << addMore << " is not Y or N!" << endl;
            return 1;
        }

        if (head) {
            if (mode == 1) {
                head = addFront(head, current);
            } else {
                head = addBack(head, current);
            }
        } else {
            head = current;
        }
    }

    cout << "Outputting all reviews:" << endl;

    printList(head);

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

void printList(Node* head) {
    Node* current = head;
    int count = 1;
    double totalRating = 0;

    while (current) {
        cout << "   > Review #" << count << ": " << current->rating << ": " << current->review << endl;
        totalRating += current->rating;
        current = current -> next;
        count++;
    }

    totalRating = totalRating / count;

    cout << "   > Average: " << totalRating << endl;
}



