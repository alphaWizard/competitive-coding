#include <bits/stdc++.h>

using namespace std;

int a[100000];
int b[100000];
bool vis[100000];

int main () {
    int n;
    int t = 0;
    while (cin>>n&&n) {
        t++;
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
            b[i] = a[i];
            vis[i] = false;
        }
        sort(b, b + n);

        unordered_map<int, int> place;
        
        for (int i = 0; i < n; ++i) {
            place[b[i]] = i;
        }
    
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i] == false) {
                if (place[a[i]] == i) {
                    vis[i] = true;
                    continue;
                }
                int min_val = a[i];
                int num = 0;
                int sum = 0;
                int j = i;

                while (vis[j] == false) {
                    sum += a[j];
                    num++;
                    if (a[j] < min_val) {
                        min_val = a[j];
                    }
                    vis[j] = true;
                    j = place[a[j]];
                }
                sum -= min_val;
                res += sum + min_val * (num - 1);
                
                if (2 * (b[0] + min_val) <
                    (min_val - b[0]) * (num - 1)) {
                    res -= (min_val - b[0]) * (num - 1) -
                           2 * (b[0] + min_val);
                }    
            }
        }
        cout<<"Case "<<t<<": "<< res<<endl<<endl;
    }
    return 0;
}
