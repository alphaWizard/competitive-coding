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
	int n;
	cin>>n;
	for(int j=1;j<=n;++j)
	{
	string s;
	cin>>s;
	int ans=0;
	vector <int> z=z_function(s);
	for(int i=0;i<z.size();++i) 
	{
	if(z[i]==s.length()-i) ans++;
	}
	cout<<"Case "<<j<<": "<<ans<<endl;
}
return 0;
}
