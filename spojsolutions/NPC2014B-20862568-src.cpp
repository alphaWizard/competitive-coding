#include<bits/stdc++.h>
using namespace std;
int ar[5005];
int mi(int l,int r)
{
    //int m=ar[l];
    int in=l;
    for(int j=l+1;j<=r;++j)
    {
        if(ar[j]<ar[in]) in=j;
    }
    return in;
}
int f(int l,int r,int h )
{ if(l>r) return 0;
    int a=mi(l,r);
    int er=ar[a];
    return min(r-l+1,f(l,a-1,er)+f(a+1,r,er)+er-h);
}
int main()
{
    int n;cin>>n;
    //int ar[n];
    for(int i=0;i<n;++i)
        cin>>ar[i];
    cout<<f(0,n-1,0);
    return 0;
}