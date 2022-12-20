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
                return -1;
            }
            T x = head->data;
            Node *temp = head;
            head=head->next;
            delete(temp);
            return x;
         }

         T getTop()
         {
            if(head == NULL) return -1;

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
    
class Expression
{
    public:
    bool isOperator(char x)
    {
       if(x == '+' || x=='-' || x=='*' || x=='/' || x=='^' || x=='(' || x==')')
       {
        return true;
       }

       return false;
    }

    int Rank(char x)
    {
        if(x == '^')
        {
            return 3;
        }
        else if( x == '*' || x=='/')
        {
            return 2;
        }
        else if(x == '+' || x=='-')
        {
            return 1;
        }

    return -1;

    }

    string InfinxtoPostfix(string s)
    {
        Stack<char>st;
        string ans="";

        for(int i=0; i<s.length(); i++)
        {
           if(!isOperator(s[i]))
           {
            ans.push_back(s[i]);
           }
           else if( s[i] == '(')
           {
            st.Push(s[i]);
           }
           else if(s[i] == ')')
           {
              while(st.getTop() != '(' && !st.isEmpty())
              {
                 ans.push_back(st.Pop());
              }
           }
           else 
           {
             if(Rank(s[i]) >= Rank(st.getTop()))
             {
               st.Push(s[i]);
             }
             else
             {
               while(Rank(s[i]) < Rank(st.getTop()) && !st.isEmpty())
               {
                 ans.push_back(st.Pop());
               }

               st.Push(s[i]);
             }
           }

        }

        while(!st.isEmpty())
        {
            if(st.getTop() == '(')
            {
                st.Pop();
                continue;
            }
            ans.push_back(st.Pop());
        }
    return ans;

    }

    string InfixtoPrefix(string s)
    {
        Stack<char>st;
        int n=s.length();
       
        string news=s;
    
        reverse(news.begin(), news.end());

        for(int i=0; i<n; i++)
        {
           if(news[i] == '(')
           {
            news[i]=')';
           }
           else if(news[i] == ')')
           {
             news[i]='(';
           }
        }

       string ans=InfinxtoPostfix(news);
       reverse(ans.begin(), ans.end());
       return ans;

    }

    float EvaluatePostfix(string s)
    {
      map<char,float>mp;

      for(int i=0; i<s.length(); i++)
      {
        if(!isOperator(s[i]))
        {
          cout<<"Enter value of "<<s[i]<<" :- ";
          float x; cin>>x;
          mp[s[i]]=x;
        }


      }
      Stack<float>st;

      for(int i=0; i<s.length(); i++)
      {
        if(!isOperator(s[i]))
        {
            st.Push(mp[s[i]]);
        }
        else
        {
           if(s[i] == '+')
           {
              float val1=st.Pop();
              float val2=st.Pop();
              float res=val1+val2;
              st.Push(res);
           }
           else if(s[i] == '-')
           {
              float val1=st.Pop();
              float val2=st.Pop();
              float res=val2-val1;
              st.Push(res);

           }
           else if(s[i] == '*')
           {
              float val1=st.Pop();
              float val2=st.Pop();
              float res=val2*val1;
              st.Push(res);

           }
           else if(s[i] == '/' )
           {
              float val1=st.Pop();
              float val2=st.Pop();
              float res=val1+val2;
              st.Push(res);
           }

        }

      }

    return st.getTop();

    }

    float EvaluatePrefix(string s)
    {
      map<char,float>mp;
      int n=s.length();
      Stack<float>st;

      for(int i=0; i<n; i++)
      {
         if(!isOperator(s[i]))
         {
           cout<<"Enter value of "<<s[i]<<":- ";
           float x; cin>>x;
           mp[s[i]]=x;
         }

      }

      for(int i=n-1; i>=0; i--)
      {
        if(!isOperator(s[i]))
        {
          st.Push(mp[s[i]]);
        }
        else
        {
           if(s[i] == '+')
           {
              float val1=st.Pop();
              float val2=st.Pop();
              float res=val1+val2;
              st.Push(res);
           }
           else if(s[i] == '-')
           {
              float val1=st.Pop();
              float val2=st.Pop();
              float res=val1-val2;
              st.Push(res);

           }
           else if(s[i] == '*')
           {
              float val1=st.Pop();
              float val2=st.Pop();
              float res=val2*val1;
              st.Push(res);
           }
           else if(s[i] == '/' )
           {
              float val1=st.Pop();
              float val2=st.Pop();
              float res=val2/val1;
              st.Push(res);
           } 
        }
      }

      return st.getTop();
    
    }

    bool ValidateInfix(string s)
    {
       Stack<char>st;
       for(int i=0; i<s.length();i++)
       {
         if(s[i] == '(')
         {
            st.Push(s[i]);
         }
         else
         {
            if(st.isEmpty() || st.getTop() != '(')
            {
                return false;
            }
            st.Pop();
         }
       }

       return true;
       
    }


};
int main()
{

Expression e1;
cout<<e1.InfinxtoPostfix("(a+b)*(c-d)")<<"\n";
cout<<e1.InfixtoPrefix("(a+b)*(c-d)")<<"\n";
// float res=e1.EvaluatePostfix("ab+cd-*");
// cout<<res<<"\n";
float res1=e1.EvaluatePrefix("+ab");
cout<<res1<<"\n";


return 0;
}