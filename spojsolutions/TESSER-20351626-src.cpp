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
    int t;cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
        int ar[n];
        string s="";
        for(int i=0;i<n;++i)
        {
            cin>>ar[i];
            if(i>0)
            {
                if(ar[i]>ar[i-1]) s+='G';
                else if(ar[i]==ar[i-1]) s+='E';
                else s+='L';
            }
                
        }
        string pat;
        cin>>pat;
        int l=pat.length();
        string temp=pat+'#'+s;
        vector<int> z=z_function(temp);
        bool a=false;
        for(int i=l+1;i<z.size();++i)
        {
            if(z[i]==l) {a=true;break;}
        }
    if(a) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";


    }

return 0;
}