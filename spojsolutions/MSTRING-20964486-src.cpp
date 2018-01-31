#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s,t;int n,m;
int dp[1005][1005];
int f(int i,int j)
{
	if(i>=n) return 2000;
	if(j>=m) return 1;
	if(dp[i][j]!=-1) return dp[i][j];
	bool res=false;
	int u;
	for(u=j;u<m;++u)
		{if(t[u]==s[i]) {res=true;break;}}
	if(!res) return dp[i][j]=1;
	return dp[i][j]=min(1+f(i+1,u+1),f(i+1,j));


}
int main() {
 
  cin>>s>>t;
  n=s.length();
  m=t.length();
  for(int i=0;i<1005;++i)
  	for(int j=0;j<1005;++j)
  		dp[i][j]=-1;
  	cout<<f(0,0);

    return 0;
}
