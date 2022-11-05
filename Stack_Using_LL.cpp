#include<bits/stdc++.h>
using namespace std;


// Template to create object of any datatype
template<class T>
class Stack
{
 public:
    struct Node
    {
         T data;
         Node *next;
       
    };
    
    Node *top = new Node;  
    // default constructor 
    Stack()
    {
        top=NULL;
    }


    // Checck if stack is empty
    bool isEmpty()
    {
       if(top== NULL)
       {
           return true;
       }  
       return false;
    }
    
    // Push an element inti stack
    void Push(T x)
    {
      Node *temp = new Node;
      temp->data=x;
      temp->next=top;
      top=temp;
    }

    // Pop an element and return its value
    T Pop()
    {
         if(isEmpty())
         {
             cout<<"Linked List is Empty\n";
             return NULL;
         }
        T x=top->data;
        top=top->next;
        return x;
    }

    // Display all the element of stack
    void Display()
    {
        Node *temp = new Node;
        temp =top;
        if(isEmpty())
        {
           cout<<"Stack is empty";
           return;
        }

        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

    // Return the top of stack
    T getTop()
    {
        if(isEmpty())
        {
            return NULL;
        }
        return top->data;
    }

};

