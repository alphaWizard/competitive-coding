#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 ll ar[10005],cost[10005];
ll n;
ll f(ll v)
{
   ll s=0;
    for(ll i=0;i<n;++i)
    {
        s+=cost[i]*abs(ar[i]-v);
    }
    return s;
}
int main()
{
   ll t;cin>>t;
    while(t--)
    {
       cin>>n;
        for(ll i=0;i<n;++i)
            cin>>ar[i];
        for(ll i=0;i<n;++i)
            cin>>cost[i];
       ll lo=0,hi=10000;
        while(lo<hi)
        {
            ll mid=lo+(hi-lo)/2;
            ll a=f(mid);
            ll b=f(mid+1);
           
            if(a<b) hi=mid;
            else lo=mid+1;
           // cout<<lo<<" "<<hi<<endl;
        }
        //cout<<hi<<endl;
        cout<<f(hi)<<endl;
       // cout<<f(2)<<" "<<f(3);
    }

	return 0;
} 