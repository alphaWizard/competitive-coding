#include<bits/stdc++.h>
using namespace std;
int n,k;
int ar[105];
int dp[105][105];
const int inf=1000000000;

int f(int i,int j)
{
   if(i>n) return inf;
   if(j>k) return inf;
   if(j==k&&i<=n) return 0;
   if(dp[i][j]<inf) return dp[i][j];
   for(int u=1;u<=k;++u)
   {
    if(ar[u]!=-1)
        dp[i][j]=min(dp[i][j],ar[u]+f(i+1,j+u));
   } 
   return dp[i][j];

}

int main() {
  

    int t;
    cin>>t;
    while(t--)
    {
       cin>>n>>k;
       for(int i=1;i<=k;++i)
        cin>>ar[i];
    if(k==0) {cout<<0<<endl;continue;}
    //cout<<f(5,k);
    for(int i=0;i<105;++i)
    {
        for(int j=0;j<105;++j)
        {
            dp[i][j]=1000000000;
        }
    }
    int x=f(0,0);
    if(x>=inf) cout<<-1<<endl;
        else
    cout<<x<<endl;

    }
    return 0;
}
