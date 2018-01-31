#include <bits/stdc++.h>
using namespace std;
int n,m;
char ma[201][201];
int dp[201][201][2];
int f(int i,int j,int k)
{
	if(i<0||i>=n) return 0;
	if(j<0||j>=m) return 0;
	if(ma[i][j]=='#') return 0;

	if(k==1)
	{
		if(dp[i][j][k]!=-1) return dp[i][j][k];
		int p=0;
		if(ma[i][j]=='T') p++;
		return dp[i][j][k]=p+max(f(i,j+1,1),f(i+1,j,0));
	}
	else
	{
		if(dp[i][j][k]!=-1) return dp[i][j][k];
		int p=0;
		if(ma[i][j]=='T') p++;
		return dp[i][j][k]=p+max(f(i,j-1,0),f(i+1,j,1));
	}
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				cin>>ma[i][j];
				dp[i][j][0]=-1;
				dp[i][j][1]=-1;
			}
		}
		cout<<f(0,0,1)<<endl;


	}
    
    
      
    return 0;
}

