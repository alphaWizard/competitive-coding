
#include<bits/stdc++.h>
using namespace std;
const int N=106;
int flaw;     //counting numbers of inconsistent assertions
int pot[N],prec[N];

void initialize(int n)
{
	flaw=0;
	for(int i=1;i<=n;++i)
	{
		prec[i]=i;
		pot[i]=0;
	}

}
int find(int x)
{
	if(prec[x]==x) return x;
	int rx=find(prec[x]);    // rx is the root of x
	pot[x]=(pot[prec[x]]+pot[x]+2)%2;   //add all potentials along the path,i.e.,potential calculated wrt root
	prec[x]=rx;
	return rx;   
}

void merge(int a,int b,int d)
{
	int ra=find(a);
	int rb=find(b);
	if(ra==rb && (pot[a]-pot[b]+2)%2!=d) flaw++;
	else if(ra!=rb)
	{
		pot[ra]=(d+pot[b]-pot[a]+2)%2;
		prec[ra]=rb;
	} 
}


int main()
{
	while(true)
	{
	int n;   //no. of variables
	cin>>n;
	if(n==0) break;
	initialize(n);
	for(int i=1;i<=n;++i)    //consider 1-based indexing of variables
	{
		int a;string b;
		int tr=i;
		cin>>a>>b;           //asserting a-b=d;
		int d;
		if(a<tr) swap(a,tr);
		if(b=="false") d=1;
		else d=0;
		merge(a,tr,d);
	}
	if(flaw>0) cout<<"PARADOX"<<endl;
	else cout<<"NOT PARADOX"<<endl;

	}



	return 0;
}