#include<bits/stdc++.h>
using namespace std;

#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define i64 long long

const int INF = 0x7fffffff;
const int MAXN = 5005, MAXE = 200006;

int src, snk, nNode, nEdge;
int Q[MAXN], fin[MAXN], pro[MAXN], dist[MAXN];
int flow[MAXE], cap[MAXE], nex[MAXE], to[MAXE];

inline void init(int _src, int _snk, int _n) {
    src = _src, snk = _snk, nNode = _n, nEdge = 0;
    SET(fin);
}

inline void add(int u, int v, int c) {
    to[nEdge] = v, cap[nEdge] = c, flow[nEdge] = 0, nex[nEdge] = fin[u], fin[u] = nEdge++;
    to[nEdge] = u, cap[nEdge] = 0, flow[nEdge] = 0, nex[nEdge] = fin[v], fin[v] = nEdge++;
}

bool bfs() {
    int st, en, i, u, v;
    SET(dist);
    dist[src] = st = en = 0;
    Q[en++] = src;
    while(st < en) {
        u = Q[st++];
        for(i=fin[u]; i>=0; i=nex[i]) {
            v = to[i];
            if(flow[i] < cap[i] && dist[v]==-1) {
                dist[v] = dist[u]+1;
                Q[en++] = v;
            }
        }
    }
    return dist[snk]!=-1;
}

int dfs(int u, int fl) {
    if(u==snk) return fl;
    for(int &e=pro[u], v, df; e>=0; e=nex[e]) {
        v = to[e];
        if(flow[e] < cap[e] && dist[v]==dist[u]+1) {
            df = dfs(v, min(cap[e]-flow[e], fl));
            if(df>0) {
                flow[e] += df;
                flow[e^1] -= df;
                return df;
            }
        }
    }
    return 0;
}

i64 dinitz() {
    i64 ret = 0;
    int df;
    while(bfs()) {
        for(int i=1; i<=nNode; i++) pro[i] = fin[i];
        while(true) {
            df = dfs(src, INF);
            if(df) ret += (i64)df;
            else break;
        }
    }
    return ret;
}
int dis(pair<int,int> a,pair<int,int> b)
{
    return abs(a.first-b.first)+abs(a.second-b.second);
}

int main() {
  /*  int n, e, u, v, c, i;
    scanf("%d%d", &n, &e);
    init(1, n, n);
    for(i=0; i<e; i++) {
        scanf("%d%d%d", &u, &v, &c);
        if(u!=v) add(u, v, c);
    }
    printf("%lld\n", dinitz());*/

    int t;
    cin>>t;
    while(t--)
    {
        int p,t,s,ti;
        cin>>p>>t>>s>>ti;
        pair<int,int> per[p],taxi[t];
        init(p+t+1,p+t+2,p+t+2);
        for(int i=0;i<p;++i)
        {
            int x,y;cin>>x>>y;
            per[i]={x,y};
            add(p+t+1,i+1,1);
        }
        for(int i=0;i<t;++i)
        {
            int x,y;cin>>x>>y;
            taxi[i]={x,y};
            add(p+i+1,p+t+2,1);
        }
        
        //add()
        for(int i=0;i<p;++i)
        {
            for(int j=0;j<t;++j)
            {
                if(dis(per[i],taxi[j])*200<=s*ti)
                {
                    add(i+1,p+j+1,1);
                }
            }
        }
        printf("%lld\n", dinitz());


    }
    return 0;
}
