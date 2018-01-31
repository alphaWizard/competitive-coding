#include <bits/stdc++.h>
using namespace std;
vector<int> z_function(string s) {   //utility function computing z-array
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
string s;
cin>>s;
        int ct=0;
        string pat;
        cin>>pat;
        int l=pat.length();
        s=pat+'#'+s;
            vector <int> z=z_function(s);
        vector<int> posn;
for(int i=l+1;i<z.size();++i) //print the z-array
{
    if(z[i]==l) {
        ct++;
        posn.push_back(i-l);
    
}
}
        if(ct>0)
    {
        cout<<ct<<endl;
        for(int i=0;i<posn.size();++i)
            cout<<posn[i]<<" ";
        cout<<endl<<endl;
    }

    else cout<<"Not Found"<<endl<<endl;
    
    }
    
return 0;
}