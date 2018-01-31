#include <bits/stdc++.h>


#define scll(t)  scanf("%lld",&t)
#define sc(t)  scanf("%lld",&t)

using namespace std;
typedef long long ll;

bool is(ll inp)
{
    ll sq = (long long ll)sqrt(inp);
    return (inp == (sq*sq));
}


int main()
{
        ll t,flag;
 ll n,i;
  scanf("%lld",&t);
 while(t--)
 {
        scanf("%lld",&n);
        flag = 0;
        for(i=0;i*i<=n;i++)
        {

             if(is(n-i*i))
             {
                 flag = 1;
                 break;
             }
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");

 }

}