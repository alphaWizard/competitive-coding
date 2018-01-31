#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define i64 long long

const ll INF = 0x7fffffff;
const ll MAXN = 55005;
const ll MAXE = 310000;

ll src, snk, nNode, nEdge;
ll Q[MAXN], fin[MAXN], pro[MAXN], dist[MAXN];
ll flow[MAXE], cap[MAXE], nex[MAXE], to[MAXE];

inline void init(ll _src, ll _snk, ll _n) {
    src = _src, snk = _snk, nNode = _n, nEdge = 0;
    SET(fin);
}

inline void add(ll u, ll v, ll c) {
    to[nEdge] = v, cap[nEdge] = c, flow[nEdge] = 0, nex[nEdge] = fin[u], fin[u] = nEdge++;
    to[nEdge] = u, cap[nEdge] = 0, flow[nEdge] = 0, nex[nEdge] = fin[v], fin[v] = nEdge++;
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
		ll n,m;
		cin>>n>>m;
		init(n+m+1,n+m+2,n+m+2);
		for(ll i=1;i<=n;++i)
		{
			ll a;cin>>a;
			add(n+m+1,i,a);
		}
		ll ans=0;
		for(ll i=1;i<=m;++i)
		{
			ll u,v,w;
			cin>>u>>v>>w;
			ans+=w;
			add(n+i,n+m+2,w);
			add(u,n+i,INF);
			add(v,n+i,INF);

		}
		cout<<ans-dinitz()<<endl;


	}
	return 0;
}