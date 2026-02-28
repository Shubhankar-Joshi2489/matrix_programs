#include<iostream>
using namespace std;
/*
class stack
{
    int top;
    int *arr;
    int m;
    public :
    stack()
   {top=-1;
   
    
    cout<<"Enter the max no of elements in your stack";
    cin>>m;
    arr =new int[m];
    }
    ~stack() {
        delete[] arr;
    }
    bool push(int x)
    {   if (top >= m-1) {
            cout << "Stack Overflow!" << endl;
            return false;
        }
         top=top+1;
        arr[top]=x;
        return true ;
    }
    int pop(){
        if(top<0)
        {   cout<<"Stack underflow ";
            return -1;
        }
        return arr[top--];
    }
    void display()
    {    cout<<"stack contents ";
        for(int i=0;i<=top;i++)
        {
            cout<<arr[i]<<" ";
        }
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
        while(temp!=nullptr)
        { 
            cout<<temp->data<<" ";
            temp=temp->next;


        }
        }
    
};
int main () 
{
    LinkedStack ob;
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