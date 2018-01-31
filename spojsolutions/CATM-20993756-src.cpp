#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	int n,m;
	cin>>n>>m;
	int t;
	cin>>t;
	while(t--)
	{
		int ma,mb,a,b,c,d;
		cin>>ma>>mb>>a>>b>>c>>d;
		int res=0;
		for(int i=1;i<=n;++i)  
		{
			int j=1;
			int ms=abs(ma-i)+abs(mb-j);
			int cs=min(abs(a-i)+abs(b-j),abs(c-i)+abs(d-j));
			if(ms<cs) {res=1;break;}
		}
		for(int i=1;i<=n;++i)  
		{
			int j=m;
			int ms=abs(ma-i)+abs(mb-j);
			int cs=min(abs(a-i)+abs(b-j),abs(c-i)+abs(d-j));
			if(ms<cs) {res=1;break;}
		}
		for(int j=1;j<=m;++j)  
		{
			int i=1;
			int ms=abs(ma-i)+abs(mb-j);
			int cs=min(abs(a-i)+abs(b-j),abs(c-i)+abs(d-j));
			if(ms<cs) {res=1;break;}
		}
		for(int j=1;j<=m;++j)  
		{
			int i=n;
			int ms=abs(ma-i)+abs(mb-j);
			int cs=min(abs(a-i)+abs(b-j),abs(c-i)+abs(d-j));
			if(ms<cs) {res=1;break;}
		}
		if(res==1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}