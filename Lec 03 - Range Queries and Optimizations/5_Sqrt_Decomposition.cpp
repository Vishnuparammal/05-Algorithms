/*  Let's consider there is an array, arr[] = {0,...,n-1 }.
    Now we need to perform two types of operations on this array.

    1. Sum query: Given two indices, (l, r), print the sum of all
       elements in the range (l, r).
    
    2. Update query: Given an index i and value x, replace arr[i]'s
       current value by 'x'.
    
    In simple approach, we can just calculate the sum by adding all
    elements in the range (l, r) one by one and return the sum. In
    this way, the time complexity of sum query is O(n) and for update
    it's O(1).

    In other way, we can create a prefix sum array. pre[] = {0,...,n-1}.
    Now if need to find sum of all elements in the range (l, r), we 
    can just calculate sum = pre[r] - pre[l]. So sum query becomes O(1).
    But if we update, let's say first element of array, we need to create
    entire pre[] array again. So now update operation becomes O(n).

    Square Root Decomposition Technique is one of the most frequently 
    used query optimization technique which reduces sum query time to 
    O(sqrt(n)) keeping the update query's cost O(1) only.

    Let us consider that we have an array of 9 elements.
    A[] = {1, 5, 2, 4, 6, 1, 3, 5, 7}

    Let’s decompose this array into sqrt(9) blocks, where each block will 
    contain the sum of elements lying in it. Therefore now our decomposed 
    array would look like this :

    Blocks_A[] = {8, 11, 15};

    Now there will be two kinds of overlaps when asked sum query:
    Lets say, sum(3, 8). In this query, block 2 and 3 are completely
    included. So sum = 11 + 15 = 26. In the worst case our range can be 0 to 
    n-1. In this case all the blocks are completely overlapped by our query 
    range. Hence, the complexity for this type of query will be O(sqrt(n)).

    But it is possible not whole block might get included. For example, 
    sum(1, 6). In this case, we first add elements till we reach some block.
    So after index 2, we have a block till index 5. So the sum is calculated
    as:
        sum = a[1] + a[2] + Block_a[1] + a[6] = 5 + 2 + 11 + 3 = 21.
    
    If you see, the maximum elements which we need to sum individually 
    can only be 2*(sqrt(n) - 1) at max. In between there will be 
    (sqrt(n)-2) blocks. So the overall operations are:
    2*(sqrt(n)-2) + sqrt(n) - 2 ~ 3*sqrt(n) - 6. 
    So the overall time complexity remains O(sqrt(n)) only.

    For update query we simply find the block in which the given index lies, 
    then subtract its previous value and add the new updated value as per 
    the update query. Time Complexity : O(1)

    Space Complexity: O(sqrt(n))
*/

#include<bits/stdc++.h>
using namespace std;

#define MAX 10000

int* arr = new int[MAX];    // global copy of input array
int block_size = sqrt(MAX);
int* blocks = new int[block_size+1];

// Preprocessing i.e. filling blocks based on input array
void preprocess(int input[], int n) {
    int block_index = -1; 

    for (int i=0; i<n; i++) { 
        arr[i] = input[i]; 
        if (i%block_size == 0)
            block_index++;
        blocks[block_index] += arr[i]; 
    } 
} 

// Update query
void update (int index, int val) {
    int block_number = index/block_size;
    blocks[block_number] += val - arr[index];
    arr[index] = val;
}

// Sum query
int query (int l, int r) {
    int sum = 0; 
    while (l < r && l%block_size!=0 and l!=0) { 
        sum += arr[l]; 
        l++; 
    } 
    while (l+block_size <= r) { 
        sum += blocks[l/block_size]; 
        l += block_size; 
    } 
    while (l<=r) { 
        sum += arr[l]; 
        l++; 
    } 
    return sum;
}

/* ------------- MAIN DRIVER CODE ------------- */
int main() 
{
    int input[] = {1, 5, 2, 4, 6, 1, 3, 5, 7, 10}; 
    int n = sizeof(input)/sizeof(input[0]); 
  
    preprocess(input, n); 
  
    cout << "query(3,8) : " << query(3, 8) << endl; 
    cout << "query(1,6) : " << query(1, 6) << endl; 
    update(8, 1); 
    cout << "query(8,8) : " << query(8, 8) << endl; 
    return 0; 
} 
