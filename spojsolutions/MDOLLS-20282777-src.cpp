 #include<bits/stdc++.h>  
    using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.first!=b.first) return a.first>b.first;
    return a.second<b.second;
}
    int main()
    {
       
       int t;cin>>t;
        while(t--)
        {
            
            int n;
            cin>>n;
         vector<pair<int,int>> v;
            v.clear();
            for(int i=0;i<n;++i)
            {
                int a,b;cin>>a>>b;
                v.push_back({a,b});
            }
            sort(v.begin(),v.end(),cmp);
            int ar[n];
            for(int i=0;i<n;++i)
                ar[i]=v[i].second;
            
             vector<int> br;
            br.push_back(ar[0]);
            
              int top=0,temp;
           for(int i=1;i<n;++i)
           {
              temp=ar[i];
               if(temp>=br[top])
               {br.push_back(temp);top++;}
                else
                {
                    auto it=upper_bound(br.begin(),br.begin()+top+1,temp)-br.begin();
                    br[it]=temp;
                    
                }
           }
          
          cout<<top+1<<endl;
            
        }
    
    return 0;
} 