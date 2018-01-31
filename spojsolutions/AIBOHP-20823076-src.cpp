#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int dp[6200][6200];
int f(int i,int j)
{
    //cout<<i<<" "<<j<<endl;
    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==s[j]) return dp[i][j]=f(i+1,j-1);
    return dp[i][j]=1+min(f(i,j-1),f(i+1,j));
}



int main() {

int t;cin>>t;

   while(t--)
   {
    cin>>s;

    for(int i=0;i<=s.length();++i)
        {for(int j=0;j<=s.length();++j)
           { dp[i][j]=-1;dp[i][i]=0;}
       }
    cout<<f(0,s.length()-1)<<endl;

   }

    return 0;
}
