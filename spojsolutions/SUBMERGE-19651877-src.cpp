    #include<bits/stdc++.h>
    using namespace std;
 typedef int ll;
    ll t,n,m,k,tim,ch,ans;
    ll disc[100005],low[100005],vis[100005],par[100005],artp[100005];
    vector<ll>v[100005];
    void dfs(ll src)
    {
        ll i,j,ch;
        low[src]=disc[src]=++tim;
        vis[src]=1;
        ll numch=0;
        for(i=0;i<v[src].size();i++)
        {
           ch=v[src][i];
           if(!vis[ch])
           {
               par[ch]=src;
               numch++;
               dfs(ch);
               low[src]=min(low[src],low[ch]);
               if(par[src]==-1&&numch>1)
               artp[src]=1;
               else if(par[src]!=-1&&low[ch]>=disc[src])
               artp[src]=1;
           }
           else
           {
               if(par[src]!=ch)
               {
                   low[src]=min(low[src],disc[ch]);
               }
           }
        }
    }
    int main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        //int t;cin>>t;
        while(5)
        {
        int n,m;
            cin>>n>>m;
            if(n==0&&m==0) break;
            tim=0;
            for(int i=0;i<=n;i++)
            {
                disc[i]=0;
                low[i]=100000;
                v[i].clear();
                vis[i]=0;
                par[i]=-1;
                artp[i]=0;
            }
            for(int i=0;i<m;i++)
            { int x,y;
                cin>>x>>y;
                v[x].push_back(y);
                v[y].push_back(x);
            }
            ans=0;
          dfs(1);
          for(int i=1;i<=n;++i)
          ans+=artp[i];
          cout<<ans<<endl;
          }
          
          
        
        return 0;
    } 