#include<iostream>
using namespace std;
class CircularQueue {
    int head, tail, size;
    int *arr;

public:
    CircularQueue(int k) {
        size = k;
        arr = new int[k];
        head = tail = -1;
    }

    bool enqueue(int value) {
        if ((tail + 1) % size == head) return false; // Full
        if (head == -1) head = 0;
        tail = (tail + 1) % size;
        arr[tail] = value;
        return true;
    }

    int dequeue() {
        if (head == -1) return -1; // Empty
        int res = arr[head];
        if (head == tail) head = tail = -1;
        else head = (head + 1) % size;
        return res;
    }
    void display() {
    if (head == -1) {
        cout << "Queue is Empty" << endl;
        return;
    }

    cout << "Queue elements: ";
    int i = head;
    
    while (true) {
        cout << arr[i] << " ";
        
        // Stop once we have printed the tail element
        if (i == tail) break; 
        
        // Move to the next index, wrapping around to 0 if necessary
        i = (i + 1) % size; 
    }
    cout << endl;
}
};
int main()
{
    CircularQueue ob(5);
    ob.enqueue(10);
    ob.enqueue(20);
    ob.enqueue(30);
    ob.enqueue(40);
    ob.enqueue(50);
    ob.enqueue(60);
    ob.dequeue();
    ob.display();
    return 0;
}

