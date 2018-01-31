#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//unordered_map<ll,ll> u;
const ll mod=1000000007;
ll power(ll x, ll  y, ll p)
{
    ll res = 1;     
 
    x = x % p;
 
    while (y > 0)
    {
       
        if (y & 1)
            res = (res*x) % p;
 
     
        y = y>>1; 
        x = (x*x) % p;  
    }
    return res;
}
int main()
{ 
    ll t;cin>>t;
    while(t--)
    {
  ll n;cin>>n;
        if(n==1||n==2||n==3) {cout<<n<<endl;continue;}
       ll x=n/3;
        if(n%3==0) cout<<power(3,x,mod)<<endl;
        else if((n-1)%3==0){cout<<(power(3,(n-1)/3-1,mod)*4)%mod<<endl;}
        else
        {
            {cout<<(power(3,(n-1)/3,mod)*2)%mod<<endl;}
        }
        
    }
    
        

//cout<<m;

    return 0;
}
    