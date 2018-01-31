#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ar[101][101],dp[101][101];
int n,m;
const int dx[]={1,1,1};
const int dy[]={-1,0,1};
int f(int i,int j)
{
    if(i==n-1)
        return ar[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int an=-1;
    for(int u=0;u<3;++u)
    {
        int x=i+dx[u];
        int y=j+dy[u];
        if(x>=0&&x<n&&y>=0&&y<m)
        {
            an=max(an,f(x,y));
        }
    }
    return dp[i][j]=ar[i][j]+an;

}

int main() {

   int t;
   cin>>t;
   while(t--)
   {
   // int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            dp[i][j]=-1;
            cin>>ar[i][j];
        }
    }
    int an=-1;
    for(int j=0;j<m;++j)
    {
        an=max(an,f(0,j));
    }
    cout<<an<<endl;

   }

    return 0;
}
