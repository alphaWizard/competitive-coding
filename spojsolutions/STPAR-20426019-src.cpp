#include <bits/stdc++.h>
using namespace std;


int main() {

    int n;
    while(cin>>n&&n)
    {
        int ar[n];
        stack<int> s;
        for(int i=0;i<n;++i)
            cin>>ar[i];
        int st=1;int p=1;
        for(int i=0;i<n;++i)
        {
            if(ar[i]!=st)
            {
                while(!s.empty()&&s.top()==st) {st++;s.pop();}
                
                s.push(ar[i]);
            }
           else
           {
               st++;
           }
        }
   while(!s.empty())
   {
       if(s.top()==st){st++;s.pop();}
       else break;
   }
       // cout<<st;
        if(st==n+1) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}