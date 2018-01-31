  #include <bits/stdc++.h>
using namespace std;
 typedef long long ll;
ll dp[13][100];

ll f(ll n,ll k)
{
	if(n==1&&k==0) return 1;
	if(n==1&&k!=0) return 0;
	if(k<0) return 0;
	if(n==0&&k>0) return 0;
	if(k==0) return 1;
	if(dp[n][k]!=-1) return dp[n][k];
	ll ans=0;
	for(ll a=0;a<n;++a)
	{
		ans+=f(n-1,k-(n-a-1));
	}
	return dp[n][k]=ans;
}
 
 
int main()
{
       ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   ll t;
   cin>>t;
   for(ll i=0;i<13;++i)
   	for(ll j=0;j<98;++j)
   		dp[i][j]=-1;
   while(t--)
   {
   	ll n,k;
   	cin>>n>>k;
   	cout<<f(n,k)<<endl;

   }
  

    return 0;
}
    
