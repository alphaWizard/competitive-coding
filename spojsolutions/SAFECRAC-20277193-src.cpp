#include <bits/stdc++.h>
using namespace std;

const int mod=1000000007;
int main() {
    
    vector<int> v[10];
    v[0].push_back(7);
    v[1].push_back(4);
       v[1].push_back(2);
       v[2].push_back(1);
       v[2].push_back(3);
       v[2].push_back(5);
       v[3].push_back(2);   v[3].push_back(6);   v[4].push_back(1);   v[4].push_back(5);   v[4].push_back(7);
       v[5].push_back(2);   v[5].push_back(4);   v[5].push_back(6);   v[5].push_back(8);
       v[6].push_back(5);   v[6].push_back(3);   v[6].push_back(9);   v[7].push_back(4);   v[7].push_back(0);
       v[7].push_back(8);   v[8].push_back(7);   v[8].push_back(5);    v[8].push_back(9);
       v[9].push_back(6);   v[9].push_back(8);
    int dp[100005][10];
   for(int i=0;i<=9;++i)
       dp[1][i]=1;
    for(int i=2;i<=100004;++i)
    {
        for(int j=0;j<10;++j)
        {
            int r=0;
            for(int k=0;k<v[j].size();++k )
            {
                r=(r+dp[i-1][v[j][k]])%mod;
            }
            dp[i][j]=r;
        }
    }
    int t;cin>>t;
    while(t--)
    {
    
    int n;
    cin>>n;
        int res=0;
       for(int i=0;i<10;++i)
           res=(res+dp[n][i])%mod;
        cout<<res<<endl;
       
    }
    return 0;
}
