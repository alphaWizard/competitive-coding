#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;


int main()
{ 
 ll n,m;
    cin>>n>>m;
   int ar[n];
    for(int i=0;i<n;++i)
        cin>>ar[i];
    sort(ar,ar+n);
    int p=0;
    for(int i=0;i<n;++i)
    {
        if(binary_search(ar,ar+n,ar[i]+m)) p++;
    }
    cout<<p;
    
    return 0;
}