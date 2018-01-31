/*  generates prime in the range n to m 
n,m <=10e9
*/

#include <bits/stdc++.h>
using namespace std;



inline bool isPrime(int x)
{
	if(x<2 || (x%2==0 && x!=2)) return false;
	for(int i=3;i*i<=x;i+=2) if(x%i==0) return false;
	return true;
}

vector<int> genPrimes(int start,int finish)
{
	vector<int> ret;
	for(int i=start;i<=finish;++i) if(isPrime(i)) ret.push_back(i);
	return ret;
}


inline bool ok(const vector<int>&p,int x) {
	 if(x==1) return false;
	int n = p.size();
	for(int i=0;i<n && p[i]*p[i] <= x;i++) {
		if(x%p[i]==0) return false;
	}
	return true;
}

int main() {
	vector<int> pp = genPrimes(2,31625);
	int n;
	int m;
    cin>>n>>m;

	vector<int> p;
	for(int i=n;i<=m;++i) if(ok(pp,i)) {cout<<i<<" ";}

	return 0;
}
