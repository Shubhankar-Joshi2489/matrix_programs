#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    // Fixed constructor to initialize prev to nullptr
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class LinkedList {
    
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // ---------- 1. INSERTION METHODS ----------
    
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head != nullptr) {
            newNode->next = head;
            head->prev = newNode; // Link old head back to new node
        }
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        
        temp->next = newNode;
        newNode->prev = temp; // Link new node back to previous tail
    }

    void insertAtPosition(int val, int pos) {
        if (pos <= 1 || !head) {
            insertAtBeginning(val);
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp->next; i++)
            temp = temp->next;

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }

    // ---------- 2. DELETION METHODS ----------

    void deleteBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr; // New head has no previous
        delete temp;
    }

    void deleteEnd() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;

        temp->prev->next = nullptr; // Disconnect from second-to-last
        delete temp;
    }
    void deleteAtposition(int val, int pos) {
    if (pos <= 1 || !head) {
        deleteBeginning();
        
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next; i++) {
        temp = temp->next;
    }

    // 1. Define P FIRST
    Node *p = temp->next;    
    
    // 2. Check if P exists SECOND
    if (p == nullptr) return; 

    // 3. Safety check for the NEXT node (The "Tail" Check)
    if (p->next != nullptr) {
        p->next->prev = p->prev;
    }

    // 4. Safety check for the PREVIOUS node (Always exists because of pos > 1)
    if (p->prev != nullptr) {
        p->prev->next = p->next;
    }

    delete p; // Don't forget the semicolon!
}
    // ---------- 3. DISPLAY ----------

    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        Node* last = nullptr;
        
        cout << "Forward:  ";
        while (temp) {
            cout << temp->data << " <-> ";
            last = temp; // Save last for backward check
            temp = temp->next;
        }
        cout << "NULL" << endl;

        // Extra check: Verify prev links by printing backward
        cout << "Backward: ";
        while (last) {
            cout << last->data << " <-> ";
            last = last->prev;
        }
        cout << "NULL" << endl << endl;
    }

    // ---------- 4. REVERSE ----------
    
    void reverse() {
        if (!head || !head->next) return;
        
        Node* curr = head;
        Node* temp = nullptr;

        // In a DLL, we just swap next and prev pointers for every node
        while (curr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            
            // Move to the "next" node (which is now stored in curr->prev)
            curr = curr->prev;
        }
        
        // After the loop, temp points to the old second-to-last node
        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    // Helper for setup
    void createFromVector(vector<int> v) {
        for (int x : v) insertAtEnd(x);
    }
};

int main() {
    LinkedList list;
    int n,x,p;
     cout<<"Enter the no of elements";
     cin>>n;
     vector<int> v(n);
     cout<<"Enter the elements";
     for(int i=0;i<n;i++)
     {
        cin>>v[i];
     }

    cout << "--- Doubly Linked List Operations ---\n";
    list.createFromVector(v);
    list.display();
     cout<<"Enter element to insert and its postion";
     cin>>x>>p;
    cout << "Inserting "<<x<<" at position \n"<<p;
    list.insertAtPosition(x,p);
    
    list.display();
    cout<<"Enter element to delete and its postion";
     cin>>x>>p;
    cout << "Deleting"<<x<<" from position \n"<<p;
     list.deleteAtposition(x,p);
    list.display();

    cout << "Reversing the list:\n";
    list.reverse();
    list.display();

    return 0;
}

/*
*/