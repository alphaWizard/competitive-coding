#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<ll,ll> arr[30005];
bool toconsider[30005];
ll n;
ll tempo;
ll dist(ll i, ll j)
{
	return (arr[i].first-arr[j].first)*(arr[i].first-arr[j].first) + (arr[i].second-arr[j].second)*(arr[i].second-arr[j].second);
}
ll findmin(ll l, ll r)
{
	if(r-l+1==1)
		return 1e18;
	else if(r-l+1==2)
		return dist(l,r);
	ll x=(l+r)/2;
	ll val=min(findmin(l,x),findmin(x+1,r));
	vector<pair<pair<ll,ll> ,ll > >temp;
	for(ll i=l;i<=r;i++)
	{
		toconsider[i]=false;
		if(arr[i].first>=arr[x].first-val&&arr[i].first<=arr[x].first+val)
			toconsider[i]=true;
	}
	for(ll i=l;i<=r;i++)
	{
		if(toconsider[i])
			temp.push_back(make_pair(make_pair(arr[i].second,arr[i].first),i));
	}
	for(ll i=0;i<temp.size();i++)
	{
		for(ll j=i+1;j<temp.size()&&j<i+8;j++)
		{
			val=min(val,dist(temp[i].second,temp[j].second));
		}
	}
	return val;
}
int main()
{
	ll i,j,k;
	cin>>n;
	tempo=LLONG_MAX;
	for(i=1;i<=n;i++)
	{
		cin>>arr[i].first>>arr[i].second;
	}
	sort(arr+1,arr+n+1);
	ll ans=findmin(1,n);
	cout<<fixed<<setprecision(6);
	cout<<sqrt(ans)<<endl;
	return 0;
}