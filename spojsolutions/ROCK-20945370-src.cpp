#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
int n;
string s;
int dp[300][300];

int f(int i,int j)
{
	//if(i>j) return 0;
	//if(i==j) return s[i]=='1';
	if(dp[i][j]!=-1) return dp[i][j];
	int ct=0;
	for(int u=i;u<=j;++u)
	{
		if(s[u]=='1') ct++;
	}
	if(2*ct>j-i+1) return dp[i][j]=j-i+1;
	int ret=0;
	for(int u=i;u<j;++u)
	{
		ret=max(ret,f(i,u)+f(u+1,j));
	}
	return dp[i][j]=ret;
}

int main() {
	ll t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>s;
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				dp[i][j]=-1;
			cout<<f(0,n-1)<<endl;
		
	}
return 0;
}