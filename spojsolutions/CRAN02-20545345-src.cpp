#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
cout.tie(NULL);
ll t;
cin>>t;
while(t--)
{
	ll n;
	cin>>n;
	unordered_map<ll,ll> u;
	ll ar[n];
	ll s[n+1];
	s[0]=0;

	for( ll i=0;i<n;++i)
	{
		cin>>ar[i];
	}
	for(int i=0;i<n;++i)
	{
		s[i+1]=s[i]+ar[i];
	}
	ll ans=0;
	for(int i=0;i<=n;++i)
	{
        ans+=u[s[i]];
		u[s[i]]++;
		
	}
	cout<<ans<<endl;
}
return 0;





}