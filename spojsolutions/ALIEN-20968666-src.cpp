#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
 
int t;
cin>>t;
while(t--)
{
	int n,b;
	cin>>n>>b;
	int ar[n];
	for(int i=0;i<n;++i)
		cin>>ar[i];
	int mas=0,su=0,res=0;
	int i=0,j=0;
	while(i<n&&i<=j)
	{
		while(j<n&&su+ar[j]<=b)
		{
			su+=ar[j];
			j++;
		}
		if(j-i>mas)
		{
			res=su;
			mas=j-i;
		}
		if(j-i==mas)
		{
			res=min(res,su);
		}
		su-=ar[i];
		i++;


	}
	cout<<res<<" "<<mas<<endl;
}



    return 0;
}
