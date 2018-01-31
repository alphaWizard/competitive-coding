#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int lis( int arr[], int n )
{
    int *lis, i, j, max = 0;
    lis = (int*) malloc ( sizeof( int ) * n );
 
    for (i = 0; i < n; i++ )
        lis[i] = 1;
 
    for (i = 1; i < n; i++ )
        for (j = 0; j < i; j++ ) 
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
 
    for (i = 0; i < n; i++ )
        if (max < lis[i])
            max = lis[i];
 
    free(lis);
 
    return max;
}
int main() {
	int n,c;
	cin>>c>>n;
	int cola[c];
	for(int i=0;i<c;++i)
		cola[i]=i;
	int car[n*c],vbr[n*c];
	for(int i=0;i<n*c;++i)
		cin>>car[i]>>vbr[i];
	int res=INT_MAX;
	do{
		int temp[n*c];
		for(int i=0;i<n*c;++i)
		{
			temp[i]=cola[car[i]-1]*n+vbr[i];

		}
		res=min(res,n*c-lis(temp,n*c));



	}while(next_permutation(cola,cola+c));
	cout<<res;

return 0;
}