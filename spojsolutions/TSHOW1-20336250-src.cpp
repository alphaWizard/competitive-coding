#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
ll t;cin>>t;
    while(t--)
    {
        ll k;cin>>k;
    bitset<55> b(k+(ll)1);
        string s="";
         int number1 = b.count();
        int ct=0;
       for(int i=0;i<55;++i)
       {
           if(b[i]==1)
           {
               ct++;
               if(ct==number1) break;
               else
                   s='6'+s;
           }
           else
               s='5'+s;
       }
         cout<<s<<endl;
    }
   

        
    
    
	
	return 0;
}