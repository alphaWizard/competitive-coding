#include <bits/stdc++.h>
using namespace std;
 
#define MAXN 500005
#define SQRSIZE  800
 
int arr[MAXN];             
int block[SQRSIZE];      
int blk_sz;                  
 
void update(int idx, int val)
{
    int blockNumber = idx / blk_sz;
    block[blockNumber] += val - arr[idx];
    arr[idx] = val;
}
 
int query(int l, int r)
{
    int sum = 0;
    while (l<r and l%blk_sz!=0 and l!=0)
    {
        sum += arr[l];
        l++;
    }
    while (l+blk_sz <= r)
    {
        sum += block[l/blk_sz];
        l += blk_sz;
    }
    while (l<=r)
    {
        sum += arr[l];
        l++;
    }
    return sum;
}
 

void preprocess(int input[], int n)
{
    int blk_idx = -1;
 
    blk_sz = sqrt(n);
 
    for (int i=0; i<n; i++)
    {
        arr[i] = input[i];
        if (i%blk_sz == 0)
        {
            blk_idx++;
        }
        block[blk_idx] += arr[i];
    }
}
 
// Driver code
int main()
{
    int n;
    cin>>n;
    int input[n];
    for(int i=0;i<n;++i)
        cin>>input[i];
    preprocess(input, n);
 
    cout << "query(3,8) : " << query(3, 8) << endl;
    cout << "query(1,6) : " << query(1, 6) << endl;
    update(8, 0);
    cout << "query(8,8) : " << query(8, 8) << endl;
    return 0;
}