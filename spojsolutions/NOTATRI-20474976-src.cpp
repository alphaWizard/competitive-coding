#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(cin>>n&&n)
    {
        int ar[n];
        for(int i=0;i<n;++i)
            cin>>ar[i];
        sort(ar,ar+n);int s=0;
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                auto it=upper_bound(ar,ar+n,ar[i]+ar[j])-ar;
                s+=n-it;
                
            }
        }
        cout<<s<<endl;
    }

	return 0;
} 