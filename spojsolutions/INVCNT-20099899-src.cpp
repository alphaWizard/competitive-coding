#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll merge(ll ar[],ll low,ll mid,ll high)
{
    ll n1=mid-low+1;
    ll n2=high-mid;
    ll temp1[n1];
    ll temp2[n2];
    for(ll i=low;i<=mid;++i)
        temp1[i-low]=ar[i];
     for(ll i=mid+1;i<=high;++i)
        temp2[i-mid-1]=ar[i];
    ll invct=0;
    ll i=0,j=0,k=low;
    while(i<n1&&j<n2)
    {
        if(temp1[i]<=temp2[j])
        {
            ar[k]=temp1[i];
            i++;
        }
        else
        {
            ar[k]=temp2[j];
            j++;
            invct+=n1-i;
        }
        k++;
    }
    while(i<n1)
    {
        ar[k]=temp1[i];
        k++;
        i++;
    }
     while(j<n2)
    {
        ar[k]=temp2[j];
        k++;
        j++;
    }
    return invct;
    
}
ll mergesort(ll ar[],ll low,ll high)
{
    ll invct=0;
    if(low<high)
    {
        ll mid=low+(high-low)/2;
        invct=mergesort(ar,low,mid);
        invct+=mergesort(ar,mid+1,high);
        invct+=merge(ar,low,mid,high);
    }
    return invct;
}
int main()
{
    ll t;cin>>t;
    while(t--)
    {
   ll n;cin>>n;
    ll ar[n];
    for(ll i=0;i<n;++i)
     cin>>ar[i];
    ll inversions=mergesort(ar,0,n-1);
    cout<<inversions<<"\n";
    }
    return 0;
}