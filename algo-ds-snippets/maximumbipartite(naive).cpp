#include<bits/stdc++.h>  //naive dfs implementation of maximum bipartite matching
using namespace std;
vector<int> adj[2009];
bool mark[2009];
int match[2009];
void init()
{
    for(int i=0; i<2009; ++i)
    {
        match[i]=-1;
        adj[i].clear();
    }
}
bool dfs(int v) { // v is in X, it reaturns true if and only if there is an augmenting path starting from v
    if(mark[v])
        return false;
    mark[v] = true;
    for(auto &u : adj[v])
        if(match[u] == -1 or dfs(match[u])) // match[i] = the vertex i is matched with in the current matching, initially -1
            return match[v] = u, match[u] = v, true;
    return false;
}

int main()
{

    init();
    unordered_map<int,int> mx,my;
    set<int> s;
    int n,m;
    cin>>n>>m;
    int p=1;
    for(int i=0; i<m; ++i)
    {
        int a,b;
        cin>>a>>b;
        if(mx[a]==0) {
            mx[a]=p;
            ++p;
        }
        if(my[b]==0) {
            my[b]=p;
            ++p;
        }
        s.insert(mx[a]);
        adj[mx[a]].push_back(my[b]);
    }
    int ct=0;
    for(auto &i:s)
    {
        memset(mark, false, sizeof mark);
        if(dfs(i)) ct++;
    }
    cout<<ct<<endl;   //ct=maximum bipartite matching

    return 0;
}
