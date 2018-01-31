
#include <bits/stdc++.h>

using namespace std;

void bfs(vector<list<int> > adjacencyList, int parent[], int level[], int start)
{
    list<int>::iterator itr;
    level[start] = 0;
    list<int> VertexQueue;
    VertexQueue.push_back(start);
     while (!VertexQueue.empty())
    {
        int newVertex = VertexQueue.front();
         itr = adjacencyList[newVertex].begin();
       while (itr != adjacencyList[newVertex].end()) {
            if (level[*itr] == -1) {
                level[*itr] = level[newVertex] + 1;
                parent[*itr] = newVertex;
                VertexQueue.push_back(*itr);
            }
            ++itr;
        }
          VertexQueue.pop_front();    
    }
}

int main() {
   int q;cin>>q;
    while(q--)
        {
        int v,e;cin>>v>>e;
           vector< list<int> > adjlist(v + 1);
        for(int i=0;i<e;i++)
            {
            int a,b;cin>>a>>b;
            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
        }
        int st;cin>>st;//st=source node (start)
        int parent[v + 1];

    int level[v + 1];


    for (int i = 0; i <= v; ++i) {

        parent[i] = 0;
        level[i] = -1;
    }
        bfs(adjlist,parent,level,st);

        for(int i=1;i<=v;++i) // prints level(distance from source) of each node (reachable else prints -1)
            {
            if(level[i]>0)
               cout<<level[i]<<" ";
            if(level[i]<0) cout<<-1<<" ";
        }
        cout<<endl;
    }
    return 0;
}

