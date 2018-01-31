#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;cin>>n;
    ll k;
    cin>>k;
    string s;
    cin>>s;
    ll su[n+1];
    ll ans=0ll;
    unordered_map<ll,ll> u;
    su[0]=0ll;
    u[0]++;
    ll ans2=0ll;
    for(ll i=0;i<n;++i)
    {
        su[i+1]=su[i]+s[i]-'0';
        ans2+=u[su[i+1]];
        u[su[i+1]]++;
    }
    if(k!=0)
    {
    for(ll i=0;i<=n;++i)
    {
       ans+= u[su[i]+k];
            
    }
        cout<<ans<<endl;continue;
    }
   cout<<ans2<<endl;
    }
    
return 0;
}