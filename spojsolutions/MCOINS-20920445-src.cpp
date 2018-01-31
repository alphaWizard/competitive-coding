#include <bits/stdc++.h>
using namespace std;
int dp[1000000];
int k,l;
int f(int n)
{
	if(n<0) return 1;
	if(n==0) return 0;
	if(n==1||n==k||n==l) return 1;
	if(dp[n]!=-1) return dp[n];
	return dp[n]=!(f(n-1)&f(n-k)&f(n-l));

}

int main() {
	for(int i=0;i<1000000;++i)
		dp[i]=-1;
   int m;
   cin>>k>>l>>m;
   while(m--)
   {
   	int a;
   	cin>>a;
   	if(f(a)) cout<<"A";
   	else cout<<"B";
   }

    return 0;
}