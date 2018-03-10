#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
    int val;
    int cnt;
    node* left;
    node* right;
};

node* create()
{
    node* newnode=new node();
    newnode->val=-7;
    newnode->cnt=0;
    newnode->left=newnode->right=NULL;
    return newnode;
}

void insert(node* root,int val)
{
    node* temp=root;
    for(int i=29;i>=0;--i)
    {
        int j=val&(1<<i);
        if(!j)
        {
            if(temp->left==NULL)
                {node* nleft=create();temp->left=nleft;}
            temp=temp->left;

        }
        else
        {
             if(temp->right==NULL)
                {node* nright=create();temp->right=nright;}
             temp=temp->right;
        }
        temp->cnt++;
    }
    temp->val=val;
}

int query(node* root,int val)
{
    node* temp=root;
    int ans=0;
    for(int i=29;i>=0;--i)
    {
        int j=val&(1<<i);
        if(!j)
        {
            if(temp->left==NULL||temp->left->cnt<=0)
                temp=temp->right;
            else temp=temp->left;
        }
        else
        {
            if(temp->right==NULL||temp->right->cnt<=0)
                temp=temp->left;
            else temp=temp->right;
        }
        temp->cnt--;
    }
    return temp->val;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;++i)
        cin>>ar[i];
    node* root=create();
    for(int i=0;i<n;++i)
    {
        int b;
        cin>>b;
        insert(root,b);
    }
    for(int i=0;i<n;++i)
    {
        cout<<(query(root,ar[i])^ar[i])<<" ";
    }

    return 0;
}