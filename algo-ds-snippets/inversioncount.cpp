#include <bits/stdc++.h>
using namespace std;
int merge(int ar[],int low,int mid,int high)
{
    int n1=mid-low+1;
    int n2=high-mid;
    int temp1[n1];                      //copied into two arrays
    int temp2[n2];
    for(int i=low;i<=mid;++i)
        temp1[i-low]=ar[i];
     for(int i=mid+1;i<=high;++i)
        temp2[i-mid-1]=ar[i];
    int invct=0;                         //counter of inversion count     
    int i=0,j=0,k=low;
    while(i<n1&&j<n2)
    {
        if(temp1[i]<=temp2[j])
        {
            ar[k]=temp1[i];
            i++;
        }
        else
        {
            ar[k]=temp2[j];
            j++; 
            invct+=n1-i;           // all the remaining contributes to inversions
        }
        k++;
    }
    while(i<n1)
    {                                 // copy remaining elements into original arrays
        ar[k]=temp1[i];
        k++;
        i++;
    }
     while(j<n2)
    {
        ar[k]=temp2[j];
        k++;
        j++;
    }
    return invct;
    
}
int mergesort(int ar[],int low,int high)
{                                    
    int invct=0;
    if(low<high)
    {
        int mid=low+(high-low)/2;
        invct=mergesort(ar,low,mid);            //inversions in left
        invct+=mergesort(ar,mid+1,high);           // inversions in right
        invct+=merge(ar,low,mid,high);             // inversions during merge
    }
    return invct;
}
int main()
{
   int n;cin>>n;
    int ar[n];
    for(int i=0;i<n;++i)
     cin>>ar[i];
    int inversions=mergesort(ar,0,n-1);
    cout<<inversions<<"\n";
    return 0;
}

