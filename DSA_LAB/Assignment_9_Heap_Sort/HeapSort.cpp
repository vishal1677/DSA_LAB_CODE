#include<bits/stdc++.h>
using namespace std;
#define maxsize 100

class Maxheap
{
 public:
         int  arr[maxsize];
         int arrsize;

         Maxheap()
         {
            arrsize=0;
            arr[0]=-1;
         }
      
         void Insert(int x);
         int  Delete();
         void Print();

};

void Maxheap::Insert(int x)
{
  arrsize=arrsize+1;
  int index=arrsize;
  
  arr[index]=x;

  while(index > 1)
  {
     int parent=index/2;

     if(arr[parent] < arr[index])
     {
        swap(arr[parent], arr[index]);
        index=parent;

     }
     else
     {
       return;
     }

  }

}


int Maxheap::Delete()
{
    if(arrsize == 0)
    {
        cout<<"Heap is empty\n";
        return -1;
    }

    int val=arr[1];
    arr[1]=arr[arrsize];
    arr[arrsize]=val;

    arrsize--;

    int i=1;

    while(i<arrsize)
    {
         int l=2*i;
         int r=2*i+1;

         if( l < arrsize &&  arr[i] < arr[l])
         {
            swap(arr[i], arr[l]);
            i=l;
         }
         else if(r < arrsize && arr[i] < arr[r])
         {
            swap(arr[i], arr[r]);
            i=r;
         }
         else
         {
            break;
         }
    }

return val;

}

// void Maxheap::PrintinSorted()
// { 
//    int n=arrsize;

//    while(arrsize > 0)
//    {
//      Delete();
//    }

//    for(int i=1; i<=n; i++)
//    {
//     cout<<arr[i]<<" ";
//    }
    
    


// }

void Heapify(vector<int>&v, int n, int i)
{
    int largest=i;
    int lefti=2*i;
    int righti=2*i+1;

    if(lefti <= n && v[largest] < v[lefti])
    {
        largest=lefti;
    }

    if(righti <= n && v[largest] < v[righti])
    {
        largest=righti;
    }

    if(largest != i)
    {
        swap(v[i], v[largest]);
        Heapify(v,n,largest);
    }
  
}

void Heapsort(vector<int>&v, int n)
{
    for(int i=n/2; i>=0; i--)
    {
        Heapify(v,n,i);
    }

    int t=n;
    while(t > 1)
    {
        swap(v[t],v[1]);
        t--;
 
        Heapify(v,t,1);
    }

    for(int i=1; i<=n; i++)
    {
       cout<<v[i]<<" ";
    }
}



void Maxheap::Print()
{
    for(int i=1; i<=arrsize; i++)
    {
        cout<<arr[i]<<" ";
    }
}


class Minheap
{


};

int main()
{
    Maxheap h1;
    h1.Insert(1);
    h1.Insert(2);
    h1.Insert(3);
    h1.Insert(4);
    h1.Insert(5);
    h1.Insert(17);
    h1.Insert(18);
    h1.Insert(19);



    vector<int>v={2,4,17,2,56};
    Heapsort(v,5);







  





return 0;
}