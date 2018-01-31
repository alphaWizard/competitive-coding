

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define op(x) (x&(-x))
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define si(n) scanf("%d",&n)
#define s2i(x,y) scanf("%d %d",&x,&y);
#define s3i(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define s4i(x,y,z,w) scanf("%d %d %d %d",&x,&y,&z,&w);
#define print(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
#define print2d(a,n,m) for(int i=0;i<n;i++) {for(int j=0;j<m;j++) cout<<a[i][j]<<" "; cout<<endl;}

const int N = 100005;
const int MOD = 1000000007;

vector<int> adj[N];




  //mapping down numbers into smaller range as of array size
int sz=0;
for (int i = 0; i < n; i ++) cin >> a[i], tot[sz++] = a[i];

    sort(tot, tot + sz);
    sz = unique(tot, tot + sz) - tot;

    for (int i = 0; i < n; i ++) a[i] = lower_bound(tot, tot + sz, a[i]) - tot;

    






    int phi(int n)
{
    float result = n; 
    for (int p=2; p*p<=n; ++p)
    {

        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
            result *= (1.0 - (1.0 / (float) p));
        }
    }
    if (n > 1)
        result *= (1.0 - (1.0 / (float) n));
 
    return (int)result;
}




//lower bound

while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            ans=query(0,0,n-1,a,b,mid);
            if(ans>=k)
                {hi=mid-1;an=mid;}
            else lo=mid+1;

        }


 int lo = 1, hi = n;                //11111100000
        while( lo <= hi ){
            int mid = (lo + hi) >> 1;

            int can = n;
            for(int i = mid-1; i < n; ++i )
             for(int j = mid-1; j < n; ++j ){
                 int M = pref[i][j];
                 if( i - mid >= 0 && j - mid >= 0 )
                    M -= pref[i-mid][j-mid];
                 can = min( can, M );
             }
            if( can <= k ) lo = mid + 1;
            else hi = mid - 1;
        }

        printf("%d\n", lo - 1 );
    }
        



        //substring diff

     for(int i = 0; i < n; ++i )
         for(int j = 0; j < n; ++j ){
           int s = A[i] != B[j];
           if( i > 0 && j > 0 )
              pref[i][j] = pref[i-1][j-1] + s;
            else
              pref[i][j] = s;
         }



         //lowerbound

                 while(lo < hi){
            mi = (lo + hi)>>1;
            
            if(solve(mi,N-1) < F) lo = mi+1;
            else hi = mi;
        }

       // increasing