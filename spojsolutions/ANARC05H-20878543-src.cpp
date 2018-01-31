#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
string s;
ll dp[30][3000];
ll sum[30];
ll f(ll i,ll su)
{
	ll temp=0;
	ll res=0;
	if(i==0) return s[0]-'0'<=su;
	if(dp[i][su]!=-1) return dp[i][su];
	for(ll j=i;j>=1;--j)
	{
		temp+=s[j]-'0';
		if(temp>su) break;
		res+=f(j-1,temp);


	}

	return dp[i][su]=(sum[i]<=su)+res;
}
int main()
{
	int ct=1;
	while(true)
	{
		
		cin>>s;
		if(s=="bye") break;
		ll n=s.length();
		ll su=0;

		for(ll i=0;i<n;++i)
		{
			su+=s[i]-'0';
			sum[i]=su;
		}
		for(ll i=0;i<30;++i)
		{
			for(ll j=0;j<3000;++j)
			{
				dp[i][j]=-1;
			}
		}
		cout<<ct++<<". ";
		cout<<f(n-1,su)<<endl;
	}
return 0;

}
