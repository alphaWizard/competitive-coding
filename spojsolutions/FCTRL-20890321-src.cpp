  #include <bits/stdc++.h>
using namespace std;
 typedef long long ll;

 
int main()
{
       ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   ll t;
   cin>>t;
  while(t--)
  {
  	ll n;
  	cin>>n;
  	ll ans=0;
  	ll p=5;
  	while(n/p>0)
  	{
  		ans+=n/p;
  		p=p*5;

  	}
  	cout<<ans<<endl;
  	

  	}


    return 0;
}
    
