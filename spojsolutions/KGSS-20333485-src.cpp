
#include <cstdio>
#include <algorithm>
using namespace std;

struct SegmentTreeNode {
	int ma,ma2;
	
	void assignLeaf(int value) {
		ma=value;ma2=-1;
	}
	
	void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
		ma=max(left.ma,right.ma);
        ma2=min(max(left.ma,right.ma2),max(right.ma,left.ma2));
	}
	
	int getValue() {
		return ma+ma2;
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
	int N, i, A[100005], M, y,z;char x[4];
	
	scanf("%d", &N);
	for (i = 0; i < N; ++i)
		scanf("%d", &A[i]);
	SegmentTree<int,int> st(A, N);
	
	scanf("%d", &M);
	for (i = 0; i < M; ++i) {
		scanf("%s %d %d", &x, &y,&z);
        if(x[0]=='Q')
		printf("%d\n", st.getValue(y-1, z-1));
        else
        { A[y-1]=z;
            st.update(y-1,A[y-1]);
        }
	}	
	
	return 0;
} 
	