#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		map<string,int> u;
		for(int i=0;i<n;++i)
		{
			string temp="";
			for(int j=0;j<6;++j)
			{
				string tr;
				cin>>tr;
				temp+=tr;
				temp+=' ';
			}
			if(u.find(temp)==u.end()){u.insert({temp,1});}
			else u[temp]++;
		}
		for(auto &i:u)
		{
			cout<<i.first<<i.second<<endl;

		}
		cout<<endl;
		


	}
	
	return 0;
}