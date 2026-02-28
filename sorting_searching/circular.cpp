#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularList {
public:
    Node* head; // In this implementation, head points to the LAST node

    CircularList() : head(nullptr) {}

    // ---------- INSERTION ----------
    
    // Attaching to the "left" of head (which makes it the new last element)
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            newNode->next = newNode;
            head = newNode;
            return;
        }
        // newNode points to the current first element
        newNode->next = head->next;
        // Current last element points to the new node
        head->next = newNode;
        // Move the head pointer to the new node so it stays at the "end"
        head = newNode;
    }

    // ---------- DELETION ----------
    
    void deleteValue(int key) {
        if (!head) return;

        Node *curr = head->next, *prev = head;
        bool found = false;

        // Search for the node
        do {
            if (curr->data == key) {
                found = true;
                break;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head->next);

        if (found) {
            if (curr == head && curr->next == head) {
                // Only one node in list
                head = nullptr;
            } else {
                prev->next = curr->next;
                if (curr == head) head = prev; // Update head if we deleted the last node
            }
            delete curr;
        }
    }

    // ---------- DISPLAY ----------
    
    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head->next; // Start from the first node
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head->next);
        cout << "(back to start: " << head->next->data << ")" << endl;
    }
};

int main() {
    CircularList cll;

    cout << "Inserting 10, 20, 30 (Head always moves to the newest node):" << endl;
    cll.insert(10);
    cll.insert(20);
    cll.insert(30);
    cll.display();

    cout << "\nDeleting 20:" << endl;
    cll.deleteValue(20);
    cll.display();

    cout << "\nDeleting 30 (the current head/last node):" << endl;
    cll.deleteValue(30);
    cll.display();

    return 0;
}