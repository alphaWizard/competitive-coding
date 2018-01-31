#include <bits/stdc++.h>
using namespace std;
int dpf[35];
int dpg[35];
int f(int n);
int g(int n);


int main()
{
	for(int i=0;i<35;++i)
		dpf[i]=dpg[i]=-1;
	while(true)
	{
		int n;
		cin>>n;
		if(n==-1) break;
		cout<<f(n)<<endl;

	}
 
    return 0;
}

int g(int n)
{
	if(n==0) return 1;
	if(n==1) return 0;
	if(dpg[n]!=-1) return dpg[n];
	return dpg[n]=f(n)+g(n-2);
}
int f(int n)
{
	if(n==0) return 1;
	if(n==1) return 0;
	if(dpf[n]!=-1) return dpf[n];
	return dpf[n]=f(n-2)+2*g(n-2);
}

