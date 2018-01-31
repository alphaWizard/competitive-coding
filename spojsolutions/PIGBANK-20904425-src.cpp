#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll w[520],c[520];
ll dp[520][20000];
ll n;
ll f(ll i,ll s)
{
	if(s<0) return INT_MAX;
	if(s==0) return 0;
	if(i==n-1) {
		if(s%w[i]==0) return c[i]*(s/w[i]);
		else return INT_MAX;
	}
	if(dp[i][s]!=-1) return dp[i][s];
	return dp[i][s]=min(c[i]+f(i,s-w[i]),f(i+1,s));
}

int main(){

	ll t;
	cin>>t;
	while(t--)
	{
		ll a,b;
		cin>>a>>b;
		ll sum=b-a;
		//ll n;
		cin>>n;
		for(ll i=0;i<n;++i)
		{
			cin>>c[i]>>w[i];
			for(ll j=0;j<20000;++j)
				dp[i][j]=-1;
		}
		ll x=f(0,sum);
		if(x>=INT_MAX)
			cout<<"This is impossible."<<endl;
		else cout<<"The minimum amount of money in the piggy-bank is "<<x<<"."<<endl;




	}

   
    return 0;
}