#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;


int main()
{ 
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;cin>>n;
  ll a[n],b[n],c[n],d[n];
    unordered_map<ll,ll> u;
    u.reserve(16000000);
    for(ll i=0;i<n;++i)
    {
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    for(ll i=0;i<n;++i)
    {
        for(ll j=0;j<n;++j)
        {
            u[a[i]+b[j]]++;
        }
            
    }
    ll res=0;
     for(ll i=0;i<n;++i)
    {
        for(ll j=0;j<n;++j)
        {
           ll temp=-(c[i]+d[j]);
             if (u.find(temp) != u.end())
            res+=u[temp];
        }
            
    }
    cout<<res;
    
    

    return 0;
}
    