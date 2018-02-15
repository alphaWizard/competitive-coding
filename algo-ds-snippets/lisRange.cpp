	for(int i=0;i<n;++i)
	{
		vector<int> s;
		vector<int>::iterator it;
		for(int j=i;j<n;++j)
		{
			int ans=0;
			x=v[j];
			it = lower_bound(s.begin(), s.end(), x); //strictly increasing
			if(it==s.end()) s.push_back(x);
			else *it=x;
			ans=s.size();
			dp[i].push_back(ans);
		}

	}


//for i to j dp[i][j-i]