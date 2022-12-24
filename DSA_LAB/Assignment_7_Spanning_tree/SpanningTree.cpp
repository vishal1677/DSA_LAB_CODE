#include<bits/stdc++.h>
using namespace std;
#define maxsize 6


class Graph
{
 public:


vector<pair<int,int>>EdgeNode [maxsize];

void Addnode(int u, int v, int wt)
{
   EdgeNode[u].push_back({v,wt});

   EdgeNode[v].push_back({u,wt});

}


void Prims()
{
 

   vector<bool>visited(false,maxsize);
   vector<int>key(maxsize,INT_MAX);
   vector<int>parent(maxsize);
   priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
  
   pq.push({0,0});
   key[0]=0;
   parent[0]=0;

   for(int count =0; count<maxsize-1; count++)
   {
     int v=pq.top().second;
     pq.pop();

     visited[v]=true;

     for(auto child:EdgeNode[v])
     {
        int child_v=child.first;
        int wt=child.second;

        if(visited[child_v] == false && wt<key[child_v])
        {
            key[child_v]=wt;
            parent[child_v]=v;
            pq.push({wt,child_v});
        }

     }
   }
   
   for(int i=0; i<maxsize; i++)
   {
       cout<<"From "<<i<<" to "<<parent[i]<<" @ "<<key[i]<<"\n";
   }
   
  cout<<"Minimum weight of spanning tree "<<accumulate(key.begin(), key.end(), 0);

}


unordered_map<int,list<pair<int,int>>>AdjList;
// void Addnode(int u, int v, int wt)
// {
//    AdjList[u].push_back({v,wt});
//    AdjList[v].push_back({u,wt});
// }

void NewPrims()
{
  vector<int>value(maxsize,INT_MAX);
  vector<bool>visited(maxsize,false);
  vector<int>parent(maxsize,-1);

  int ans=0;

  value[0]=0;
  parent[0]=0;

  
  for(int i=0; i<maxsize-1; i++)
  {
      int mini=INT_MAX;
      int u;

      for(int v=0; v<maxsize; v++)
      {

        if(visited[v] == false && value[v] <mini)
        {
          u=v;
          mini=value[v];
        }
      }

      visited[u]=true;

     for(auto it:AdjList[u])
     {

      int v=it.first;
      int wt=it.second;
      
     if(visited[v] == false &&  wt<value[v])
     {
      parent[v]=u;
      value[v]=wt;
      ans+=wt;

     }
        

     }
  
  }
  
  for(int i=0; i<maxsize; i++)
  {
      cout<<"From "<<parent[i]<<" to "<<i<<" @ "<<value[i]<<"\n";

  }
  
cout<<"The minimum weight of tree is "<<accumulate(value.begin(), value.end(),0)<<"\n";


}

vector<pair<int,pair<int,int>>>EdgeList;
 void Addegde(int u,int v, int wt)
 {
    EdgeList.push_back({wt,{u,v}});
 }


 void Makeset(vector<int>&parent, vector<int>&rank)
 {
      for(int i=0; i<maxsize; i++)
      {
         parent[i]=i;
         rank[i]=0;
      }

 }

 int Findparent(int val, vector<int>parent)
 {
    if(parent[val] == val)
    {
      return val;
    }

    return parent[val]=Findparent(parent[val],parent);

 }

 void Union(int u, int v, vector<int>&parent, vector<int>&rank)
 {
     u=Findparent(u,parent);
     v=Findparent(v,parent);

     if(rank[u] < rank[v])
     {
       parent[u]=v;
     }
     else if(rank[v] < rank[u])
     {
       parent[v]=u;
     }
     else
     {
       parent[u]=v;
       rank[v]++;
     }
 }


 
 void Kruskals()
 {
   vector<int>parent(maxsize);
   vector<int>rank(maxsize);
   Makeset(parent,rank);
   sort(EdgeList.begin(), EdgeList.end());
   int ans=0;

   for(int i=0; i<EdgeList.size(); i++)
   {
      int u=Findparent(EdgeList[i].second.first,parent);
      int v=Findparent(EdgeList[i].second.second, parent);

      if(u != v)
      {
       cout<<"From "<<EdgeList[i].second.first<<" to "<<EdgeList[i].second.second<<" @ "<<EdgeList[i].first<<"\n";
        ans+=EdgeList[i].first;
        Union(u,v,parent,rank);
      }

   }
 
cout<<"Minimum weight of spanning tree is "<<ans<<"\n";


 }

 void Display()
{
  sort(EdgeList.begin(), EdgeList.end());

  for(int i=0; i<EdgeList.size(); i++)
  { 
     cout<<EdgeList[i].second.first<<" "<<EdgeList[i].second.second<<" "<<EdgeList[i].first<<"\n";
  
  } 
}

};



int main()
{
   Graph g1;
  //  g1.Addegde(0,1,1);
  //  g1.Addegde(1,2,3);
  //  g1.Addegde(2,3,5);
  //  g1.Addegde(3,4,4);
  //  g1.Addegde(4,5,2);
  //  g1.Addegde(4,0,7);
  //  g1.Addegde(5,0,4);

  //  g1.Kruskals();

   cout<<"\n";

   g1.Addnode(0,1,1);
   g1.Addnode(1,2,3);
   g1.Addnode(2,3,5);
   g1.Addnode(3,4,4);
   g1.Addnode(4,5,2);
   g1.Addnode(4,0,7);
   g1.Addnode(5,0,4);

   g1.Prims();







return 0;
}

