#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll waystosum(ll sum, vector<ll> coins) {
    vector<long> memo(sum + 1);
    memo[0] = 1;
    for (auto &coin : coins) {
        for (ll i = coin; i <= sum; i++) {
            memo[i] += memo[i-coin];
        }
    }
    return memo[sum];
}

int main()
{
	ll s;cin>>s;
	ll n;
	cin>>n;
	vector<ll> v;ll su=0;
	for(ll i=0;i<n;++i)
	{
		ll a;
		cin>>a;su+=a;
		v.push_back(su);
	}
	if(waystosum(s,v)>0) cout<<"YES";
	else cout<<"NO";
	//cout<<waystosum(13,v);
    return 0;
}