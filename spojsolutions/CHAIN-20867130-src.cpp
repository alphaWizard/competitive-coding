
#define _CRT_SECURE_NO_WARNINGS 1
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;



const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const int MAX = 50001;

int root[MAX], d[MAX];

int find(int u) {
	if(u == root[u]) return u;
	int tmp = root[u];
	root[u] = find(root[u]);
	d[u] = (d[tmp] + d[u]+9)%3;
	return root[u];
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int test, cs, n, k, i, t, x, y, px, py, ans, tmp;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &k);
		for(i = 1; i <= n; i++) {
			root[i] = i;
			d[i] = 0;
		}
		ans = 0;
		while(k--) {
			scanf("%d %d %d", &t, &x, &y);
			if(x > n || y > n) { ans++; continue; }
			px = find(x);
			py = find(y);
			t--;
			if(px == py) {
				tmp = (d[x] - d[y]+9) % 3; 
				if(tmp != t) ans++;
			}
			else {
				root[px] = py;
				i = (t-d[x]+d[y]+9)%3;
				d[px] = i;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}