#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {
    
int n;
   scanf("%d",&n);
    int r=0;
    for(int i=0;i<n;++i)
    {
        int a;scanf("%d",&a);r^=a;
    }
  printf("%d",r);
	
	return 0;
}