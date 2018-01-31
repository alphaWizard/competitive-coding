
#include<bits/stdc++.h>
using namespace std;

int f(string s) {   //utility function computing z-array
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
    return *max_element(z.begin(),z.end());
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin>>s;
	string te="";
	te+=s[0];
	int ans=1;
	int p=1;
	for(int i=1;i<s.length();++i)
	{
		te=s[i]+te;
		p++;
		ans+=p-f(te);

	}
	cout<<ans<<endl;

}
	return 0;
}