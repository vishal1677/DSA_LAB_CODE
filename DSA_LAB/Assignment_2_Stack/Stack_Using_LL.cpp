#include<bits/stdc++.h>
using namespace std;


template<class T>
class Stack
{
 private:
         struct Node
         {
            T data;
            Node *next;   
         };
         Node *head;         
 public:
         Stack()
         {
            head=NULL;
         }

         bool isEmpty()
         {
             if(head == NULL) return true;

             return false;
         }

        

         void Push(int x)
         {
            Node *temp = new Node;
            temp->data=x;

            if(head == NULL)
            {
                temp->next=NULL;
            }
            else
            {
                temp->next=head;
            }
            head=temp;
         }

         T Pop()
         {
            if(head == NULL)
            {
                return NULL;
            }
            T x = head->data;
            Node *temp = head;
            head=head->next;
            delete(temp);
            return x;
         }

         T getTop()
         {
            return head->data;
         }

         void Display()
         {
            if(head == NULL){
                cout<<"Linked list is empty";
            }
            else
            {
                Node *temp= head;
                while(temp != NULL)
                {
                    cout<<temp->data<<" ";
                    temp=temp->next;
                }
            }
         }

};
    


