#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;

bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.second!=b.second) return a.second<b.second;
    return a.first>b.first;
}
int main()
{ 
int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<pair<int,int>> v;
        for(int i=0;i<n;++i)
        {
            int a,b;cin>>a>>b;v.push_back({a,b});
        }
        sort(v.begin(),v.end(),cmp);
        int lst=0,res=1;
        for(int i=1;i<n;++i)
        {
            if(v[i].first>=v[lst].second){res++;lst=i;}
        }
        cout<<res<<endl;
    }
    return 0;
}
    