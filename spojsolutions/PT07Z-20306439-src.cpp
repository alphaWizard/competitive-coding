#include <bits/stdc++.h>

using namespace std;

int bfs(vector<list<pair<int,int> > > adjacencyList,  int level[], int start,int label,int v)
{
    //list<int>::iterator itr;
    level[start] = 0;
    list<int > VertexQueue;
    VertexQueue.push_back(start);
     while (!VertexQueue.empty())
    {
        int newVertex = VertexQueue.front();
        auto itr = adjacencyList[newVertex].begin();
       while (itr != adjacencyList[newVertex].end()) {
            if (level[(*itr).first] == -1) {
                level[(*itr).first] = level[newVertex] + (*itr).second;
                VertexQueue.push_back((*itr).first);
            }
            ++itr;
        }
          VertexQueue.pop_front();    
    }
   int in=1;
 for(int i=2;i<=v;++i)
 {
     if(level[i]>level[in]) in=i;
     
 }
    if(label==0) return in;
    return level[in];
    
    
}

int main() {
    
 
     
       int v;
        cin>>v;
        int e;
        e=v-1;
           vector< list<pair<int,int> > >adjlist(v + 1);
        for(int i=0;i<e;i++)
            {
            int a,b;cin>>a>>b;
            adjlist[a].push_back({b,1});
            adjlist[b].push_back({a,1});
        }
   
        //int parent[v + 1];

    int level[v + 1];


    for (int i = 0; i <= v; ++i) {

    
        level[i] = -1;
    }
        int st=1;
       int node= bfs(adjlist,level,st,0,v);
        //cout<<node;
            for (int i = 0; i <= v; ++i) {

    
        level[i] = -1;
    }
        
        cout<<bfs(adjlist,level,node,1,v)<<endl;

      
 
    return 0;
}
