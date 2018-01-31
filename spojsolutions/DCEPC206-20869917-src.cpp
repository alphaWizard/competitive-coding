#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll merge(ll ar[],ll low,ll mid,ll high)
{
    ll n1=mid-low+1;
    ll n2=high-mid;
    ll temp1[n1];                      //copied into two arrays
    ll temp2[n2];
   // ll s[n1];
   // ll sum=0;
    for(ll i=low;i<=mid;++i)
         temp1[i-low]=ar[i];

     for(ll i=mid+1;i<=high;++i)
        temp2[i-mid-1]=ar[i];

   // s[n1-1]=temp1[n1-1];

   // for(ll u=n1-2;u>=0;--u)
    //{
     //  s[u]=temp1[u]+s[u+1]; 
   // }
    ll invct=0;                         //counter of inversion count     
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
            invct+=(n1-i)*ar[k];          // all the remaining contributes to inversions
        }
        k++;
    }
    while(i<n1)
    {                                 // copy remaining elements into original arrays
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
    //cout<<invct<<endl;
    return invct;
    
}
ll mergesort(ll ar[],ll low,ll high)
{                                    
    ll invct=0;
   // cout<<8;
    if(low<high)
    {
        ll mid=low+(high-low)/2;
        invct=mergesort(ar,low,mid);            //inversions in left
        invct+=mergesort(ar,mid+1,high);           // inversions in right
        invct+=merge(ar,low,mid,high);             // inversions during merge
    }
    //cout<<invct<<endl;
    return invct;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
   ll n;cin>>n;
    ll ar[n];
    for(ll i=0;i<n;++i)
     cin>>ar[i];
 	reverse(ar,ar+n);
    ll inversions=mergesort(ar,0,n-1);
    cout<<inversions<<"\n";
}
    return 0;
}

