#include<bits/stdc++.h>
using namespace std;


int main() {
  

    int t;
    cin>>t;
    while(t--)
    {
       int n,k;
       cin>>n>>k;
       int ar[n];
       int hi=-1;
       for(int i=0;i<n;++i)
        {cin>>ar[i];hi=max(hi,ar[i]);}
    int lo=0;hi++;int mid=lo+(hi-lo)/2;
    while(hi-lo>1)
    {
        //cout<<lo<<" "<<hi<<endl;
         mid=lo+(hi-lo)/2;
        int ct=0;
        for(int i=0;i<n;++i)
        {
            ct+=ar[i]/mid;
        }
        if(ct>=k)
            lo=mid;
        else hi=mid;

    }
    cout<<lo<<endl;

    }
    return 0;
}
