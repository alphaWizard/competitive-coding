#include "bits/stdc++.h"
using namespace std;

const int N = 100000;
vector <int> adj[N + 1];
bool visited[N + 1];
int sz[N + 1];
int level[N+1];
int n;
long long num, den;

void dfs(int u, int d) {
   visited[u] = 1;
   sz[u] = 1;
   for(auto v: adj[u]) {
      if(!visited[v]) {
         dfs(v, d + 1);
         sz[u] += sz[v];
      }
   }
   level[u]=d;
}

int main() {
   cin >> n;

   for(int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }

   dfs(1, 0);
   
  for(int i=1;i<=n;++i)
  {
      cout<<level[i]<<" ";
  }
    cout<<endl;
      for(int i=1;i<=n;++i)
  {
      cout<<sz[i]<<" ";
  }
   return 0;
}
