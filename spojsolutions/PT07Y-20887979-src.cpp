  #include <bits/stdc++.h>
using namespace std;
 typedef long long ll;


 /*



int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge(int x,int y){    //  x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y))     return ;
    if(par[y] < par[x]) // balancing the height of the tree
        swap(x, y);
    par[x] += par[y];
    par[y] = x;
}
 */
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
    //cout.tie(NULL);
    int n,m;
    cin>>n>>m;
     initialize(n);
    for(int i=1;i<=m;++i)
    {
        int a,b;cin>>a>>b;
        if(root(a)!=root(b))
        join(a,b);
        else {cout<<"NO";return 0;}
    }
    cout<<"YES";
    
  

    return 0;
}
    
