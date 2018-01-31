#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	while(true)
	{
		int n;
		cin>>n;
		if(n==0) break;
		int ar[n+1];
		for(int i=1;i<=n;++i)
			cin>>ar[i];
		int f=0;
		for(int i=1;i<=n;++i)
		{
			if(ar[ar[i]]!=i) {f=1;}
		}
		if(f==1)
			cout<<"not ambiguous"<<endl;
		else cout<<"ambiguous"<<endl;

	}


   
    return 0;
}