#include<bits/stdc++.h>
using namespace std;
char ma[190][190];
int dist[190][190];
  int n; int m;
void bfs()
{
    queue<pair<int,int> > q;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(ma[i][j]=='1')
            { q.push({i,j});dist[i][j]=0;}
        }
    }
    //cout<<dist[0][1];cout<<i<<" "<<j<<endl;
    while(!q.empty())
    {
        pair <int,int> t=q.front();
        int x=t.first;
        int y=t.second;
        q.pop();
        int dx[]={-1,1,0,0};
        int dy[]={0,0,1,-1};
        for(int i=0;i<4;++i)
        {
            int newx=x+dx[i];
            int newy=y+dy[i];
            if(newx>=0&&newx<n&&newy>=0&&newy<m&&dist[newx][newy]==190*190*19)
            {
                dist[newx][newy]=dist[x][y]+1;
                q.push({newx,newy});
            }
        }
    }
        
}
int main()
{
  int t;
    cin>>t;
    while(t--)
    {
       
        cin>>n;
       
        cin>>m;
       // int ma[n][m];
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
            { cin>>ma[i][j];dist[i][j]=190*190*19;}
        bfs();
        for(int i=0;i<n;++i){
        {for(int j=0;j<m;++j)
                cout<<dist[i][j]<<" ";}
        cout<<endl;}
        cout<<endl;
        
    }
    return 0;
}