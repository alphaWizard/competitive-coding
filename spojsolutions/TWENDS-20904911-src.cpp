#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n;
ll ar[1005];
ll dp[1005][1005];
ll f(ll i,ll j)
{
	if(i>j) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	ll a,b;
	if(ar[i+1]>=ar[j])
		a=ar[i]-ar[i+1]+f(i+2,j);
	else a=ar[i]-ar[j]+f(i+1,j-1);
	if(ar[i]>=ar[j-1])
		b=ar[j]-ar[i]+f(i+1,j-1);
	else b=ar[j]-ar[j-1]+f(i,j-2);
	return dp[i][j]=max(a,b);

}

int main(){
	ll t=1;

	while(true){
		cin>>n;
		if(n==0) break;
		for(ll i=0;i<n;++i)
			cin>>ar[i];
		for(ll i=0;i<n;++i)
			for(ll j=0;j<n;++j)
				dp[i][j]=-1;
			ll x=f(0,n-1);
			cout<<"In game "<<t++<<", the greedy strategy might lose by as many as "<<x<<" points."<<endl;


	}
   
    return 0;
}