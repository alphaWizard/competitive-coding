#include <iostream>
using namespace std;

bool isvalid(int x,int y)
{
    if((x==1&&y<=9)||(x==2&&y<=6)) return true;
    return false;
}
int main()
{
 
   
    while(true)
    {
   string s;
        cin>>s;
        if(s=="0") break;
        int l=s.length();
        int dp[l+1];
        for(int i=0;i<=l;++i)
            dp[i]=0;
        dp[0]=0;
        dp[1]=1;
        for(int i=1;i<l;++i)
        {
           int x=s[i-1]-'0';
            int y=s[i]-'0';
            if(dp[i]==0) {dp[i+1]=0;continue;}
            if(x==y&&y==0) {dp[i+1]=0; continue;}
            int u=0;
            if(y!=0) u=dp[i];
                int v= 0;
                    if(isvalid(x,y)) v=max(1,dp[i-1]);
            dp[i+1]=u+v;
            
        }
        cout<<dp[l]<<endl;
        }
    return 0;
}