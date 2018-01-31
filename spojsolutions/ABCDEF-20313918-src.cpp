#include <bits/stdc++.h>

using namespace std;



int main() {
    
 int n;
    cin>>n;
    vector<int> u;
    int ar[n];
    for(int i=0;i<n;++i)
        cin>>ar[i];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            for(int k=0;k<n;++k)
            {
                   u.push_back((ar[i]*ar[j])+ar[k]);
            }
        }
    }

    sort(u.begin(),u.end());
    //for(int i=0;i<u.size();++i)
     //   cout<<u[i]<<" ";
   // cout<<"\n";
    int ans=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            for(int k=0;k<n;++k)
            {
                   if(ar[k]!=0)
                   {
                       auto it1=lower_bound(u.begin(),u.end(),(ar[i]+ar[j])*ar[k])-u.begin();
                       auto it2=upper_bound(u.begin(),u.end(),(ar[i]+ar[j])*(ar[k]))-u.begin();
                       ans+=it2-it1;
                       //cout<<it2-it1<<" ";
                   }
            }
        }
    }
    cout<<ans<<"\n";
     
 
 
    return 0;
}
