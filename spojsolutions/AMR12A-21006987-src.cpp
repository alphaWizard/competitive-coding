#include<bits/stdc++.h>
using namespace std;

#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define i64 long long

const int INF = 0x7fffffff;
const int MAXN = 5005, MAXE = 600006;

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


// USE 1-INDEXING


int main() {
	int t;
	cin>>t;
	while(t--)
	{


    // int n, e, u, v, c, i;
    // scanf("%d%d", &n, &e);
    // init(1, n, n);
    // for(i=0; i<e; i++) {
    //     scanf("%d%d%d", &u, &v, &c);
    //     if(u!=v) add(u, v, c);
    // }
    // printf("%lld\n", dinitz());




	int n,m,k,c;
	cin>>n>>m>>k>>c;
	int mat[n+1][m+1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>mat[i][j];

	int lo=0,hi=2000000000;
	int src=n+2*m+1;

	while(lo<=hi)
	{
		int mid = (lo + hi) >> 1;
		init(src, src+1, src+1);
		for(int i=1;i<=n;++i)
		{
			add(src,i,1);
			for(int j=1;j<=m;++j)
			{
				if(mat[i][j]<=mid)
					add(i,n+j,1);
				if(mat[i][j]+c<=mid)
					add(i,n+m+j,1);
			}
		}
		for(int j=1;j<=m;++j)
		{
			add(n+j,src+1,1);
			add(n+m+j,src+1,1);
		}
		if(dinitz()>=k) hi=mid-1;
		else lo=mid+1;

	}
	cout<<hi+1<<endl;

	}	
    return 0;
}
