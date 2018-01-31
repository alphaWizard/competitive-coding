#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
      int n,i,last;
      scanf("%d",&n);
      int a[n];
      for(i=0;i<n;i++)
            scanf("%d",&a[i]);
      last=n;
      for(i=n-1;i>=0;i--)
            if(a[i]==last) last--;
      printf("%d\n",last);
      return 0;
}