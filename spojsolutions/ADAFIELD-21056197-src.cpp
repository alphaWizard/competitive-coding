#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m,k;
		cin>>n>>m>>k;
		set <ll> s1,s2; //lines
		multiset<ll , greater<ll> >  ar,br; //interval
		s1.insert(0);s1.insert(n);
		s2.insert(0);s2.insert(m);
		ar.insert(n);br.insert(m);
		for(ll i=0;i<k;++i)
		{
			ll a,b;
			cin>>a>>b;
			if(a==0)
			{
				auto it=s1.upper_bound(b);
				auto it2=it--;
				if(*it!=b) 
				{
					s1.insert(b);
					ll gap=*it2 - *it;
					auto it3=ar.find(gap);
					ar.erase(it3);
					ar.insert(*it2-b);
					ar.insert(b-*it);
				}

			}
			else
			{
				//auto it=upper_bound(s2.begin(),s2.end(),b);
				auto it=s2.upper_bound(b);
				auto it2=it--;
				if(*it!=b) 
				{
					s2.insert(b);
					ll gap=*it2 - *it;
					auto it3=br.find(gap);
					br.erase(it3);
					br.insert(*it2-b);
					br.insert(b-*it);
				}
			}
			cout<<*ar.begin()* *br.begin()<<endl;

		}

	}

return 0;
}
