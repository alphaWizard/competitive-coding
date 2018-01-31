#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;
#define MAXN   1000001
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
         if(root_A==root_B) return;
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

 
int main()
{
       ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
     initialize(n);
    for(int i=1;i<=m;++i)
    {
        int a,b;cin>>a>>b;
        join(a,b);
    }
    int q;cin>>q;//queries checking whether two elements are connected or not
    while(q--)
    {
        int a,b;cin>>a>>b;
        if(root(a)==root(b)) cout<<"connected"<<"\n";
        else cout<<"not connected"<<"\n";
    }
  

    return 0;
}
    
