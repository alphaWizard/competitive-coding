#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
	ll dp[1001][1001]={};//computes ncr for all n in range 1000 (mod 10e7)
    void compute()  //precomputing function
   {
  for(int i=0;i<1001;i++)
	{dp[i][0]=1;dp[0][i]=1;}
	for(int i=1;i<1001;i++)
	for(int j=1;j<1001;j++)
	dp[i][j]=(dp[i-1][j]+dp[i][j-1])%1000000007;
}
        int main() {       
     compute();
	int n,r;cin>>n>>r;
   int result=dp[n-r][r]; //ncr is stored in dp[n-r][r]
    cout<<result;
	 
	
	return 0;
}
