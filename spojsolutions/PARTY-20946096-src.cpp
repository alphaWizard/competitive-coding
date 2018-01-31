#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll mod=1000000007;
ll b,n,costop;
ll cost[104],fun[104];
ll dp[104][600];

ll f(ll i,ll b)
{
	if(b<=0) return 0;
	if(i==-1) return 0;
	if(dp[i][b]!=-1) return dp[i][b];
	ll ai=f(i-1,b);
	ll bi=0;
	if(b>=cost[i])
	bi=f(i-1,b-cost[i])+fun[i];
	if(ai>bi) return dp[i][b]=ai;
	else {
		return dp[i][b]=bi;
	}
}


int main() {
	while(true)
	{
	
	cin>>b>>n;
	if(b==0&&n==0) break;
	costop=0;
	for(ll i=0;i<n;++i)
	{
		cin>>cost[i]>>fun[i];
	}
	memset(dp,-1,sizeof(dp));
	ll res=f(n-1,b);
	ll i;
	for( i=0;i<=b;++i)
	{
		if(f(n-1,i)==res) break;
	}
	cout<<i<<" "<<res<<endl;
}


return 0;
}