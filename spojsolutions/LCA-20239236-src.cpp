#include<bits/stdc++.h>
using namespace std;
int parent[1001],visited[1001];

void init()
{
    for(int k=0;k<1001;++k) {
        parent[k]=k;
        visited[k]=0;
    }
}
int lca(int x, int y, int n){

	int i;
	for(i=1;i<=n;i++) visited[i] = 0;

	visited[x] = 1;

	while(parent[x]!=x){
		visited[x] = 1;
		x = parent[x];
	}

	visited[x] = 1;

	while(visited[y]!=1) y = parent[y];

	return y;
}

int main(){
	int t,case_no;
	int n,m,q,x,y,i,j,k;
	cin>>t;
    int p=1;
	while(t--)
          {
		cout<<"Case "<<p++<<':'<<endl;
		cin>>n;
        init();
		for(k=1;k<=n;k++) parent[k] = k;
		for(i=1;i<=n;i++){
			cin>>m;
			while(m--){
				cin>>k;
				parent[k] = i;
			}
		}
		cin>>q;
		while(q--){
			cin>>x>>y;
			cout<<lca(x,y,n)<<endl;
		}
	}
	return 0;
}