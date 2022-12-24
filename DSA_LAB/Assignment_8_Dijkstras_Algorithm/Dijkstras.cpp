#include<bits/stdc++.h>
using namespace std;
#define edges 6

class Graph
{
  public: 
        vector<pair<int,int>> EdgeList[edges];
        void Addedge(int u, int v, int w)
        {
            EdgeList[u].push_back({v,w});
            EdgeList[v].push_back({u,w});
        }

        void Dijskstra(int source)
        {
           vector<bool>visited(edges, false);
           vector<int>dist(edges, INT_MAX);
           set<pair<int,int>>pq;
           pq.insert({0,source}); // first value is weight and second value is vertex no
           dist[source]=0;

           visited[source]=false;


           while(pq.size() > 0)
           {
              auto node = *pq.begin();
              int wt=node.first;
              int v=node.second;
              pq.erase(pq.begin());

               
               if(visited[v]) continue;

               visited[v]=true;
             
               for(auto child:EdgeList[v])
               {
                 int child_v=child.first;
                 int child_wt=child.second;

                 if(dist[v]+child_wt < dist[child_v])
                 {
                    dist[child_v]=dist[v]+child_wt;
                    pq.insert({dist[child_v], child_v});
                 }


               }
           }

           for(int i=0; i<edges; i++)
           {
              cout<<"From "<<source<<" to "<<i<<" @"<<dist[i]<<"\n";
           }

        }


};

int main()
{
    Graph g1;
    g1.Addedge(0,1,1);
    g1.Addedge(1,2,3);
    g1.Addedge(2,3,5);
    g1.Addedge(3,4,4);
    g1.Addedge(4,5,2);
    g1.Addedge(4,0,7);
    g1.Addedge(5,0,4);

    g1.Dijskstra(0);



return  0;
}