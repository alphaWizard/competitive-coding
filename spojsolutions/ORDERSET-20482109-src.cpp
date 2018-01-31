#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() { 
    ordered_set x;
   int n;
    cin>>n;
    while(n--)
    {
        char a;cin>>a;
        int b;cin>>b;
        if(a=='I') {if(x.find(b)==x.end()) x.insert(b); }
        if(a=='D'){if(x.find(b)!=x.end()) x.erase(b);}
          //cout<<x.size()<<endl;
        if(a=='K') {if(x.end()!=x.find_by_order(b-1)) cout<<*x.find_by_order(b-1)<<endl;else cout<<"invalid"<<endl;}
        if(a=='C') cout<<x.order_of_key(b)  <<endl;
        
    }
  
    return 0;
    
}