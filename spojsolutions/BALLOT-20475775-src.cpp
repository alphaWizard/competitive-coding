#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll ar[500005];
ll f(ll m)
{
    ll s=0;
    for(ll i=0;i<n;++i)
    {
        s+=ceil((double)ar[i]/(double)m);
    }
    return s;
}

int main()
{
while(true)
{
    cin>>n>>m;if(n==-1) break;
    for(ll i=0;i<n;++i)
        cin>>ar[i];
    ll lo=1,hi=2000001;
    while(lo<hi)
    {
        ll mid=lo+(hi-lo)/2;
        ll a=f(mid);
        if(a<=m) hi=mid;
        else lo=mid+1;
       // if(mid==lo) break;
       // cout<<lo<<" "<<mid<<" "<<hi<<endl;
    }
    cout<<hi<<endl;
    
    
}

	return 0;
} 