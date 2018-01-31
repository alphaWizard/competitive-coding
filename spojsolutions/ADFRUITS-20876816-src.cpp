#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b;
string ans;
string dp[105][105];
string f(int i,int j)
{
	if(i==-1) return b.substr(0,j+1);
	if(j==-1) return a.substr(0,i+1);
    if(dp[i][j]!="12") return dp[i][j];
	if(a[i]==b[j])
	{
		return f(i-1,j-1)+a[i];
	}
	else
	{
		string x=f(i,j-1);
		string y=f(i-1,j);
		if(x.length()<y.length())
			{return dp[i][j]=x+b[j];}
		else {return dp[i][j]=y+a[i];}


	}
}


int main()
{
	while(cin>>a&&cin>>b)
	{
		ans="";
        for(int i=0;i<105;++i)
        {
            for(int j=0;j<105;++j)
            {
                dp[i][j]="12";
            }
        }
		cout<<f(a.length()-1,b.length()-1)<<endl;
		//cout<<ans<<endl;

	}
    return 0;

}
