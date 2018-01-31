#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int ar[100005],br[100005],s[100005];
int n;
int dp[100005][5005];

int f(int tot,int cr)
{
    if(tot>=1&&cr==0) return s[tot];
    if(tot-cr<cr) return 1000000009;
    if(dp[tot][cr]!=0) return dp[tot][cr];
    else return dp[tot][cr]=min(ar[tot]+f(tot-1,cr-1),br[tot]+f(tot-1,cr));
    
}

int main()
{
cin>>n;
int temp=0;
for(int i=1;i<=n;++i)
{
    cin>>ar[i]>>br[i];
    temp+=br[i];
    s[i]=temp;
}
//cout<<ar[1]<<endl;
//cout<<br[n]<<endl;
cout<<ar[n]+f(n-1,n/2-1)<<endl;
//cout<<f(2,0);
//f(1,0);
return 0;
}