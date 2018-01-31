#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int sum[2][503][503];
int dp[503][503];
int R, C;

void solve(){
    for(int i=0;i<R;++i){
        for(int j=0;j<C;++j){
            int tmp1 = sum[0][i][j];
            int tmp2 = sum[1][i][j];
            if(j>0) tmp1 += dp[i][j-1];
            if(i>0) tmp2 += dp[i-1][j];
            dp[i][j] = max(tmp1, tmp2);
        }
    }
    printf("%d\n", dp[R-1][C-1]);
}

int main(){
    while(scanf("%d %d", &R, &C), R+C!=0){
        int s;
        for(int i=0;i<R;++i){
            for(int j=0;j<C;++j){
                scanf("%d", &s);
                sum[1][i][j] = s;
                if(j>0) sum[1][i][j] += sum[1][i][j-1];
            }
        }
        for(int i=0;i<R;++i){
            for(int j=0;j<C;++j){
                scanf("%d", &s);
                sum[0][i][j] = s;
                if(i>0) sum[0][i][j] += sum[0][i-1][j];
            }
        }
        solve();
    }
    return 0;
}