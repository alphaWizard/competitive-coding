#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
unordered_map<ll,ll> u;
ll f(ll n)
{
	if(n==0) return 0;
	if(n==1) return 1;
	if(u[n]!=0) return u[n];
	return u[n]=max(n,f(n/2)+f(n/3)+f(n/4));

}
int main()
{
	ll n;
	while(cin>>n)
	{
		cout<<f(n)<<endl;
	}
return 0;

}
