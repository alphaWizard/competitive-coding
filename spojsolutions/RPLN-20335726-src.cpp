#include <bits/stdc++.h>
using namespace std;

struct SegmentTreeNode {
	int mi;
	
	void assignLeaf(int c) {
		mi=c;
	}
	
	void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
		mi=min(left.mi,right.mi);
	}
	
	int getValue() {
		return mi;
	}
};

template<class T, class V>
class SegmentTree {
	SegmentTreeNode* nodes;
	int N;
	
public:
	SegmentTree(T arr[], int N) {
		this->N = N;
		nodes = new SegmentTreeNode[getSegmentTreeSize(N)];
		buildTree(arr, 1, 0, N-1);
	}
	
	~SegmentTree() {
		delete[] nodes;
	}
	
	V getValue(int lo, int hi) {
		SegmentTreeNode result = getValue(1, 0, N-1, lo, hi);
		return result.getValue();
	}
	
	void update(int index, T value) {
		update(1, 0, N-1, index, value);
	}
	
private:	
	void buildTree(T arr[], int stIndex, int lo, int hi) {
		if (lo == hi) {
			nodes[stIndex].assignLeaf(arr[lo]);
			return;
		}
		
		int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
		buildTree(arr, left, lo, mid);
		buildTree(arr, right, mid + 1, hi);
		nodes[stIndex].merge(nodes[left], nodes[right]);
	}
	
	SegmentTreeNode getValue(int stIndex, int left, int right, int lo, int hi) {
		if (left == lo && right == hi)
			return nodes[stIndex];
			
		int mid = (left + right) / 2;
		if (lo > mid)
			return getValue(2*stIndex+1, mid+1, right, lo, hi);
		if (hi <= mid)
			return getValue(2*stIndex, left, mid, lo, hi);
			
		SegmentTreeNode leftResult = getValue(2*stIndex, left, mid, lo, mid);
		SegmentTreeNode rightResult = getValue(2*stIndex+1, mid+1, right, mid+1, hi);
		SegmentTreeNode result;
		result.merge(leftResult, rightResult);
		return result;
	}
	
	int getSegmentTreeSize(int N) {
		int size = 1;
		for (; size < N; size <<= 1);
		return size << 1;
	}
	
	void update(int stIndex, int lo, int hi, int index, T value) {
		if (lo == hi) {
			nodes[stIndex].assignLeaf(value);
			return;
		}
		
		int left = 2 * stIndex, right = left + 1, mid = (lo + hi) / 2;
		if (index <= mid)
			update(left, lo, mid, index, value);
		else
			update(right, mid+1, hi, index, value);
		
		nodes[stIndex].merge(nodes[left], nodes[right]);
	}
};

int main() {
	int N, i, M, x,y;
  int A[100005];
    int t;
    cin>>t;
    for(int cas=1;cas<=t;++cas)
    {
   
	
	cin>>N>>M;
        for(int i=0;i<N;++i)
            cin>>A[i];
        
	
      
	SegmentTree<int,int> st(A, N);
	cout<<"Scenario #"<<cas<<":"<<endl;
	//scanf("%d", &M);//cout<<M;
	for (i = 0; i < M; ++i) {
		scanf("%d %d", &x, &y);
        
       
           cout<<(st.getValue(x-1,y-1))<<endl;
             
           // printf("%d\n", );
        
  
    }
    }
    
	
	return 0;
}