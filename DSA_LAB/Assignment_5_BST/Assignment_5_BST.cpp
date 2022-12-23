#include<bits/stdc++.h>
using namespace std;
template<class T>
class Queue
{
 public:

  struct Node
  {
    T data;
    Node *next;
  };

  Node *front;
  Node *rear;

  Queue()
  {
    front=NULL;
    rear=NULL;
  }

  void Push(T x)
  {
    
    Node *temp = new Node;
    temp->data=x;
    temp->next=NULL;


    if(rear == NULL)
    {
        rear=temp;
        front=temp;
        return;
    }

    rear->next=temp;
    rear=temp;

  }

  bool isEmpty()
  {
    if(rear == NULL  && front == NULL)
    {
        return true;
    }

    return false;
  }

  T Pop()
  {
    if(front == NULL)
    {
      return  NULL;
    }

   Node *curr=front;
   T val=curr->data;
   front=front->next;

   if(front == NULL)
   {
     rear=NULL;
   }

   delete(curr);

   return val;

 }

 T getFront()
 {
    if(front != NULL)
    {
      return front->data;

    }

 }

 T getRear()
 {
   if(rear != NULL)
   {
     return rear->data;
   }
 }

 void Display()
 {
    if(isEmpty())
    {
        cout<<"Queue is empty\n";
        return;
    }

    Node *start=front;
  

    do
    {
      cout<<start->data<<" ";
      start=start->next;
    } while (start !=  NULL);
    
 }




  

};

class Node
{
  public:
  int data;
  Node *left;
  Node *right;

  Node(int x)
  {
    data=x;
    left=NULL;
    right=NULL;
  }

};


class BST
{
 public:

 Node *root;
 BST()
 {
   root=NULL;
 }


void Insert(int x);
void Delete(int x);
void Inorder(Node *rt);
void Preorder(Node *rt);
void Postorder(Node *rt);
void Levelorder();
int  Height(Node *rt);
Node* Createcopy(Node *rt);
Node* CreatemirrorImage(Node *rt);
void Displayparentchild();
void Displayleaf();
};

void BST::Insert(int x)
{
    // find position of node
     
    Node *temp =root;
    Node *prev=NULL;
    Node *innode= new Node(x);

    if(root == NULL)
    {
        root=innode;
        return;
    }

    while(temp != NULL)
    {
        prev=temp;
        if(temp->data > x)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }
    }

    if(prev->data < x)
    {
        prev->right=innode;
    }
    else if(prev->data > x)
    {
        prev->left=innode;
    }
return ;

}

void BST::Delete(int x)
{
    // search the node to be deleted 
    Node *temp = root;
    Node *prew=NULL;

    while(temp != NULL && temp->data != x)
    {
         prew=temp;
         if(temp->data < x)
         {
            temp=temp->right;
         }
         else if(temp->data > x)
         {
            temp=temp->left;
         }
    } 

  if(!temp) // node node found in tree
  {
    cout<<"Node not found\n";
    return;
  }  

 

  if(!temp->left || !temp->right) // => temp is having only left or right child then replace it with its child
  {
     auto todelete = (temp->left) ? temp->left:temp->right;

     if(!prew)
     {
        root=todelete;
     }
     else if(prew->left == temp)
     {
        prew->left=todelete;
     }
     else if(prew->right == temp)
     {
        prew->right=todelete;
     }

   
  }
  else // temp is having both left and right child then we need to think differntely
  {
       
    // replace temp with inorder succesor i.e leftmost child in right subtree
       Node *curr = temp->right;
       Node *currpar= temp;


       while(curr->left != NULL)
       {
         currpar=curr;
         curr=curr->left;
       }

       temp->data=curr->data;
       // now check if current is having right child if yes take care of it :)
       if(currpar->left == curr)
       {
          currpar->left=curr->right;
       }
       else 
       {
         currpar->right=curr->left;

       }

       delete(curr);
  }

}

void BST::Levelorder()
{
  if(root != NULL)
  {
    Queue<Node*>q;

    q.Push(root);
    cout<<root->data<<" ";

    while(!q.isEmpty())
    {
       Node *temp = q.Pop();
       if(temp->left)
       {
        cout<<temp->left->data<<" "; 
        q.Push(temp->left);
       }

       if(temp->right != NULL)
       {
        cout<<temp->right->data<<" ";
        q.Push(temp->right);
       }
    }
  }

}

int BST::Height(Node *rt)
{
     if(rt == NULL)
     {
       return 0;
     }
    int lheight=Height(rt->left);
    int rheight=Height(rt->right);
    
   return max(lheight,rheight)+1;

}

void BST::Displayparentchild()
{
    if(root != NULL)
    {
       Queue<Node*>q;

       q.Push(root);

       while(!q.isEmpty())
       {
          Node *temp = q.Pop();

          cout<<"Parent :- "<<temp->data<<"\n";

          if(temp->left)
          {
            cout<<"Left child of "<<temp->data<<":-"<<temp->left->data<<"\n";
            q.Push(temp->left);
          }

          if(temp->right)
          {
            cout<<"Right child of "<<temp->data<<":-"<<temp->right->data<<"\n";
            q.Push(temp->right);
          }
       }
     

    }

}

Node* BST::Createcopy(Node *rt)
{
  if(!rt)
  {
    return NULL;
  }

  Node *root_copy  = new Node(rt->data);

  root_copy->left=Createcopy(rt->left);
  root_copy->right=Createcopy(rt->right);

   return root_copy;
}

Node *BST::CreatemirrorImage(Node *rt)
{
     if(!rt)
     {
       return NULL;
     }

     Node *root_mirror= new Node(rt->data);
     root_mirror->left=CreatemirrorImage(rt->right);
     root_mirror->right=CreatemirrorImage(rt->left);

     return root_mirror;

}


void BST::Displayleaf()
{
    if(root == NULL)
    {
       return;
    }
  Queue<Node*>q;
  q.Push(root);
  cout<<"The leaf nodes are :- ";

  while(!q.isEmpty())
  {
     Node *temp = q.Pop();
     
      if(temp->left)
      {
        q.Push(temp->left);
      }

      if(temp->right)
      {
        q.Push(temp->right);
      }

      if(!temp->left && !temp->right)
      {
        cout<<temp->data<<" ";
      }
  }




}
void BST::Inorder(Node *rt)
{
    if(rt != NULL)
    {
        Inorder(rt->left);
        cout<<rt->data<<" ";
        Inorder(rt->right);
    }

}

void BST::Preorder(Node *rt)
{
    if(rt != NULL)
    {
        cout<<rt->data<<" ";
        Preorder(rt->left);
        Preorder(rt->right);
    }
}

void BST::Postorder(Node *rt)
{
   if(rt != NULL)
   {
     Postorder(rt->left);
     Postorder(rt->right);
     cout<<rt->data<<" ";
   }

}


int main()
{
    BST b1;
    b1.Insert(12);
    b1.Insert(9);
    b1.Insert(14);
    b1.Insert(8);
    b1.Insert(13);
    b1.Insert(16);
    b1.Displayleaf();
    
    // b1.Displayparentchild();
    // BST b2;
    // b2.root=b2.CreatemirrorImage(b1.root);
    // b2.Displayparentchild();

    // b2.root=b1.Createcopy(b1.root);
    // b2.Displayparentchild();

    

    // cout<<b1.Height(b1.root);

    // b1.Inorder(b1.root);
    // cout<<"\n";
    // b1.Preorder(b1.root);
    // cout<<"\n";
    // b1.Postorder(b1.root);
    // cout<<"\n";
    // b1.Levelorder();


    // cout<<"\n Deleting \n";
    // b1.Delete(14);
    // b1.Inorder(b1.root);
    // cout<<"\n";
    // b1.Preorder(b1.root);
    // cout<<"\n";
    // b1.Postorder(b1.root);

//  Queue<int>q;
//  q.Push(1);
//  q.Push(2);
//  q.Push(3);
//  q.Push(4);

//  q.Display();

//  q.Pop();

//  q.Pop();

//  q.Display();
//  q.Push(5);
//  q.Display();


   





return 0;
}