#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=100000000;


bool cmp(pair<int,int> p,pair<int,int> q)
{
    if(p.second!=q.second) return p.second<q.second;
    return p.first<q.first;
}

int main() {


   while(true)
   {
    int n;
    cin>>n;
    if(n==-1) break;
    int a,b;
    int dp[n],s[n];
    vector<pair<int,int> > v;
    for(int i=0;i<n;++i)
    {
        cin>>a>>b;
        v.push_back({a,b});
        dp[i]=1;
        s[i]=0;
    }
    int ans=dp[0];
    s[0]=dp[0];
    vector<int> te;
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n;++i)
    {
        te.push_back(v[i].second);
    }
    int temp=dp[0];
    for(int i=1;i<n;++i)
    {
        int y=v[i].first;
        auto it=upper_bound(te.begin(),te.end(),y)-te.begin()-1;
        //cout<<it<<endl;
        if(it>=0) dp[i]=(dp[i]+s[it])%mod;
        temp=(temp+dp[i])%mod;
        s[i]=temp;
        ans=(ans+dp[i])%mod;
    }


cout<<setfill('0') << setw(8)<<ans<<endl;

   
   }

    return 0;
}
