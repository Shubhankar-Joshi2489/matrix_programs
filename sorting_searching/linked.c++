#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // ---------- CREATION METHODS ----------
    void createManual() {
        head = new Node(10);
        head->next = new Node(20);
        head->next->next = new Node(30);
    }

    void createFromArray(int arr[], int n) {
        for (int i = 0; i < n; i++)
            insertAtEnd(arr[i]);
    }

    void createFromVector(vector<int> v) {
        for (int x : v)
            insertAtEnd(x);
    }

    // ---------- TRAVERSAL ----------
    void traverse() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // ---------- INSERTION ----------
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
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
    }

    void insertAtPosition(int val, int pos) {
        if (pos == 1) {
            insertAtBeginning(val);
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp; i++)
            temp = temp->next;

        if (!temp) return;

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // ---------- DELETION ----------
    void deleteBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
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
        while (temp->next->next)
            temp = temp->next;

        delete temp->next;
        temp->next = nullptr;
    }

    void deleteValue(int key) {
        if (!head) return;
        if (head->data == key) {
            deleteBeginning();
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != key)
            temp = temp->next;

        if (!temp->next) return;
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    // =====================================================
    // 🔄 REVERSAL METHODS
    // =====================================================

    // 1️⃣ ITERATIVE 3 POINTER (reference)
    void reverseThreePointer() {
        Node *prev = nullptr, *curr = head, *next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    // 2️⃣ HEAD RECURSION (backtracking)
    Node* reverseHeadRec(Node* node) {
        if (!node || !node->next)
            return node;

        Node* newHead = reverseHeadRec(node->next);

        node->next->next = node;
        node->next = nullptr;

        return newHead;
    }

    void reverseUsingHeadRecursion() {
        head = reverseHeadRec(head);
    }

    // 3️⃣ TAIL RECURSION (forward processing)
    Node* reverseTailRec(Node* curr, Node* prev) {
        if (!curr)
            return prev;

        Node* next = curr->next;
        curr->next = prev;

        return reverseTailRec(next, curr);
    }

    void reverseUsingTailRecursion() {
        head = reverseTailRec(head, nullptr);
    }
};

int main() {
    LinkedList list;

    list.createManual();
    cout << "Manual: ";
    list.traverse();

    list.insertAtBeginning(5);
    list.insertAtEnd(40);
    list.insertAtPosition(25, 4);
    cout << "After insertions: ";
    list.traverse();

    list.deleteBeginning();
    list.deleteEnd();
    list.deleteValue(20);
    cout << "After deletions: ";
    list.traverse();

    cout << "Reverse (Iterative 3 pointer): ";
    list.reverseThreePointer();
    list.traverse();

    cout << "Reverse (Head recursion): ";
    list.reverseUsingHeadRecursion();
    list.traverse();

    cout << "Reverse (Tail recursion): ";
    list.reverseUsingTailRecursion();
    list.traverse();

    int arr[] = {1,2,3,4};
    LinkedList list2;
    list2.createFromArray(arr,4);
    cout << "From array: ";
    list2.traverse();

    vector<int> v = {7,8,9};
    LinkedList list3;
    list3.createFromVector(v);
    cout << "From vector: ";
    list3.traverse();
}
