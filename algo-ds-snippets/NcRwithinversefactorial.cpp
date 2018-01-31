#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(long long i=0;i<(n);i++)
#define FOR(i,a,b) for(long long i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define mp make_pair
#define M 1000001
ll mod=1000000007;
ll fact[M+1];
ll inv[M+1];
ll power(ll a, ll b, ll p){
	ll x = 1, y = a;
	while (b > 0){
		if (b%2){
			x = (x*y)%p;
		}
		y = (y*y)%p;
		b /= 2;
	}
	return x%p;
}
ll modular_inverse(ll n){
	return power(n, mod-2, mod);
}	
void fill()
{
	fact[0]=1;
	FOR(i,1,M)
	fact[i]=(fact[i-1]*i)%mod;
	inv[M]=modular_inverse(fact[M]);
	FORD(i,M-1,0)
	inv[i] =(inv[i+1]*1LL*(i+1*1LL))%mod;
}
ll coeff(ll n,ll k)
{
    ll f=fact[n];
    f=(f*inv[k])%mod;
    f=(f*inv[n-k])%mod;
    return f;
}
int main()
{
	fill();
	ll t;cin>>t;
	while(t--)
	{
	ll n,k;
	cin>>n>>k;
	cout<<coeff(n,k);
	}
	return 0;
}