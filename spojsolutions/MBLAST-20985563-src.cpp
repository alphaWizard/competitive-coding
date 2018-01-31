#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
string s1,s2;
ll n,m,k;
ll dp[2500][2500];
ll f(ll i,ll j)
{
	if(i==n) return (m-j)*k;
	if(j==m) return (n-i)*k;
	if(dp[i][j]!=-1) return dp[i][j];
	if(s1[i]==s2[j]) return dp[i][j]=f(i+1,j+1);
	return dp[i][j]=min(k+min(f(i+1,j),f(i,j+1)),abs(s1[i]-s2[j])+f(i+1,j+1));
}


int main()
{
	cin>>s1>>s2>>k;
	n=s1.length();
	m=s2.length();
	for(ll i=0;i<=n;++i)
		for(ll j=0;j<=m;++j)
			dp[i][j]=-1;
	cout<<f(0,0);
	

    return 0;
}