#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long ull;
typedef long long int ll;
typedef vector<long long int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        int a[1009];
        int l[1009]={0};
        int r[1009]={0};
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(a[i]<a[j]&&l[j]<l[i]+1)
                    l[j]=l[i]+1;
        for(int i=n-1;i>=0;i--)
            for(int j=i-1;j>=0;j--)
                if(a[i]<a[j]&&r[j]<(r[i]+1))
                    r[j]=r[i]+1;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            if(l[maxi]+r[maxi]<l[i]+r[i])
                maxi=i;
        }
        cout<<l[maxi]+r[maxi]+1<<endl;
    }
    return 0;
}