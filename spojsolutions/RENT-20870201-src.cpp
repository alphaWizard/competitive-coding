#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll dp[10005];
ll fin[10005];
vector<pair<pair<ll,ll> ,ll> > v;
bool cmp(pair<pair<ll,ll> ,ll> &a, pair<pair<ll,ll> ,ll> &b)
{
	return a.first.second<b.first.second;
}
ll f(ll i)
{
	if(i==0) return v[i].second;
	if(dp[i]!=-1) return dp[i];
	ll inc=v[i].second;
	auto it=upper_bound(fin,fin+n,v[i].first.first)-fin-1;
	if(it>=0&&it<i) inc+=f(it);
	ll exc=f(i-1);
	return dp[i]=max(inc,exc);

}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		v.clear();
		for(ll i=0;i<n;++i)
		{
			ll a,b,c;
			cin>>a>>b>>c;
			v.push_back({{a,a+b},c});
			dp[i]=-1;
			fin[i]=0;
		}
		sort(v.begin(),v.end(),cmp);
		
		for(ll i=0;i<n;++i)
		{
			fin[i]=v[i].first.second;
		}
		cout<<f(n-1)<<endl;

  
	}
    return 0;
}

