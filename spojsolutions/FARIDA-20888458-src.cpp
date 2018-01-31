  #include <bits/stdc++.h>
using namespace std;
 typedef long long ll;
ll ar[10005];
ll dp[10005];
ll n;
ll f(ll i)
{
	if(i>=n) return 0;
	//if(i==n-1) return ar[i];
	if(dp[i]!=-1) return dp[i];
	ll ans=0;
		ans=max(ar[i]+f(i+2),f(i+1));
		return dp[i]=ans;
}


 
int main()
{
       ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   ll t;
   ll it=1;
   cin>>t;
  while(t--)
  {
  	//ll n;
  	cin>>n;
  	
  	for(ll i=0;i<n;++i)
  		{
  			cin>>ar[i];
  			dp[i]=-1;
  		
  		}
  		ll a=f(0);
  		cout<<"Case "<<it++<<": ";
  		cout<<a<<endl;
  	}


    return 0;
}
    
