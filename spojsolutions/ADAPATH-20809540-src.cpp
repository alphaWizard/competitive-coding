#include<bits/stdc++.h>
using namespace std;

#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define ll long long

const ll INF = 0x7fffffff;
const ll MAXN = 30080, MAXE = 2000006;

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

ll dinitz() {
    ll ret = 0;
    ll df;
    while(bfs()) {
        for(ll i=1; i<=nNode; i++) pro[i] = fin[i];
        while(true) {
            df = dfs(src, INF);
            if(df) ret += (ll)df;
            else break;
        }
    }
    return ret;
}

int main() {
  /*  ll n, e, u, v, c, i;
    scanf("%d%d", &n, &e);
    init(1, n, n);
    for(i=0; i<e; i++) {
        scanf("%d%d%d", &u, &v, &c);
        if(u!=v) add(u, v, c);
    }
    printf("%lld\n", dinitz());*/

    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        init(2*n*n+1,2*n*n+2,2*n*n+2);
        ll ar[n+1][n+1];
        int ct=0;
        for(ll i=1;i<=n;++i)
        {
            for(ll j=1;j<=n;++j)
            {
                cin>>ar[i][j];
                if(ar[i][j]==1)
                {
                    ct++;
                }
                add(n*n+n*(i-1)+j,2*n*n+2,1);
                add(2*n*n+1,n*(i-1)+j,1);
            }
        }
        ll dx[]={-1,1,0,0};
        ll dy[]={0,0,1,-1};
        for(ll i=1;i<=n;++i)
        {
            for(ll j=1;j<=n;++j)
            {
                for(ll k=0;k<4;++k)
                {
                    ll x=i+dx[k];
                    ll y=j+dy[k];
                    if(x>=1&&y>=1&&x<=n&&y<=n&&ar[x][y]==ar[i][j]+1)
                    {
                        add(n*(i-1)+j,n*n+n*(x-1)+y,1);
                    }
                }
            }
        }
       // printf("%lld\n", dinitz());
       if(n*n-dinitz()==ct) cout<<"YES"<<endl;
       else cout<<"NO"<<endl;

    }
    return 0;
}
