/*#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long ull;
typedef long long int ll;
typedef vector<long long int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
int n;
ll a=0;
string ans;
void bfs()
{
    bool visited[n]={false};
    pair<string,int> x;
    list<pair<string,int> > q;
    q.push_back(pair<string,int>("1",1));
    visited[1%n]=true;
    while(!q.empty())
    {
        x=q.front();
        a=x.second;
        visited[a%n]=true;
        if(a%n==0)
        {
            ans=x.first;
            return;
        }
        x.second%=n;
        q.pop_front();
        if(!visited[(x.second*10)%n])
        q.push_back({x.first+"0",(x.second*10)%n});
        x.second=(x.second*10+1)%n;
        if(!visited[x.second])
        q.push_back({x.first+"1",(x.second)%n});
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        bfs();
        cout<<ans<<endl;
    }
	return 0;
}*/
    #include <bits/stdc++.h>
    using namespace std;
    #define MAX 20005
    int value[MAX];
    int parent[MAX];
     
    void bfs(int n){
    	queue<int> q;
    	q.push(1);
    	parent[1] = 0;
    	while(!q.empty()){
    		int current = q.front();
    		q.pop();
    		if(current == 0){
    			stack<int> st;
    			while(parent[current]){
    				st.push(value[current]);
    				current = parent[current];
    			}
    			st.push(1);
    			while(!st.empty()){
    				cout<<st.top();
    				st.pop();
    			}
    			cout<<endl;
    			break;
    		}
    		int temp = (current*10)%n;
    		if(parent[temp]==-1){
    			q.push(temp);
    			parent[temp] = current;
    			value[temp] = 0;
    		}
     
    		temp = (current*10)+1;
    		temp = temp%n;
    		if(parent[temp]==-1){
    			q.push(temp);
    			parent[temp] = current;
    			value[temp] = 1;
    		}
    	}
    }
     
    int main(){
     
     
    	ios_base::sync_with_stdio(false);
    	#ifndef ONLINE_JUDGE
    	freopen("input.in","r",stdin);
    	freopen("output.out","w",stdout);
    	#endif
     
    	int t,n;
    	cin>>t;
    	while(t--){
    		cin>>n;
    		for(int i=0;i<=n;i++)
    			parent[i] = -1;
    		bfs(n);
    	}
    	return 0;
    }