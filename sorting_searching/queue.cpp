#include<iostream>
using namespace std ;
/*class ArrayQueue {
    int front, rear,m,size;
        
 int *arr;

public:
    ArrayQueue() { front = 0; rear = -1; size = 0; 
          cout<<"Enter the max no of elements in your queue";
    cin>>m;
    arr =new int[m];
    }
    

    void enqueue(int x) {
        if (size ==m) return;
        arr[++rear] = x;
        size++;
    }

    int dequeue() {

        if (size == 0) return -1;
        size--;
        return arr[front++];
    }
    void display ()
    {   cout<<" Queue ";
        if(front<0) front=0;
        for(int i=front;i<=rear;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"size "<<size;
    }
};*/
struct Node {
    int data;
    Node* next;
};
class LinkedStack {
    Node* top = nullptr;

public:
    void push(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    int pop() {
        if (!top) return -1;
        int val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }
    void display()
        {
         Node* temp = top;
         if (top == nullptr) {
            cout << "Stack is empty." << endl;
            return;
        }
        while(temp!=nullptr)
        { 
            cout<<temp->data<<" <- ";
            temp=temp->next;


        }
        }
};
  int main () 
{
    LinkedStack  ob;
    int p,x;
    cout<<"enter how times you want to push";
    cin>>p;
    cout<<"enter elements ";
    for(int i=0;i<p;i++)
    { 
        cin>>x;
        ob.push(x);
    }
    cout<<"poping top elemnt";
    ob.pop();
    ob.display();
     return 0;
}

