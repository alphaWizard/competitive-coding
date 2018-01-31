#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;


int main() {
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;ll b;
		ll ps=0,s=0;
		for(ll i=0;i<n;++i)
		{
			cin>>b;
			s+=i*b-ps;
			ps+=b;
		}
		cout<<s<<endl;
	}
return 0;
}