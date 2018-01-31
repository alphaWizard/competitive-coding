#include <bits/stdc++.h>

using namespace std;

int n,k;
int ar[100005];
int f(int x)
{
    int lst=0;
    int p=1;
    for(int i=1;i<n;++i)
    {
        if(ar[i]-ar[lst]>=x)
        {
            p++;
            if(p==k) return 1;
            lst=i;
        }
    }
    return 0;
}
int bs(int lo,int hi)
{
    if(hi-lo<=1) return lo;
    int mid=lo+(hi-lo)/2;
    int t=f(mid);
    
    if(f(mid)) return bs(mid,hi);
    else return bs(lo,mid);
    
}

int main()
{
    int t;cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<n;++i)
            cin>>ar[i];
        sort(ar,ar+n);
        int lo=0,hi=ar[n-1];
        cout<<bs(lo,hi)<<endl;
        
        
        
        
    }
    return 0;
}