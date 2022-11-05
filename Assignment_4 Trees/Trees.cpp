#include "Stack_Using_LL.cpp"
#include<bits/stdc++.h>
using namespace std;


bool isOperator(char c)
{
   if(c == '+' || c=='-' || c=='*' || c=='/' || c=='^')
   {
    return true;
   }

return false;

}

int Prefix(char c)
{
    if(c == '^')
    {
        return 3;
    }
    else if( c == '*' || c == '/')
    {
        return 2;
    }
    else if( c == '+' || c=='-')
    {
        return 1;
    }

return -1;
}

class Node
{
  public:
  Node *lchild;
  char data;
  Node *rchild;

  Node(char x)
  {
     data=x;
     lchild=NULL;
     rchild=NULL;
  }

};

class Tree
{
public:
       Node *root;
       Tree()
       {
         root=NULL;
       }

       void BuildTree(string s)
       {
           Stack<Node*>N;
           for(int i=0; i<s.length(); i++)
           {
               if(!isOperator(s[i]))
               {
                  Node *temp= new Node(s[i]);
                  N.Push(temp);
               }
               else
               {
                  Node *root1= new Node(s[i]);
                  Node *temp1= N.getTop();
                  N.Pop();
                  Node *temp2=N.getTop();
                  N.Pop();
                  root1->rchild=temp1;
                  root1->lchild=temp2;
                  N.Push(root1);
               }
           }
          
          root=N.Pop();
       }
};

void Rinorder(Node *root)
{
    if(root != NULL)
    {
        Rinorder(root->lchild);
        cout<<root->data;
        Rinorder(root->rchild);
    }
        
}

void NonRinorder(Node *root)
{

  if(root == NULL)
  {
    return;
  }
  Stack<Node *>N;
  Node *temp=root;
  while(!N.isEmpty() ||  temp != NULL)
  {

       if(temp != NULL)
       {
           N.Push(temp);
           temp=temp->lchild; 
           
       }
       else
       {
          temp=N.Pop();
          cout<<temp->data;
          temp=temp->rchild;
       }
  }

}

void Rpreorder(Node *root)
{
    if(root != NULL)
    {
        cout<<root->data;
        Rpreorder(root->lchild);
        Rpreorder(root->rchild);
    }
}

void NonRpreorder(Node *root)
{
    if(root == NULL)
    {
        return;
    }
   Stack<Node*>TreeStack;
   Node *curr=root;
   Node *prew=NULL;
   while(curr != NULL  || !TreeStack.isEmpty())
   { 
       if(curr != NULL)
       {
          cout<<curr->data;
          TreeStack.Push(curr);
          curr=curr->lchild;
       }
       else
       {
          prew=TreeStack.Pop();
          curr=prew->rchild; 
       }

   }
}


void Rpostorder(Node *root)
{
    if(root != NULL)
    {
           
        Rpostorder(root->lchild);
        Rpostorder(root->rchild);
        cout<<root->data;
    }
}

void NonRpostorder(Node *root)
{
   Stack<Node*>TreeStack;
   Stack<Node*>RightChild;
   Node *curr=root;

   while(curr != NULL || !TreeStack.isEmpty())
   {
      if(curr != NULL)
      {
        TreeStack.Push(curr);

        if(curr->rchild != NULL)
        {
           RightChild.Push(curr->rchild); 
        }

        curr=curr->lchild;
      }
      else
      {
         curr=TreeStack.getTop();

         if(!RightChild.isEmpty() && curr->rchild == RightChild.getTop())
         {
             curr=RightChild.Pop();
         }
         else
         {
            cout<<curr->data;
            TreeStack.Pop();
            curr=NULL;
         }
         
         


      }   

   }
  




}

int main()
{
    Tree t1;
    t1.BuildTree("ab+cd-*");
    // Rinorder(t1.root);
    // cout<<"\n";
    // Rpreorder(t1.root);
    // cout<<"\n";
    // Rpostorder(t1.root);
    //  NonRinorder(t1.root);
    // NonRpreorder(t1.root);
    NonRpostorder(t1.root);

return 0;
}
//visit https://www.enjoyalgorithms.com/blog/iterative-binary-tree-traversals-using-stack for better explanation 
// of non recursive traversal