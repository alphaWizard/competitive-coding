 #include <bits/stdc++.h>
using namespace std;
 typedef long long ll;

int main()
{
   ll t;
   cin>>t;
  while(t--)
  {

  	int n;
  	cin>>n;
  	unordered_map<string,bool> u;
  	int fuck=0;
  	string ar[n];
  	for(int i=0;i<n;++i)
  		cin>>ar[i];
  	sort(ar,ar+n);

  	string s;
  	for(int i=1;i<=n;++i)
  	{
  		s=ar[i-1];
  		string tp="";
  		for(int j=0;j<s.length();++j)
  		{
  			tp+=s[j];
  			if(u.find(tp)!=u.end()) fuck=1;

  		}
  		u[s]=true;
  		


  	}
  	if(fuck) cout<<"NO"<<endl;
  	else cout<<"YES"<<endl;

  }
  	return 0;
}
    
