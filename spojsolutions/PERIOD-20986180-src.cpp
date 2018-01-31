#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> prefix_function (string s) {
    int n = (int) s.length();
    vector<int> pi (n);
    for (int i=1; i<n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
    }
    return pi;
}

int main()
{
	int p=1;
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
	string s;cin>>s;
	vector<int > v=prefix_function(s);
	int tempo[n+1];
	tempo[0]=0;
	cout<<"Test case #"<<p++<<endl;

	for(int i=1;i<=n;++i)
	{
		if(i%(i-v[i-1])==0&&i/(i-v[i-1])>1) cout<<i<<" "<<i/(i-v[i-1])<<endl;
	}

}

    return 0;
}