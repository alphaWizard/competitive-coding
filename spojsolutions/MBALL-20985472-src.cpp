#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
 vector<ll> memo(100000+ 7);
long waystosum(ll sum, vector<ll> coins) {
   
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
	vector<ll> v={2,3,6,7,8};
	waystosum(100001,v);

    ll t;
    cin>>t;
    while(t--)
    {
    	ll n;
    	cin>>n;
    	cout<<memo[n]<<endl;
    }
    return 0;
}