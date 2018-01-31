 #include <bits/stdc++.h>
using namespace std;
 typedef long long ll;
ll power(ll x,  ll y, ll p)
{
ll res = 1;  
 x = x % p;  
 while (y > 0)
    { if (y & 1)
      res = (res*x) % p;
        y = y>>1; 
        x = (x*x) % p;  
    }
    return res;}
 
int main()
{
   ll t;
   cin>>t;
  while(t--)
  {
  	ll a,b;
  	cin>>a>>b;
  	ll x=power(a,b,10);
  	cout<<x<<endl;
  	}
  	return 0;
}
    
