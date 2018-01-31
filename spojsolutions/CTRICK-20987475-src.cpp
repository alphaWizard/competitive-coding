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
		vector<int> v(n);
		for(int i=0;i<n;++i)
			v[i]=i+1;
		for(int j=n-1;j>=0;j--)
		{
			int ctrev=j+1;
			ctrev=ctrev%(n-j);
			rotate(v.begin()+j, v.begin()+n-ctrev, v.end());

		}
		for(int i=0;i<n;++i)
			cout<<v[i]<<" ";
		cout<<endl;
	}

    return 0;
}