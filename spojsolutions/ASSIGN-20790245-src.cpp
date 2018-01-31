#include <bits/stdc++.h>
using namespace std;
#define ll long long



int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ma[n][n];
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                cin>>ma[i][j];
            }
        }
        ll dp[(1<<n)]={0};
        dp[0]=1;
        for(ll i=0;i<(1<<n);++i)
        {
           ll ct=__builtin_popcount(i);
            for(int j=0;j<n;++j)
            {
                if(ma[ct][j]==1&& (i&(1<<j))==0 )
                {
                    dp[i|((1<<j))]+=dp[i];
                }
            }
        }
        cout<<dp[(1<<n)-1]<<endl;
    }
    

    
    return 0;
}
