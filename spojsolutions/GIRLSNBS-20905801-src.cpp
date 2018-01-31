#include <bits/stdc++.h>



using namespace std;
typedef long long ll;


int main()
{
    
 while(true)
 {
 	int a,b;
 	cin>>a>>b;
 	if(a==-1) break;
 	if(b>a) swap(a,b);
 	int x=a/(b+1)+1;
 	if(a%(b+1)==0) x--;
 	cout<<x<<endl;
        

 }

}