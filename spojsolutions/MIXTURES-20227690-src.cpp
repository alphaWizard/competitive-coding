#include <bits/stdc++.h>
using namespace std;
int ar[103];
int dp[103][103];
int sum[103];
int ans(int i,int j)
{
    if(j==i+1) return ar[i]*ar[j];
    if(i==j) return 0;
  if(j==i+2)
    {
        int we=ar[i];
        int we2=ar[i+1];
        int we3=ar[j];
        return min((we*we2+we3*((we+we2)%100)),(we3*we2+we*((we3+we2)%100)));
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int res=INT_MAX;
    for(int u=i;u<j;++u)
    {
        int x=ans(i,u);
        int m=ans(u+1,j);
        int y=(sum[u+1]-sum[i]+100)%100;
          int z=(sum[j+1]-sum[u+1]+100)%100;
        res=min(res,x+m+y*z);
    }
    return dp[i][j]=res;
}
int main()
{ 
    int n;
    while(cin>>n)
    {
        int temp=0;
        sum[0]=0;
       for(int i=0;i<n;++i)
       {cin>>ar[i];temp=(temp+ar[i])%100;;sum[i+1]=temp%100;}
        for(int i=0;i<103;++i)
            for(int j=0;j<103;++j)
                dp[i][j]=-1;
        cout<<ans(0,n-1)<<endl;
    }
        



    return 0;
}
    