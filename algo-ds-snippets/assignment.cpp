    #include <bits/stdc++.h>
        using namespace std;
         
        int dp[1 << 20];
        int n;
        vector<pair<int,int>> a,b;
         
        int f(int i,int j)
        {
        	int ret = abs(a[i].first - b[j].first);
        	ret += abs(a[i].second - b[j].second);
        	return ret;
        }
         
        int solve(int mask)
        {
            int a=__builtin_popcount(mask);
        	if(a == n) return 0;
        	else if(dp[mask] != -1) return dp[mask];
        	int ret = INT_MAX;
        	for(int i = 0; i < n; i++)
        	{
        		if(mask & (1 << i)) continue;
        		ret = min(ret, f(a,i) + solve(mask|1<<i));
        	}
        	return (dp[mask] = ret);
        }
         
        int main()
        {
        	cin >> n;
        	a.resize(n);
        	b.resize(n);
        	memset(dp,-1,sizeof(dp));
         
        	for(int i = 0; i < n; i++)
        		cin >> a[i].first >> a[i].second;
        	for(int i = 0; i < n; i++)
        		cin >> b[i].first >> b[i].second;
         
        	int ans = solve(0);
        	cout << ans << endl;
        	return 0;
        }
     
