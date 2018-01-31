#include <bits/stdc++.h>
using namespace std;
vector<int> v[100020],rv[100020];
int visited[100020];
int comp[100020];
stack<int> st;
void dfs(int s)
{
    visited[s]=1;
    for(auto vi: v[s])
    {
        if(!visited[vi]) dfs(vi);
    }
    st.push(s);
    
}
void dfs2(int s,int compo)
{
    visited[s]=1;
    comp[s]=compo;
    //if(out[s]==0) res++;
    int m=0;
    for(auto vi: rv[s])
    {
        if(!visited[vi]) dfs2(vi,compo);
    }
}

int main()
{

   int n,m;
   cin>>n>>m;
   //res=0;
   for(int i=1;i<=n;++i) 
  {
      visited[i]=0;
     // out[i]=0;
      comp[i]=0;
      v[i].clear();
      rv[i].clear();
  }

   for(int i=1;i<=m;++i)
   {
   	int a,b;
   	cin>>a>>b;
   	v[b].push_back(a);
   	rv[a].push_back(b);

       
	}

   
  for(int i=1;i<=n;++i) 
  {
      if(!visited[i]) dfs(i);
  }
   for(int i=1;i<=n;++i) 
  {
      visited[i]=0;
  }
  //int ev=0,od=0;
  int components=1;
 while(!st.empty())
  {
     // cout<<st.top()<<endl;
      int i=st.top();
      st.pop();
      if(!visited[i])
      {
          dfs2(i,components++);

      }
      
  }
 
  // for(int i=1;i<=n;++i )
  // 	cout<<comp[i]<<endl;
  int ncom=components-1;
  //cout<<ncom<<endl;
  int in[ncom+1]={0};

  for(int i=1;i<=n;++i )
  {
  	int tr=0;
  	for(auto &j:v[i])
  	{
  		if(comp[i]!=comp[j])
  			in[comp[j]]++;
  		//cout<<j<<" ";
  	}
  	//cout<<endl;
  	
  }
  int ct=0;
  for(int i=1;i<=ncom;++i)
  {
  	if(in[i]==0) ct++;

  }
  if(ct>1) {cout<<0<<endl;}
  else
  {
  	ct=0;
  	//vector<int> sol;
  	for(int i=1;i<=n;++i)
  	{
  		if(in[comp[i]]==0) ct++;
  	}
  	cout<<ct<<endl;
  	for(int i=1;i<=n;++i)
  	{
  		if(in[comp[i]]==0) cout<<i<<" ";
  	}


  }



  
   
   
    return 0;
}


