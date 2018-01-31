
#include <bits/stdc++.h>
using namespace std;

char ar[55][55];
int res[55][55];
void init()
{
    for(int i=0;i<55;++i)
        for(int j=0;j<55;++j)
            res[i][j]=-1;
}
int n,m;

int dfs(int i,int j,int pi,int pj)
{
    if(res[i][j]!=-1) return res[i][j];
    int temp=0;
    int dx[]={-1,-1,-1,1,1,1,0,0};
    int dy[]={1,-1,0,1,-1,0,1,-1};
    for(int u=0;u<8;++u)
    {
        int x=i+dx[u];
        int y=j+dy[u];
        if(x>=0&&x<n&&y>=0&&y<m&&(x!=pi||y!=pj)&&((int)ar[x][y]==ar[i][j]+1))
        {

            temp=max(temp,dfs(x,y,i,j));
        }
    }
    return res[i][j]=1+temp;
}
int main()
{
    int p=1;
    while(cin>>n&&n)
    {
        cin>>m;
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                cin>>ar[i][j];
        init();
        int res=0;
        //dfs(0,1,0,0);
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
            {
                if(ar[i][j]=='A')
                {
                    res=max(res,dfs(i,j,-1,-1));
                   // return 0;
                }
            }
        //cout<<dfs(0,0,-1,-1);
        cout<<"Case "<<p++<<": ";
        cout<<res<<endl;
 
    }
  return 0;

}

