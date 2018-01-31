  #include <bits/stdc++.h>
using namespace std;
 typedef long long ll;
 vector <int> adj[2500];
 bool visited[2500];
 int color[2500];

void initialize(int n) {
        for(int i = 0;i<=n;++i)
        {
         visited[i] = false;
        
     color[i]=-1;
     adj[i].clear();
    }
}


bool dfs(int u,int col)
{
	visited[u]=true;
	color[u]=col;
	bool an=true;
	for(auto &v: adj[u])
	{
		if(!visited[v])
		{
			an=an&dfs(v,1-col);
		}
		else
		{
			if(color[v]==color[u])
				return false;
		}
	}
	return an;

}


 
int main()
{
       ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int it=1;
   ll t;
   cin>>t;
  while(t--)
  {
  	int n,m;
  	cin>>n>>m;
  	initialize(n);
  	for(int i=1;i<=m;++i)
  	{
  		int a,b;
  		cin>>a>>b;
  		adj[a].push_back(b);
  		adj[b].push_back(a);

  	}
  	bool res=true;
  	for(int i=1;i<=n;++i)
  	{
  		if(!visited[i])
  		{
  			res=res&dfs(i,0);
  		}
  	}
  	
  	if(!res)
  	{
  		cout<<"Scenario #"<<it++<<":"<<endl;
  		cout<<"Suspicious bugs found!"<<endl;

  	}
  	else
  	{
  		cout<<"Scenario #"<<it++<<":"<<endl;
  		cout<<"No suspicious bugs found!"<<endl;

  	}


  	}


    return 0;
}
    
