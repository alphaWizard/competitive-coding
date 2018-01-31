#include <bits/stdc++.h>

using namespace std;


int main(){
   int n;
   cin>>n;
   set<int> s,v;
   set<int> result;
   while(n--)
   {
   	int a;cin>>a;
   	s.insert(a);
   	int ct;cin>>ct;
   	while(ct--)
   	{
   		int b;cin>>b;
   		v.insert(b);
   	}

   }
   set_difference(v.begin(), v.end(), s.begin(), s.end(),inserter(result, result.end()));
   cout<<result.size();
    
    return 0;
}