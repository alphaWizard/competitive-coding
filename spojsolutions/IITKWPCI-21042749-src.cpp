#include <bits/stdc++.h>
using namespace std;
int par[1004];
int car[1004];
int n,m;


#define MAXN   1004
int ar[MAXN];
int size[MAXN];
  void initialize( int n) // considering elements as 1-indexed 
    {
        for(int i = 1;i<=n;i++)
        {
    ar[ i ] = i ;
    size[ i ] = 1;
    }
    }
 
  int root (int i)
    {
        while(ar[ i ] != i)
        {
            ar[ i ] = ar[ ar[ i ] ] ; 
    i = ar[ i ]; 
        }
    return i;
    }
void join(int a,int b)
    {
        int root_A = root(a);
        int root_B = root(b);
        if(size[root_A] < size[root_B ])
        {
    ar[ root_A ] = ar[root_B];
    size[root_B] += size[root_A];
    }
        else
        {
    ar[ root_B ] = ar[root_A];
    size[root_A] += size[root_B];
    }

    }

 bool cmp(int a,int b)
{
	if(root(a)==root(b)) return a<b;
	else return false;

}   
int bar[1004];
void lowerdown(int car[],int n)
{
	int tot[n];
	int sz=0;
	for(int j=0;j<n;++j)
		{tot[sz++]=car[j];bar[j]=car[j];}
	sort(tot,tot+sz);
	 sz = unique(tot, tot + sz) - tot;
	for (int i = 0; i < n; i ++) car[i] = lower_bound(tot, tot + sz, car[i]) - tot;
	
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		initialize(n);
		car[0]=-2;
		for(int i=1;i<=n;++i)
			cin>>car[i];
		lowerdown(car,n+1);
		// for(int i=1;i<=n;++i)
		// 	cout<<car[i]<<" ";
		for(int j=1;j<=m;++j)
		{
			int a,b;
			cin>>a>>b;
			join(a,b);
		}
		int visited[n+1]={0};
		for(int i=1;i<=n;++i)
		{
			int x=n+100,in=-1;
			for(int j=1;j<=n;++j)
			{
				if(visited[j]==0&&root(j)==root(i))
				{
					if(car[j]<x){x=car[j];in=j;}
				}

			}
			visited[in]=1;cout<<bar[in]<<" ";
		}
	cout<<endl;

	}
	

return 0;
}
