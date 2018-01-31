#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll ar[1000006];
ll f(ll mid)
{
	ll s=0;
	for(ll i=0;i<n;++i)
	{
		//cout<<ar[i]<<" "<<mid<<endl;
		if(ar[i]>mid) s+=ar[i]-mid;
	}
	//cout<<mid<<" "<<m;
	if(s>=m) return 1;
	return 0;

}

int main()
{

	cin>>n>>m;
	//ll ar[n];
	ll ma=-1;
	for(ll i=0;i<n;++i)
	{
		cin>>ar[i];
		ma=max(ma,ar[i]);
	}
	//cout<<f(10);
	ll lo=0,hi=ma;
	while(hi-lo>1)
	{
		//cout<<lo<<" "<<hi<<endl;
		ll mid=lo+(hi-lo)/2;
		if(f(mid))
			lo=mid;
		else
			hi=mid;


	}
	cout<<lo;
    return 0;
}

