#include <bits/stdc++.h>
   #include <vector>
    using namespace std;
typedef long long ll;

ll ar[100005];
ll dp[100005];

ll f(ll n)
{
    //cout<<ar[n];
    if(n<1) return 0;
    if(n==1) return ar[1];
    if(n==2) return ar[1]+ar[2];
    if(n==3) return ar[1]+ar[2]+ar[3];
    if(dp[n]!=0) return dp[n];
    ll a=ar[n]+f(n-2) ;
    ll b=ar[n]+ar[n-1]+f(n-4);
    ll c=ar[n]+ar[n-1]+ar[n-2]+f(n-6);
    //cout<<a<<" "<<b<<" "<<c<<" "<<endl;
    return dp[n]=max(a,max(b,c));
    
}
    int main() { 
        ll t;
        cin>>t;
        while(t--)
        {
         ll n;cin>>n;
            ar[0]=0;
            for(ll i=1;i<=n;++i)
            {
                cin>>ar[i];
                dp[i]=0;
            }
            for(ll i=1;i<=n/2;++i)
            {
                swap(ar[i],ar[n-i+1]);
            }

            cout<<f(n)<<endl;
            
        }
      
     
        return 0;
}