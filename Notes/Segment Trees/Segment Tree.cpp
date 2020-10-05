#include<bits/stdc++.h>
using namespace std;

// Your segment tree will be present in tree
// Tree must be of size 4*n
void buildSegmentTree(int *arr, int *tree, int start, int end, int treeNode){
	if(start == end){
		tree[treeNode] = arr[start];
		return;
	}

	int mid = (start+end)/2;

	buildSegmentTree(arr, tree, start, mid, 2*treeNode);
	buildSegmentTree(arr, tree, mid+1, end, 2*treeNode+1);

	tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

void updateTree(int *arr, int *tree, int start, int end, int treeNode, int index, int value){
	if(start == end){
		arr[index] = value;
		tree[treeNode] = value;
		return;
	}

	int mid = (start+end)/2;
	
	if(index > mid)
		updateTree(arr, tree, mid+1, end, 2*treeNode+1, index, value);
	else
		updateTree(arr, tree, start, mid, 2*treeNode, index, value);
	
	tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

// To get the sum from the array in a given range
int query(int *tree, int start, int end, int treeNode, int left, int right){
	// Completly outside given range
	if(start>right || end<left)
		return 0;

	// Completly inside given range 
	if(start>=left && end<=right){
		return tree[treeNode];
	}
	// Partially inside and partially outside 
	int mid = (start+end)/2;
	int ans1 = query(tree, start, mid, 2*treeNode, left, right);
	int ans2 = query(tree, mid+1, end, 2*treeNode+1, left, right);

	return ans1+ans2;
}
int main(){
	int arr[] = {1, 2, 3, 4, 5};
	int *tree = new int[20];
	
	buildSegmentTree(arr, tree, 0, 4, 1);

	updateTree(arr, tree, 0, 4, 1, 2, 10);
	
	cout<<query(tree, 0, 4, 1, 2, 4);

	for(int i = 1; i<18; i++)
		cout<<tree[i];
}


---------------------------------------------------------------------------------------------------------
Lazy Propagation

void buildTree(int* arr, int* tree, int start, int end, int treeNode){
	if(start == end){
		tree[treeNode] = arr[start];
		return;
	}

	int mid = (start+end)/2;

	buildTree(arr, tree, start, mid, 2*treeNode);
	buildTree(arr, tree, mid+1, end, 2*treeNode+1);

	tree[treeNode] = min(tree[2*treeNode], tree[2*treeNode+1]);
}

void updateSegTreeLazy(int *tree, int *lazy, int start, int end, int left, int right, int currPos, int inc){
	if(start > end)
		return;
	
	if(lazy[currNode] != 0){
		tree[currPos] += lazy[currPos];

		if(start != end){
			lazy[2*currPos] += lazy[currPos];
			lazt[2*currPos+1] += lazy[currPos];
		}
		lazy[currPos] = 0;
	}

	// No overlap
	if(left > end || right < start)
		return;
	
	// complete overlap
	if(left <= start && end <= right){
		tree[currPos] += inc;
		if(start != end){
			lazy[2*currPos] += inc;
			lazy[2*currPos+1] += inc;
		}
		return;
	}

	// Partial overlap
	int mid = (start+end)/2;
	updateSegTreeLazy(tree, lazy, start, mid, left, right, 2*currPos, inc);
	updateSegTreeLazy(tree, lazy, mid+1, end, left, right, 2*currPos+1, inc);
	
	tree[currPos] = min(tree[2*currPos], tree[2*currPos+1]);
}
