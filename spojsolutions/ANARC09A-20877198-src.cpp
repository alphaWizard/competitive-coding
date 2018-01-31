#include <bits/stdc++.h>
using namespace std;


int main()
{
int cs=1;
	while(true)
	{
		string s;
		cin>>s;
		if(s[0]=='-') break;
		int n=s.length();
		int a=0,ans=0;
	for(int i=0; i<n; i++)
    {
    if(s[i]=='{') a++;
    if(s[i]=='}') a--;
    if(a<0) { ans++; a+=2; }
    if(a>=n-i) { ans++; a-=2; }
    }
    cout<<cs++<<". "<<ans<<endl;

	}
    return 0;

}
