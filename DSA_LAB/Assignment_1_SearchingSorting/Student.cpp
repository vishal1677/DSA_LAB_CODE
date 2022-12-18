#include<bits/stdc++.h>
using namespace std;

class Student
{
 private:
 string Name;
 double RollNo;
 int SGPA;

 public:
 Student()
 {
    Name="";
    RollNo=0;
    SGPA=0;

 }
 Student(string Name,double RollNo, int SGPA)
 {
    this->Name=Name;
    this->RollNo=RollNo;
    this->SGPA=SGPA;
 }

 void PrintInfo()
 {
    cout<<"Name    :- "<<Name<<"\n";
    cout<<"Roll No :- "<<RollNo<<"\n";
    cout<<"SGPA    :- "<<SGPA<<"\n";

 }
 string getName(){ return Name;}
 double getRollNo(){ return RollNo;}
 int getSGPA(){ return SGPA;}

};


class Database
{
  private:
   Student *Record;
   int size;

  public:
  Database(int n)
  {
    size=n;
    Record= new Student[size];

  }
  void Add();
  void Adddefault();
  void PrintDB();
  void ArrageByRollCall();
  void ArrangeByName();
  void ArrangeBySGPA();
  void SearchBySGPA();
  void SearchByName();

   ~Database()
   {
     delete [] Record;

   }
};

void Database::Add()
{
    for(int i=0; i<size; i++)
    {
    cout<<"Enter for student "<<i+1<<"\n";
    cout<<"Enter your Name :- ";
    string s; cin>>s;
    cout<<"Enter your RollNo :- ";
    double rn; cin>>rn;
    cout<<"Enter your SGPA :- ";
    float sgpa; cin>>sgpa;
    Student s1(s,rn,sgpa);
    Record[i]=s1;

    }
    
}

void Database ::Adddefault()
{
   Student s1("Vishal", 5,1);
  Student s2("Anish",23,12);
   Student s3("Shivraj",2,9.3);
   Record[0]=s1;
   Record[1]=s2;
   Record[2]=s3;
 
}

void Database:: PrintDB()
{
   for(int i=0; i<size; i++)
   {
     Record[i].PrintInfo();
   }

}


void Database::ArrageByRollCall() // use bubble sort
{
    for(int i=0; i<size-1; i++)
    {
       for(int j=0; j<size-1-i; j++)
       {
          if(Record[j].getRollNo() > Record[j+1].getRollNo() )
          {
             Student temp= Record[j];
             Record[j]=Record[j+1];
             Record[j+1]=temp;

          }
       }
    }

   
}

void Database::ArrangeByName() // use insertion sort
{
   for(int i=0; i<size; i++)
   {
      Student tmp=Record[i];
      int j=i-1;

      while(j>=0 && Record[j].getName() > tmp.getName() )
      {
         Record[j+1]=Record[j];
         j--;
      }
    Record[j+1]=tmp;

   }

 
}

int Partition(Student Record[],int lo, int hi)
{
   int i=lo;
   int j=hi;
   Student pivot = Record[lo];

   do
   {
      do{i++; }while(Record[i].getSGPA() <= pivot.getSGPA());
      do{j--;}while(Record[j].getSGPA() > pivot.getSGPA());

      if(i<j)
      {
         Student tmp = Record[i];
         Record[i]=Record[j];
         Record[j]=tmp;    
      }

   } while (i<j);

   Student tmp= Record[lo];
   Record[lo]=Record[j];
   Record[j]=tmp;

   return j;
}

void  QuickSort(Student Record[],int lo, int hi)
{ 
   int k;
   if(lo<hi)
   {
      k=Partition(Record,lo,hi);
      QuickSort(Record,0,k);
      QuickSort(Record,k+1,hi);
   }
}


void Database::ArrangeBySGPA() // use quick sort
{
   QuickSort(Record,0,size);
   for(int i=size-1; i>=0; i--) // quick sort sorts the array in increasing order so print the array in reverse manner
   {
      Record[i].PrintInfo();
   }

   
}

void Database::SearchByName() // use binary search
{
   cout<<"Enter the Name you want to search ? ";
   string key; cin>>key;

   ArrangeByName();
   int lo=0;
   int hi=size-1;
   bool flag = true;

   while(lo<=hi)
   {
      int mid=lo+(hi-lo)/2;
      if(Record[mid].getName() == key )
      {
         cout<<"Student found in records\n";
         Record[mid].PrintInfo();
         flag=false;
         break;
      }
      else if(Record[mid].getName() > key)
      {
         hi=mid-1;
      }
      else
      {
         lo=mid+1;
      }
   }
   
   if(flag)
   {
      cout<<"Student not found in records\n";
   }

}

void Database::SearchBySGPA()
{
   cout<<"Enter SGPA that you want to find \n";
   float sgpa; cin>>sgpa;
   bool flag=true;

   for(int i=0; i<size; i++)
   {
      if(Record[i].getSGPA() == sgpa)
      {
         Record[i].PrintInfo();
      }
   }

   if(flag){
      cout<<"Student not found in records\n";
   }

}

int main()
{
  Database db(3);
//   db.Add();
 db.Adddefault();
//  db.PrintDB();
//  db.PrintDB();
db.ArrangeBySGPA();
// db.PrintDB();
// db.SearchByName();
//db.ArrageByRollCall();
// db.ArrangeByName();
/*
You can add validations and make it menu driven its damm easy :0)

*/


return 0;
}