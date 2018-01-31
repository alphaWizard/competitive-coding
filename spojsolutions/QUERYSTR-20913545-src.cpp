
#include<bits/stdc++.h>
using namespace std;

vector<int> f(string s) {   //utility function computing z-array
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
	 ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin>>s;
	string real=s;
	reverse(s.begin(),s.end());
	s+=s;
	vector<int> z=f(s);
	vector<int> ans;
	// for(int i=z.size()-1;i>=real.length();--i)
	// {
	// 	ans.push_back(z[i]);
	// }
	// for(auto &w:ans)
	// 	cout<<w<<endl;
	int q;
	cin>>q;
	while(q--)
	{
		int a;
		cin>>a;
		cout<<z[z.size()-a]<<endl;
	}


}
	return 0;
}