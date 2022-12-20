#include<bits/stdc++.h>
using namespace std;
#define size 5

class CircularQ
{
 private:
 int front=-1;
 int rear=-1;
 int arr[size];

 public:

 CircularQ()
 {
    for(int i=0; i<size; i++)
    {
        arr[i]=-1;
    }
 }

 bool isEmpty()
 {
    if(front == rear)
    {
      return true;
    }

    return false;    
 }

 bool isFull()
 {
    if((rear+1)%size == front)
    {
        return true;
    }
   return false;
 }

 void Enque(int x)
 {
    if(isFull())
    {
        cout<<"Queue is full\n";
    }
    else
    {
        rear=(rear+1)%size;
        arr[rear]=x;
    }

 }

 int Dequeue()
 {
    if(isEmpty())
    {
        cout<<"Queue is Empty\n";
        return -1;
    }
    else
    {
       int x=arr[front];
       arr[front]=-1;
       front=(front+1)%size;
       return x;
    }
 } 
 
 void Display()
 {
    if(isEmpty())
    {
        cout<<"Queue is empty\n";
        return;
    }
     int i=front+1;

     do
     {
        if(arr[i] != -1){
       cout<<arr[i]<<" ";
        }
       i=(i+1)%size;

     } while (i != (rear+1)%size);
     

 }

 int getFront()
 {
    if(isEmpty())
    {
        cout<<"Queue is full\n";
        return -1;
    }
    else
    {
       return arr[(front+1)%size];
    }

 }
 int getRear()
 {
    if(isEmpty())
    {
        cout<<"Queue is empty\n";
        return -1;
    }
    else
    {
        return arr[(rear+1)%size];
    }

 }

};

int main()
{
  CircularQ cq;
  cq.Enque(1);
  cq.Enque(2);
  cq.Enque(3);

  cq.Display();
  cout<<"\n";
  cq.Dequeue();
  cq.Display();
  cq.Dequeue();
  cout<<"\n";
  cq.Display();
  cq.Enque(4);
  cout<<"\n";
  cq.Display();

return 0;
}