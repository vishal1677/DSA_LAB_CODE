#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
       int data;
       Node *left;
       Node *right;
       bool lthread;
       bool rthread;
       Node(int x)
       {
          data=x;
          left=NULL;
          right=NULL;
          lthread=true;
          rthread=true;
       }

};


class TBT
{
public:
       Node *root;
       TBT()
       {
        root=NULL;
       }

       void Insert(int x)
       {
           Node *temp=root;
           Node *ptr=new Node(x);

           Node *par=NULL;

           while(temp != NULL)
           {
                if(temp->data == x)
                {
                    cout<<"Inserting a duplicate value\n";
                    return;
                }

                par=temp;

                if(temp->data > x)
                {
                    if(temp->lthread == false)
                    {
                        temp=temp->left;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if(temp->rthread ==false)
                    {
                        temp=temp->right;
                    }
                    else
                    {
                        break;
                    }
                }

            }

            if(par == NULL)
            {
                root=ptr;
            }
            else if(x>par->data) // insert node to right
            {
               ptr->right=par->right;
               ptr->left=par;
               par->rthread=false;
               par->right=ptr;

            }
            else
            {
                ptr->left=par->left;
                ptr->right=par;
                par->lthread=false;
                par->left=ptr;
            }       

 
            }
       
       void DelCaseA(Node *ptr, Node *par)
       {
         if(par == NULL)
         {
            root=NULL;
         }
         else if(ptr == par->left)
         {
            par->lthread=true;
            par->left=ptr->left;


         }
         else if(ptr == par->right)
         {
            par->rthread=true;
            par->right=ptr->right;
         }

         delete(ptr);

       }

       void DelCaseB(Node *ptr, Node *par)
       {
         Node *child;

         if(ptr->lthread == false)
         {
            child=ptr->left;
         }
         else if(ptr->rthread == false)
         {
            child=ptr->right;
         }

         if(par == NULL)
         {
            root=child;
         }
         else if(ptr=par->left)
         {
            par->left=child;
         }
         else
         {
            par->right=child;
         }

         Node *s=InoSuccsor(ptr);
         Node *p=InoPredcssor(ptr);

         if(ptr->lthread == false)
         {
            p->right=s;
         }
         else if(ptr->rthread == false)
         {
            s->left=p;
         }
         
         delete(ptr);

       }

       void DelCaseC(Node *ptr, Node *par)
       {
         Node *succ=ptr->right;
         Node *parsucc=ptr;

         while(succ->left != NULL)
         {
            parsucc=succ;
            succ=succ->left;
         }

         ptr->data=succ->data;

         if(succ->lthread == true && succ->rthread == true)
         {
            DelCaseA(succ,parsucc);
         }
         else
         {
            DelCaseB(succ,parsucc);
         }


       }
       
       
       void Delete(int x)
       {
         if(root == NULL)
         {
            cout<<"Tree is empty\n";
            return;
         }

         bool flag=true;

         Node *ptr=root;
         Node *par=NULL;
         while(ptr != NULL)
         {
            par=ptr;
            if(ptr->data == x)
            { 
                flag=false;
                break;
            }
            else if(ptr->data > x)
            {
                if(ptr->lthread == false)
                {
                    ptr=ptr->left;
                }
                else
                {
                    break;
                }
            }
            else if(ptr->data < x)
            {
                 if(ptr->rthread == false)
                 {
                    ptr=ptr->right;
                 }
                 else
                 {
                    break;
                 }
            }

         }

         if(flag)
         {
            cout<<"Node not present in tree\n";
            return;
         }
         else
         {
            if(par->lthread == false && par->rthread == false)
            {
                DelCaseC(ptr,par);
            }
            else if(par->lthread == false)
            {
                DelCaseB(ptr,par);
            }
            else if(par->rthread == false)
            {
                DelCaseB(ptr,par);
            }
            else
            {
                DelCaseA(ptr,par);
            }

         }




       }
            Node *InoSuccsor(Node *curr)
            {
               if(curr->rthread == true)
               {
                 return curr->right;
               }

               curr=curr->right;

               while(curr->lthread == false)
               {
                curr=curr->left;
               }
           
            return curr;

            }
            
            Node *InoPredcssor(Node *curr)
            { 
                 if(curr->lthread == false)
                 {
                    return curr->left;
                 }

                 curr=curr->left;

                 while(curr->rthread == false)
                 {
                    curr=curr->right;
                 }

             return curr;    
            }

            void Inorder()
            {
                if(root == NULL)
                {
                    cout<<"Tree is empty \n";
                    return;
                }
               
               Node *ptr=root;
               while(ptr->lthread == false)
               {
                 ptr=ptr->left;
               }

               while(ptr != NULL)
               {
                 cout<<ptr->data<<" ";
                 ptr=InoSuccsor(ptr);

               }

            }

            void Preorder()
            {
               if(root == NULL)
               {
                  cout<<"Tree is empty\n";
                  return;
               }

               Node *ptr=root;

               while(ptr != NULL)
               {
                  cout<<ptr->data<<" ";
                  if(ptr->lthread == false)
                  {
                    ptr=ptr->left;
                  }
                  else if(ptr->rthread == false)
                  {
                    ptr=ptr->right;
                  }
                  else
                  {
                      while(ptr != NULL && ptr->rthread == true)
                      {
                        ptr=InoSuccsor(ptr);
                      }
                   if(ptr != NULL)
                   {
                    ptr=ptr->right;
                   }
                
                  }


               }
            
            }

            void RecInorder(Node *rt);
            void RecPreorder(Node *rt);
            void RecPostorder(Node *rt);

};

void TBT::RecInorder(Node *rt)
{
    if(rt != NULL)
    {
       if(rt->lthread == false)
       {
         RecInorder(rt->left);
       }

       cout<<rt->data<<" ";

       if(rt->rthread == false)
       {
        RecInorder(rt->right);
       }

    }

}

void TBT::RecPostorder(Node *rt)
{
    if(rt != NULL)
    {
        if(rt->lthread == false)
        {
            RecPostorder(rt->left);
        }

        if(rt->rthread == false)
        {
            RecPostorder(rt->right);
        }

        cout<<rt->data<<" ";
    }

}

void TBT::RecPreorder(Node *rt)
{
    if(rt != NULL)
    {
        cout<<rt->data<<" ";

        if(rt->lthread == false)
        {
            RecPreorder(rt->left);
        }

        if(rt->rthread == false)
        {
            RecPreorder(rt->right);
        }
    }
}




int main()
{
TBT t1;
t1.Insert(5);
t1.Insert(1);
t1.Insert(13);
t1.Insert(10);
t1.Insert(15);

cout<<"Inorder:- ";
t1.Inorder();
t1.Delete(13);
cout<<"\n";

cout<<"Inorder:- ";
t1.Inorder();




return 0;
}
