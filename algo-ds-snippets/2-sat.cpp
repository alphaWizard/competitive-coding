    #include <bits/stdc++.h>
    #define MAXN 200005
    #define SIZE (2*MAXN + 1)
    using namespace std;
     
    typedef vector <int> vi;
     
    vi G[SIZE], Grev[SIZE];
    bool explored[SIZE];
    int leader[SIZE], finish[SIZE], order[SIZE], t, parent;
    map <int, bool> truthAssignment;
     
    void dfs_reverse(int i) {
        explored[i] = true;
        for(vi::iterator it = Grev[i].begin(); it != Grev[i].end(); it++)
            if(!explored[*it])
                dfs_reverse(*it);
        t++;
        finish[i] = t;
    }
     
    void dfs(int i) {
        explored[i] = true;
        leader[i] = parent;
        for(vi::iterator it = G[i].begin(); it != G[i].end(); it++)
            if(!explored[*it])
                dfs(*it);
    }
     
    bool stronglyConnected(int u, int v)    {
        return leader[u] == leader[v];
    }
     
    int main()  {
    	int tp;
    	cin>>tp;
    	while(tp--)
    	{
        int i, u, v, N, M;
         scanf("%d %d", &N, &M);
        truthAssignment.clear();
        t=0;parent=0;
        for(int i=0;i<=2*N;++i)
        {
        	G[i].clear();
        	Grev[i].clear();
        	explored[i]=false;
        	leader[i]=0;
        	finish[i]=0;
        	order[i]=0;
        }
     
       // graph assignment 
        for(i=0; i<M; i++)  {
            scanf("%d %d", &u, &v);
                    G[N+u].push_back(v); G[N+v].push_back(u);
                    Grev[v].push_back(N+u); Grev[u].push_back(N+v);
                }
     
         for(int i=1;i<=N/2;++i)
         {
         	int u=2*i-1;
         	int v=2*i;
         	G[N+u].push_back(v); G[N+v].push_back(u);
                    Grev[v].push_back(N+u); Grev[u].push_back(N+v);
                    G[u].push_back(N+v); G[v].push_back(N+u);
                    Grev[N+v].push_back(u); Grev[N+u].push_back(v);
         }        
            
     // till here
         
        memset(explored, false, (2*N + 1)*sizeof(bool));
        for(i=2*N; i>0; i--)  {
            if(!explored[i])
                dfs_reverse(i);
            order[finish[i]] = i;
        }
     
        memset(explored, false, (2*N + 1)*sizeof(bool));
        for(i=2*N; i>0; i--)
            if(!explored[order[i]]) {
                parent = order[i];
                dfs(order[i]);
            }
     
        for(i=2*N; i>0; i--)   {
            u = order[i];
            if(u > N)   {
                if(stronglyConnected(u, u-N)) break;
                if(truthAssignment.find(leader[u]) == truthAssignment.end())    {
                    truthAssignment[leader[u]] = true;
                    truthAssignment[leader[u-N]] = false;
                }
            } else {
                if(stronglyConnected(u, N+u)) break;
                if(truthAssignment.find(leader[u]) == truthAssignment.end())    {
                    truthAssignment[leader[u]] = true;
                    truthAssignment[leader[N+u]] = false;
                }
            }
        }
     
        if(i > 0)
            printf("impossible\n");
        else    {
            printf("possible\n");
            for(i=1; i<=N; i++)
                printf("%d", truthAssignment[leader[i]]);
            printf("\n");
        }
    }
        return 0;
    } 