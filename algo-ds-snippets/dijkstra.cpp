#include <bits/stdc++.h>
using namespace std;
struct edge { int to, length; };
    void dijkstra( vector< vector<edge> > graph, int source,int min_distance[],int v) {
        
        min_distance[ source ] = 0;
        set< pair<int,int> > active_vertices;
        active_vertices.insert( {0,source} );
            
        while (!active_vertices.empty()) {
            int where = active_vertices.begin()->second;
            active_vertices.erase( active_vertices.begin() );
            for (auto ed : graph[where]) 
                if (min_distance[ed.to] > min_distance[where] + ed.length) {
                    active_vertices.erase( { min_distance[ed.to], ed.to } );
                    min_distance[ed.to] = min_distance[where] + ed.length;
                    active_vertices.insert( { min_distance[ed.to], ed.to } );
                }
           }
        }
int main() {
  int t;cin>>t;
    while(t--)
        {
        int v,e;cin>>v>>e;
        vector<vector<edge>> ve(v);
        
        for(int i=1;i<=e;i++)
            {
            int a,b,c;
            cin>>a>>b>>c;
            edge m1,m2;
            m1.to=b-1;m2.to=a-1;
            m1.length=c;m2.length=c;
            ve[a-1].push_back(m1);
            ve[b-1].push_back(m2);
            }
        int min_distance[v];
        for(int i=0;i<v;i++) min_distance[i]=INT_MAX;
        int src;cin>>src;
        dijkstra(ve,src-1,min_distance,v);
        for(int i=1;(i<=v);i++)
            {
            if(i==src) continue;
            if(min_distance[i-1]!=INT_MAX)
           cout<< min_distance[i-1]<<" ";
            else cout<<-1<<" ";
        }
        cout<<endl;
    }
    return 0;
}
