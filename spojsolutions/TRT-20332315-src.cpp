#include <bits/stdc++.h>
using namespace std;

int dp[2004][2004];
int ar[2004];
int ans(int i,int j,int k)
{
    if(i>j) return 0;
    if(i==j) return ar[i]*k;
    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j]=max(ar[i]*k+ans(i+1,j,k+1),ar[j]*k+ans(i,j-1,k+1));
}
int main()
{
  int n;
    cin>>n;
    
    for(int i=1;i<=n;++i)
        cin>>ar[i];
    for(int i=0;i<2004;++i)
        for(int j=0;j<2004;++j)
            dp[i][j]=-1;
    cout<<ans(1,n,1);
    
    
  return 0;

}

