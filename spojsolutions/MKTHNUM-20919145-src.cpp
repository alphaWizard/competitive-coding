#include <bits/stdc++.h>
using namespace std;

vector<int> tree[4*100100];
int arr[100010];
void build(int index,int start,int end)
{
    if(start == end)
    {
        (tree[index]).push_back(arr[start]);
    }
    else
    {
        int mid = (start+end)/2;
        build(2*index+1,start,mid);
        build(2*index+2,mid+1,end);


        int left=2*index+1;
        int right=left+1;
        merge (tree[left].begin(),tree[left].end(),tree[right].begin(),tree[right].end(),back_inserter(tree[index]));

    }
}

int query(int index,int start,int end,int l,int r,int k)
{

    if(r<start || end<l)
        return 0;
    if(l<=start && end<=r)
        return upper_bound((tree[index]).begin(),(tree[index]).end(),k)-tree[index].begin();

    int mid = (start+end)/2;
    if (l > mid)
        return query(2*index+2, mid+1, end, l, r,k);
    if (r <= mid)
        return query(2*index+1, start, mid, l, r,k);

    int left = query(2*index+1,start,mid,l,r,k);
    int right = query(2*index+2,mid+1,end,l,r,k);

    return left+right;
}
int main() {
    int n,m,a,b,mode,k;
    int ans=0;
    vector<int> v;
    scanf("%d",&n);scanf("%d",&m);

    for(int i=0; i<n; ++i)
       { scanf("%d",&arr[i]);
   v.push_back(arr[i]);}
   sort(v.begin(),v.end());
   for(int i = 0;i < n; i ++ ) {
        arr[i] = lower_bound(v.begin(),v.end(),arr[i]) - v.begin() + 1;
    }

    build(0,0,n-1);

 //    for(int i=1;i<=7;++i)
	// cout<<query(0,0,n-1,0,1,i)<<endl;
	int an;
    for(int i=0; i<m; ++i)
    {
        scanf("%d%d%d",&a,&b,&k);
        a--;b--;
        int lo=1;
        int hi=n;

        while(lo<=hi)
        {
        	int mid=lo+(hi-lo)/2;
        	ans=query(0,0,n-1,a,b,mid);
        	if(ans>=k)
        		{hi=mid-1;an=mid;}
        	else lo=mid+1;

        }
        printf("%d\n",v[an-1]);
    }
    return 0;
}