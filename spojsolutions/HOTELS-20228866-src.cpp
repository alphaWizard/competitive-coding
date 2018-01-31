#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;


int main()
{ 
 ll n,m;
    cin>>n>>m;
    ll ar[n+1];
    for(ll i=1;i<=n;++i)
        cin>>ar[i];
    ll sum=0;
    ll res=0;
    int low=1;
     for(int i=1;i<=n;++i)
     {
         sum+=ar[i];
         while(sum>m)
         {
             sum-=ar[low];
             low++;
             if(sum>=res&&sum<=m) {res=sum;break;}
             
         }
         if(sum>=res&&sum<=m) res=sum;
     }
    cout<<res;

    return 0;
}
    