#include <iostream>

using namespace std;
int ans[3000][3000];
   
    int solve(int x, int y)
    {
        if(x<=0||y<=0)
            return -1;
        else if(ans[x][y]==-1)
        {
        ans[x][y] = max( solve(x-17,y+7)+2, solve(x-2,y-8)+2 );
        }
        return ans[x][y];
    }
int main()
{
    int t;cin>>t; 
    for(int i=0;i<3000;++i)
        for(int j=0;j<3000;++j)
            ans[i][j]=-1;
    while(t--)
    {
        
       int h,a;
        cin>>h>>a;
       cout<<solve(h,a)<<endl;
        }
    return 0;
}