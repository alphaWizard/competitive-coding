#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,m;
int mat[502][502];
int dp[502][502];

int f(int i,int j)
{
	if(i==n-1&&j==m-1) return 1;
	if(dp[i][j]!=-1) return dp[i][j];
	if(i==n-1) return dp[i][j]=max(1,f(i,j+1)-mat[i][j]);
	if(j==m-1) return dp[i][j]=max(1,f(i+1,j)-mat[i][j]);
	return dp[i][j]=max(1,min(f(i+1,j)-mat[i][j],f(i,j+1)-mat[i][j]));
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		
		cin>>n>>m;
		for(int i=0;i<n;++i)
			{
				for(int j=0;j<m;++j)
				{
					cin>>mat[i][j];
					dp[i][j]=-1;
				}
			}
			cout<<f(0,0)<<endl;
	}
	
	return 0;
}