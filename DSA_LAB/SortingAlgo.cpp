#include<bits/stdc++.h>
using namespace std;

void BubbleSort(int arr[], int n)
{
   for(int i=0; i<n-1; i++)
   {
    for(int j=0; j<n-i-1; j++)
    {
        if(arr[j]>arr[j+1])
        {
            swap(arr[j], arr[j+1]);
        }
    }
   }
}

void InsertionSort(int arr[], int n)
{
   for(int i=0; i<n; i++)
   {
      int temp=arr[i];
      int j=i-1;
      while(arr[j] > temp && j>=0)
      {
        arr[j+1]=arr[j];
        j--;
      }
      arr[j+1]=temp;
   }
}


int Partition(int arr[], int l, int h)
{
    int tem=arr[l];
    int i=l;
    int j=h;

    do
    {
        do{i++;}while(arr[i]<=tem);
        do{j--;}while(arr[j]>tem);

        if(i<j)
        {
            swap(arr[i], arr[j]);
        }
        
    } while (i<j);
    swap(arr[j], arr[l]);

return j;
}

void QuickSort(int arr[],int l,int h)
{
    int k;
    if(l<h)
    {
       k=Partition(arr,l,h);
       QuickSort(arr,0,k);
       QuickSort(arr,k+1,h);
    }

}

void Merge(int arr[], int l, int mid,int h, int n)
{ 
    int A[n];
    int i=l;
    int j=mid+1;
    int k=0;

    while(i<= mid && j<=h)
    {
         if(arr[i]<arr[j])
         {
            A[k]=arr[i];
            k++;
            i++;
         }
         else
         {
            A[k]=arr[j];
            k++;
            j++;
         }
    }

    for(; i<=mid; i++)
    {
       A[k]=arr[i];
       k++;
    }

    for(; j<=h; j++)
    {
        A[k]=arr[j];
        k++;
    }

    for(int i=l,j=0; i<=h; i++,j++)
    {
        arr[i]=A[j];
    }

}

void MergeSort(int arr[], int l, int h, int n)
{
    int mid;
    if(l<h)
    {
       mid=(l+h)/2;
        MergeSort(arr,l,mid, n);
        MergeSort(arr,mid+1,h,n);
        Merge(arr,l,mid,h,n);
    }

}

void Print(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
 int a[]={5,4,3,2,1};
//  BubbleSort(a,5);
 Print(a,5);
//  QuickSort(a,0,5);
MergeSort(a,0,4,5);

// InsertionSort(a,5);
cout<<"\n";
Print(a,5);
return 0;
}