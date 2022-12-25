#include<bits/stdc++.h>
using namespace std;

class Student
{
 private:
        string RollNo;
        string Name;
        string Division;
public:
       Student(string rn, string name, string div)
       {
         RollNo=rn;
         Name=name;
         Division=div;
       }

       string getRollNo(){ return RollNo; }
       string getName(){ return Name; }
       string getDivision(){ return Division; }
};

class Database
{
 public:
         void Add();
         void Display();
         void Delete(string key);
         void Search(string key);
         void Update(string key);
         bool validate(string s);

         vector<string> Split(string s, char del);
};

void Database::Add()
{
   cout<<"Enter Name:- ";
   string name; 
   cin>>name;
   cout<<"Enter RollNo:- ";
   string rn;
   cin>>rn;
   cout<<"Enter Division:- ";
   string div;
   cin>>div;
   string s=name+","+rn+","+div+"\n";
   ofstream outfile("data.txt",ios::app);
   outfile<<s;

   outfile.close();

}

bool  Database::validate(string s)
{ 
   double rn;
   try
   {
      rn=stod(s);
   }
   catch(exception e)
   {
      return false;
   }

   if(s.length() == 5 && rn > 0)
   {
      return true;
   }
   
return false;

}

vector<string> Database :: Split(string s, char del)
{
   vector<string>ans;
   string temp="";

   for(int i=0; i<s.length(); i++)
   {
     
      if(s[i] == del )
      {
        ans.push_back(temp);
        temp="";
      }
      else
      {
       temp.push_back(s[i]);
      }
   }

   ans.push_back(temp);

 return ans;  

}


void Database::Display()
{
   ifstream infile("data.txt");
   string s;

   getline(infile,s);  
  
   while(!infile.eof())
   {
     vector<string>token = Split(s,',');
     cout<<"Name     :- "<<token[0]<<"\n";
     cout<<"RollNo   :- "<<token[1]<<"\n";
     cout<<"Division :- "<<token[2]<<"\n";
     getline(infile,s);
   }
   
   infile.close();

}


void Database::Delete(string key)
{ 
   ifstream oldfile("data.txt");
   ofstream  newfileout("new.txt",ios::app);
   string s;
   getline(oldfile,s);

   while(!oldfile.eof())
   {
      vector<string>token=Split(s,',');
      if(key != token[1])
      {
         newfileout<<s<<"\n";
      }
      getline(oldfile,s);

   }

   oldfile.close();
   newfileout.close();

   remove("data.txt");
   rename("new.txt","data.txt");
}


void Database::Search(string key)
{
   ifstream infile("data.txt");
   string s;
   getline(infile,s);
   bool flag=true;

   while(!infile.eof())
   {
      vector<string>token = Split(s,',');
      if(key == token[1])
      {
         flag=false;
         cout<<"Student found in records ... Loading data\n";
         cout<<"Name     :- "<<token[0]<<"\n";
         cout<<"RollNo   :- "<<token[1]<<"\n";
         cout<<"Division :- "<<token[2]<<"\n";

         break;
      }

      getline(infile,s);

   }

if(flag)
{
   cout<<"Student not found in records\n";
}

    

}

void Database::Update(string key)
{
   ifstream infile("data.txt");
   ofstream outfile("new.txt");
   cout<<"Enter what you want to modify\n";
   cout<<"1) Name\n";
   cout<<"2) RollNo\n";
   cout<<"3) Division\n";
   int ch;
   cin>>ch;
   ch--;

   cout<<"Enter modified value:- ";
   string modify;
   cin>>modify;


   string s;
   getline(infile,s);

   while(!infile.eof())
   {
      vector<string>token = Split(s,',');
      if(key != token[1])
      {
          outfile<<s<<"\n";
      }
      else
      {
         token[ch]=modify;
         string wrt=token[0]+token[1]+token[2];
         outfile<<wrt<<"\n";
      }

     getline(infile,s);

   }

   infile.close();
   outfile.close();

   remove("data.txt");
   rename("new.txt","data.txt");

}



int main()
{
  
  







     


   

return 0;
}