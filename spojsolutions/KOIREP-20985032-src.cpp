#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
	ll n,m;
	cin>>n>>m;
	vector<pair<ll,ll> > v;
	for(ll i=0;i<n;++i)
	{
		for(ll j=0;j<m;++j)
		{
			ll u;cin>>u;
			v.push_back({u,i});
		}
	}
	sort(v.begin(),v.end());
	// for(ll i=0;i<n*m;++i)
	// {
		
	// 		cout<<v[i].second<<" ";
	
	// }
	ll i=0,j=0;
	ll mi=INT_MAX;
	int cnt[n+1]={0};
	int check = 1;
	cnt[v[0].second]=1;
	while(i<n*m&&j<n*m)
	{
		if(check==n)
		{
			mi=min(mi,v[j].first-v[i].first);
			cnt[v[i].second]--;
			if(cnt[v[i].second]==0) check--;
			i++;
		}
		else
		{
			j++;
			if(j==n*m) break;
			cnt[v[j].second]++;
			if(cnt[v[j].second]==1) check++;
			

		}

	}
	cout<<mi<<endl;
return 0;
}
 