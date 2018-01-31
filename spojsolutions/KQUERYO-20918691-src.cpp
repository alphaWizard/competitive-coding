#include <bits/stdc++.h>
using namespace std;

vector<int> tree[4*30010];
int arr[30010];
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
        return (tree[index]).end()-upper_bound((tree[index]).begin(),(tree[index]).end(),k);

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
    scanf("%d",&n);

    for(int i=0; i<n; ++i)
        scanf("%d",&arr[i]);

    build(0,0,n-1);

    scanf("%d",&m);

    for(int i=0; i<m; ++i)
    {
        scanf("%d%d%d",&a,&b,&k);
        int ij=a^ans;
        int ji=b^ans;
        int kn=k^ans;
        if(ij<1) ij=1;
        if(ji>n) ji=n;
        if(ij>ji) ans=0;
        else
        ans=query(0,0,n-1,ij-1,ji-1,kn);
        printf("%d\n",ans);
    }
    return 0;
}