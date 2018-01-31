#include<bits/stdc++.h>
using namespace std;
char ma[101][101];
bool vis[101][101];
//int in;
 string s="ALLIZZWELL";
 int n,m;
int res;
bool isvalid(int i,int j)
{
    return (i>=0&&i<n&&j>=0&&j<m);
}
void init()
{
    //in=0;
   for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
            { vis[i][j]=false;}
}
void dfs(int i,int j,int in)
{
    vis[i][j]=true;
    if(in==9) {res=1;return;}
    int dx[]={-1,-1,-1,1,1,1,0,0};
    int dy[]={0,1,-1,0,-1,1,1,-1};
    for(int u=0;u<8;u++)
    {
        int x=i+dx[u];
        int y=j+dy[u];
        if(isvalid(x,y) && !vis[x][y] && ma[x][y]==s[in+1])
        {    dfs(x,y,in+1);}
    }
       vis[i][j]=false;
}
int main()
{
int t;cin>>t;
    while(t--)
    {
       res=0;
        cin>>n>>m;
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
            { cin>>ma[i][j];vis[i][j]=false;}
       int fg=0;
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
            {
                if(ma[i][j]=='A') {init();dfs(i,j,0);if(res==1) {fg=1;break;}}
            }
        
        //cout<<in;
        if(fg) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
return 0;
}



