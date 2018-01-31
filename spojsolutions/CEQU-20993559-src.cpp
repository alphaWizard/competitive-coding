#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	int p=1;
	int t;
	cin>>t;
	while(t--)
	{
		
		int a,b,c;
		cin>>a>>b>>c;
		cout<<"Case "<<p++<<": ";
		if(c%__gcd(a,b)==0) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}