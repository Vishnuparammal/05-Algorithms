// Video Link 1: https://www.youtube.com/watch?v=Ic7OO3Uw6J0
// Video Link 2: https://www.youtube.com/watch?v=0l3xN3BpxHg
// Video Link 3: https://www.youtube.com/watch?v=wyt5_GJqsMw
// Video Link 4: https://www.youtube.com/watch?v=UKH4Zgfa4kI
// Video Link 5: https://www.youtube.com/watch?v=aLLC0Bi6I-Q

#include<iostream>
using namespace std;

// Build Segment Trees
void buildTree(int* arr, int* tree, int start, int end, int treeNode) {
    if (start == end) {
        tree[treeNode] = arr[start];
        return;
    }
    int mid = (start+end)/2;
    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);

    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

// Update a segment tree
void updateTree (int* arr, int* tree, int start, int end, int treeNode, int index, int value) {
    if (start == end) {
        arr[index] = value;
        tree[treeNode] = value;
        return;
    }
    int mid = (start+end)/2;
    if (index > mid) 
        updateTree(arr, tree, mid+1, end, 2*treeNode+1, index, value);
    else
        updateTree(arr, tree, start, mid, 2*treeNode, index, value);
    
    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

// Sum query 
int sumQuery (int* tree, int start, int end, int treeNode, int right, int left) {

	// Completely outside the given range
	if (start > right || end < left)
		return 0;
	
	// Completely inside the given range
	if (start >= left && end <= right)
		return tree[treeNode];

	// Partially inside the given range
	int mid = (start+end)/2;
	int res1 = sumQuery(tree, start, mid, 2*treeNode, left, right);
	int res2 = sumQuery(tree, mid+1, end, 2*treeNode+1, left, right);
	return (res1+res2);
}

/* -------------- MAIN DRIVER CODE ----------------- */
int main() {
    int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
    int* seg_tree = new int[2*n];

    buildTree(arr, seg_tree, 0, 4, 1);
    //updateTree(arr, seg_tree,0, 4, 1, 2, 10);
	for (int i = 1; i < 10; i++)
		cout << seg_tree[i] << " ";
	cout << endl;
	int ans = sumQuery (seg_tree, 0, 4, 1, 1, 2);
	cout << "Sum(2, 4) = " << ans << endl;

	delete seg_tree;
    return 0;
}	