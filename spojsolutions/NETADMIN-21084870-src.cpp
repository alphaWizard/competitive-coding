#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define i64 long long

const ll INF = 0x7fffffff;
const ll MAXN = 5005, MAXE = 60006;

ll src, snk, nNode, nEdge;
ll Q[MAXN], fin[MAXN], pro[MAXN], dist[MAXN];
ll flow[MAXE], cap[MAXE], nex[MAXE], to[MAXE];

inline void init(ll _src, ll _snk, ll _n) {
    src = _src, snk = _snk, nNode = _n, nEdge = 0;
    SET(fin);
}

inline void add(ll u, ll v, ll c) {  //directed
    to[nEdge] = v, cap[nEdge] = c, flow[nEdge] = 0, nex[nEdge] = fin[u], fin[u] = nEdge++;
    to[nEdge] = u, cap[nEdge] = 0, flow[nEdge] = 0, nex[nEdge] = fin[v], fin[v] = nEdge++;
}
inline void add2(ll u, ll v, ll c) {  //undirected
    to[nEdge] = v, cap[nEdge] = c, flow[nEdge] = 0, nex[nEdge] = fin[u], fin[u] = nEdge++;
    to[nEdge] = u, cap[nEdge] = c, flow[nEdge] = 0, nex[nEdge] = fin[v], fin[v] = nEdge++;
}

bool bfs() {
    ll st, en, i, u, v;
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

ll dfs(ll u, ll fl) {
    if(u==snk) return fl;
    for(ll &e=pro[u], v, df; e>=0; e=nex[e]) {
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
    ll df;
    while(bfs()) {
        for(ll i=1; i<=nNode; i++) pro[i] = fin[i];
        while(true) {
            df = dfs(src, INF);
            if(df) ret += (i64)df;
            else break;
        }
    }
    return ret;
}


// USE 1-INDEXING


int main() {
    ll t;
    cin>>t;
    while(t--)
    {
    	ll n,m,k;
    	cin>>n>>m>>k;
    	ll st;
    	init(1,n+1,n+1);
    	for(ll i=1;i<=k;++i)
    	{
    		ll v;cin>>v;
    		add(v,n+1,1);
    	}
    	for(ll i=1;i<=m;++i)
    	{
    		ll a,b;
    		cin>>a>>b;
    		if(i==1) st=nEdge;
    		add2(a,b,0);
    	}
    	ll perm=st;
    	ll lo=0,hi=k;
    	while(lo<=hi)
    	{
    		ll mid=lo+(hi-lo)/2;
    		for(ll i=1;i<=m;++i)
    		{
    			cap[st++]=mid;
    			cap[st++]=mid;
    		}
    		for(int i=0;i<nEdge;++i)
    			flow[i]=0;
    		if(dinitz()>=k) hi=mid-1;
    		else lo=mid+1;

    		st=perm;
    	}
    	cout<<hi+1<<endl;

    }
    return 0;
}

