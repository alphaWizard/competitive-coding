#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[100005][12];
vector<ll> v(100005);
 ll s1[100005],s2[100005];
ll pointer; 
vector<long long> M; 
vector<long long> B;

bool bad(ll l1,ll l2,ll l3)
{
    return (B[l3]-B[l1])*(M[l1]-M[l2])<(B[l2]-B[l1])*(M[l1]-M[l3]);
}
void add(long long m,long long b)
{
    M.push_back(m);
    B.push_back(b);
    while (M.size()>=3&&bad(M.size()-3,M.size()-2,M.size()-1))
    {
        M.erase(M.end()-2);
        B.erase(B.end()-2);
    }
}
long long query(long long x)
{
    if (pointer>=M.size())
        pointer=M.size()-1;
    while (pointer<M.size()-1&&
      M[pointer+1]*x+B[pointer+1]<M[pointer]*x+B[pointer])
        pointer++;
    return M[pointer]*x+B[pointer];
}    

    

int main() {
   
ll n,k;
    cin>>n>>k;
    for(ll i=n;i>=1;--i)
    {
         cin>>v[i];
    }
    for(ll i=1;i<=n;++i)
    {
        //cin>>v[i].first>>v[i].second;
        s1[i]+=s1[i-1]+v[i];
        s2[i]+=s2[i-1]+v[i]*i;
        
    }
    for(ll u=1;u<=n;++u) {dp[u][0]=0;dp[u][1]=s1[u]*u-s2[u];}
    for(ll kk=2;kk<=k;++kk)
    {
        M.clear();B.clear(); pointer=0;
        add(-s1[0],s2[0]);
        for(ll i=1;i<=n;++i)
        {
            dp[i][kk]=query(i)+s1[i]*i-s2[i];
            add(-s1[i],dp[i][kk-1]+s2[i]);
        }
        
    }
    cout<<dp[n][k];
    
    return 0;
}