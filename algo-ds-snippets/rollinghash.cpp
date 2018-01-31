#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int  m =1000000007;
int main()
{
    string s;
    cin>>s;
    ll n=s.length();
    ll h=0;
	ll pro[n+1],hash[n+1];
    pro[0]=1;
    hash[0]=0;
    for(int i=1; i<=n; i++)
        pro[i]=(pro[i-1]*33)%m;
    for(int i=0; i<n; i++)
    {
        h=(h*33+(s[i]-'a' +1 ))%m;
        hash[i+1]=h;
    }
    int t,l1,l2,r1,r2;
    cin>>t;
    while(t--)
    {
        cin>>l1>>r1>>l2>>r2;
        ll hash1=(hash[r1]%m-(hash[l1-1]*pro[r1-l1+1])%m+m)%m;
        ll hash2=(hash[r2]%m-(hash[l2-1]*pro[r2-l2+1])%m+m)%m;
        if(hash1==hash2)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
