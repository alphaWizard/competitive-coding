
/* used for maintaining a system of equations of the form ( y-x = d ) along
			 with the their consistencial queries dynamically using disjoint set union and find data structure.
	
	By:Arpit Gupta(@alphawizard)			 


*/




#include<bits/stdc++.h>
using namespace std;
const int N=50005;
int flaw;     //counting numbers of inconsistent assertions
int pot[N],prec[N];

void initialize(int n)
{
	flaw=0;
	for(int i=0;i<=n;++i)
	{
		prec[i]=i;
		pot[i]=0;
	}

}
int find(int x)
{
	if(prec[x]==x) return x;
	int rx=find(prec[x]);    // rx is the root of x
	pot[x]=(pot[prec[x]]+pot[x]+9)%3;   //add all potentials along the path,i.e.,potential calculated wrt root
	prec[x]=rx;
	return rx;   
}

void merge(int a,int b,int d)
{
	int ra=find(a);
	int rb=find(b);
	if(ra==rb && (pot[a]-pot[b]+9)%3!=d) flaw++;
	else if(ra!=rb)
	{
		pot[ra]=(d+pot[b]-pot[a]+9)%3;
		prec[ra]=rb;
	} 
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n;   //no. of variables
	cin>>n;
	int m;   // no. of equations
	cin>>m;
	initialize(n);
	for(int i=1;i<=m;++i)    //consider 1-based indexing of variables
	{
		int d,a,b;        //asserting a-b=d;
		cin>>d>>a>>b;
		d--;
		if(a>n||b>n) flaw++;
		else
		{
			merge(a,b,d);

		}
		


	}
	cout<<flaw<<endl;
}
	return 0;
}