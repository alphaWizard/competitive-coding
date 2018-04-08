#include<bits/stdc++.h>
using namespace std;

int som(int ar[],int n)  //sum of maximums
{
	int l[n],r[n];
	//l[i]=j s.t j<i and maximum j with ar[j]>ar[i]
	//r[i]=j st j>i and minimum j with ar[j]>=ar[i]
	stack<int> s;
	for(int i=0;i<n;++i)
	{
		while(!s.empty()&&ar[i]>=ar[s.top()])
			s.pop();
		if(s.empty())
			l[i]=-1;
		else l[i]=s.top();
		s.push(i);
	}
	while(!s.empty())
		s.pop();
	for(int i=n-1;i>=0;--i)
	{
		while(!s.empty()&&ar[i]>ar[s.top()])
			s.pop();
		if(s.empty())
			r[i]=n;
		else r[i]=s.top();
		s.push(i);
	}
	int res=0;
	for(int i=0;i<n;++i)
		res+=(i-l[i])*ar[i]*(r[i]-i);
	return res;
}

int main()
{
	int n;
	cin>>n;
	int ar[n];
	for(int i=0;i<n;++i)
		cin>>ar[i];
	int x=som(ar,n);
	for(int i=0;i<n;++i)
		ar[i]*=-1;
	int y=som(ar,n);
	cout<<x+y;

	return 0;
}
