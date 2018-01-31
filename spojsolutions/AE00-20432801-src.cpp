#include<bits/stdc++.h>
using namespace std;

int main()
{
 int n;
    cin>>n;int ct=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=i;j<=n/i;++j)
        {
            if(i*j<=n) ct++;
        }
    }
    cout<<ct;
    return 0;
}