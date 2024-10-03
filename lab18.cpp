// COMSC-210 | Lab 19 | Niko Dittmar
#include <fstream>
#include <random>
#include <iostream>

using namespace std;

struct Node {
    double rating;
    string review;
    Node * next;
};

Node* addFront(Node*, Node*);
Node* addBack(Node*, Node*);
void printList(Node*);

class Movie {
private:
    string title;
    Node* reviews;
public:
    Movie(string t) {
        title = t;
        reviews = nullptr;
    }

    void addReview(Node* review) {
        reviews = addFront(reviews, review);
    }

    void printMovie() {
        cout << title << endl;
        printList(reviews);
    }
};

int main() {

    ifstream inputFile("lab18.txt");

    // Make sure it was opened
    if (!inputFile.is_open()) {
        cout << "We ran into an error opening your file! Please try again.";
        return 1;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> randomRating(1.0,5.0);

    vector<Movie> movies;

    string line;

    while(getline(inputFile, line)) {
        Movie movie(line);

        
        while(getline(inputFile, line) && line != "") {
            Node* current = new Node;
            current->review = line;
            double rating = round(randomRating(gen) * 10) / 10.0;
            current->rating = rating;
            movie.addReview(current);
        }

        movies.push_back(movie);
    }

    cout << "Movies:" << endl;

    for (int i = 0; i < movies.size(); i++) {
        movies[i].printMovie();
    }

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

// printList() prints a linked list.
// arguments: head - a pointer to the head of the linked list
// returns: none.
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

    totalRating = totalRating / (count - 1);

    cout << "   > Average: " << totalRating << " " << endl;
}



