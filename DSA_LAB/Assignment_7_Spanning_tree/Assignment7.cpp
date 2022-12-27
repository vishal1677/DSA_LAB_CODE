#include<bits/stdc++.h>
using namespace std;
# define Edgepair pair<int,pair<int,int>>

struct Pair
{
  int v;
  int av;
  int wt;
};
struct Compare
{
 bool operator()(Pair p1, Pair p2)
 {
     return p1.wt>p2.wt;

 }

};
class SpanningTree
{
  public:
        int Graph[6][6]={
            {0,1,0,0,0,2},
            {1,0,2,0,0,0},
            {0,2,0,1,0,0},
            {0,0,1,0,3,0},
            {0,0,0,3,0,4},
            {2,0,0,0,4,0}
        };


vector<pair<int , pair<int, int> > >Edges;

void AddEdge(int v1, int v2, int wt)
{
  Edges.push_back({wt,{v1,v2}});
}
void MakeEdges()
{
  AddEdge(0,1,1);
  AddEdge(1,2,2);
  AddEdge(2,3,1);
  AddEdge(3,4,3);
  AddEdge(4,5,4);
  AddEdge(5,0,2);

}

  // for(int i=0; i<Edges.size(); i++)
  // {
  //   cout<<" From "<<Edges[i].second.first<<" to "<<Edges[i].second.second<<" at "<<Edges[i].first<<"\n";

  // } 
string Encode(int n)
{ 
  if(n == 0)
  {
    return "Gate";
  }
  else if(n == 1)
  {
     return "Library";
  }
  else if(n == 2)
  {
     return "EnTc Dept";
  }
  else if(n == 3)
  {
     return "CE Dept";
  }
  else if(n == 4)
  {
     return "IT Dept";
  }
  else if(n == 5)
  {
    return "FE Dept";
  }

}

void Prims()
{
priority_queue<Pair,vector<Pair>,Compare>pq;
vector<bool>visited(6,false);

pq.push({0,-1,0});

while(pq.size() > 0)
{
  Pair rm = pq.top();
  pq.pop();

  if(visited[rm.v] == true ) continue;

  visited[rm.v] == true;

  if(rm.av != -1)
  {
    cout<<"From "<<rm.v<<" to "<<rm.av<<" at "<<rm.wt<<"\n";
  }

// find adjecent nodes of u

for(int i=0; i<6; i++)
{
   if(Graph[rm.v][i] != 0  && visited[i] == false)
   {
    pq.push({i,rm.v, Graph[rm.v][i]});
     
   }
}


}

}
void Makeset(vector<int>&parent , vector<int>&rank, int n)
{
  for(int i=0; i<n; i++)
  {
    parent[i]=i;
    rank[i]=0;
  }
   
}
int Findparent(vector<int>&parent , int node )
{
  if(parent[node] == node)
  {
    return node;
  }

  return parent[node]=Findparent(parent, parent[node]);
  
}
void Union(int u, int v, vector<int>&parent, vector<int>&rank )
{
  u=Findparent(parent,u);
  v=Findparent(parent,v);


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
  }


}
void Kruskal()
{
   vector<int>parent(6);
   vector<int>rank(6);
   MakeEdges();
   Makeset(parent, rank, 6);
   sort(Edges.begin(), Edges.end());
   int minweight=0;
   
   for(int i=0; i<Edges.size(); i++)
   {
      
         int u=Findparent(parent,Edges[i].second.first);
         int v=Findparent(parent,Edges[i].second.second);

       if(u != v)
       {
            Union(u,v, parent, rank);
            cout<<" From "<<Encode(Edges[i].second.first)<<" to "<<Encode(Edges[i].second.second)<<" at cost "<<Edges[i].first<<"\n";
            minweight+=Edges[i].first;
       }

       
   }

cout<<"The total minimum cost of spanning  tree is "<<minweight<<"\n";
}
void Display()
{
  sort(Edges.begin(), Edges.end());

  for(int i=0; i<Edges.size(); i++)
  { 
     cout<<Edges[i].second.first<<" "<<Edges[i].second.second<<" "<<Edges[i].first<<"\n";
  
  } 
}
};
int main()
{

  SpanningTree spanning;
  // spanning.Prims();
  spanning.Kruskal();
  // spanning.MakeEdges();
  // spanning.Display();
  

  //****Output*****//
 /*
 From Gate to Library at cost 1
 From EnTc Dept to CE Dept at cost 1
 From Library to EnTc Dept at cost 2
 From FE Dept to Gate at cost 2
 From CE Dept to IT Dept at cost 3
 The total minimum cost of spanning  tree is 9 
*/

return 0;
}