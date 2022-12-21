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
            if(head  == NULL) return true;

            return false;

         }

         void Push(T x)
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
            if(head == NULL) return NULL;

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
    





class Node
{
  public:

  char data;
  Node *left;
  Node *right;

  Node(char x)
  {
    data=x;
    left=NULL;
    right=NULL;
  }
};


class ExpressionTree
{
 public:
       bool isOperator(char c)
       {
         if(c == '+' || c=='-' || c=='*' || c=='/' || c=='^')
         {
          return true;
         }

         return false;

       }

       Node* Postfixtree(string s)
       {
          Stack<Node*>st;

          for(int i=0; i<s.length(); i++)
          {
             if(!isOperator(s[i]))
             {
               Node *temp = new Node(s[i]);
               st.Push(temp);
             }
             else
             {
              Node *head1=new Node(s[i]);
              Node *temp1=st.Pop();
              Node *temp2=st.Pop();
              head1->left=temp2;
              head1->right=temp1;
              st.Push(head1);              
             }

          }

        return st.getTop();

       }
       Node* Prefixtree(string s)
       {
          Stack<Node*>st;

          for(int i=s.length()-1; i>=0; i--)
          {
            if(!isOperator(s[i]))
            {
               Node *temp = new Node(s[i]);
               st.Push(temp);
            }
            else
            {
              Node *head1= new Node(s[i]);
              Node *temp1=st.Pop();
              Node *temp2=st.Pop();
              head1->left=temp1;
              head1->right=temp2;
              st.Push(head1);

            }
          }

         return st.getTop();
       }

       void Inorder(Node *root)
       {
          if(root != NULL)
          {
             Inorder(root->left);
             cout<<root->data;
             Inorder(root->right);
          }
       }


       void Iterinorder(Node *head)
       {

          Stack<Node*>st;

          Node *curr =head;

          while(curr != NULL || !st.isEmpty())
          {
             if(curr != NULL)
             {
              st.Push(curr);
              curr=curr->left;
             }
             else
             {
                curr=st.Pop();
                cout<<curr->data;
                curr=curr->right;         
             }


          }

        





       }

       void Postorder(Node *root)
       {
          if(root != NULL)
          {
          Postorder(root->left);
          Postorder(root->right);
          cout<<root->data;
          }
       }

       void Iterpostorder(Node *head)
       {
          Stack<Node*>stMain;
          Stack<Node*>stRight;
          Node *curr=head;

          while(!stMain.isEmpty() || curr != NULL)
          {
         
                if(curr != NULL)
                {
                  if(curr->right != NULL)
                  {
                    stRight.Push(curr->right);
                  }
                  stMain.Push(curr);
                  curr=curr->left;
                }
                else
                {  
                  curr=stMain.getTop();
                  if(!stRight.isEmpty() && curr->right == stRight.getTop())
                  {
                    curr=stRight.Pop();
                  }
                  else
                  {
                    cout<<curr->data;
                    stMain.Pop();
                    curr=NULL;

                  }
                }


          }

       }

       void Preorder(Node *root)
       {
         if(root != NULL)
         {
         cout<<root->data;
         Preorder(root->left);
         Preorder(root->right);
         }
          
       }

       void Iterpreorder(Node *root)
       {

          Stack<Node*>st;
          Node *curr=root;


          while(curr!= NULL || !st.isEmpty())
          {
              if(curr != NULL)
              {
                cout<<curr->data;
                if(curr->right != NULL)
                {
                  st.Push(curr->right);
                }
                curr=curr->left;

              }
              else
              {
                 curr=st.Pop();
              }
            

          }

      

       }

};


int main()
{

ExpressionTree e1;
Node *head1=e1.Prefixtree("+ab");
// e1.Inorder(head1);
// cout<<"\n";
// e1.Iterinorder(head1);
// e1.Preorder(head1);
// e1.Iterpreorder(head1);

// cout<<"\n";
// e1.Postorder(head1);

e1.Iterpostorder(head1);








    return 0;
}