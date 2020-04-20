/*
Minimum operations to make GCD of array a multiple of k
Reference: https://www.geeksforgeeks.org/minimum-operations-make-gcd-array-multiple-k/

Given an array and k, we need to find the minimum operations needed
to make GCD of the array equal or multiple of k.
Here an operation means either increment or decrements an array element by 1.

Examples:

Input : a = { 4, 5, 6 }, k = 5
Output: 2

Explanation:
We can increase 4 by 1 so that it becomes 5
and decrease 6 by 1 so that it becomes 5.
Hence minimum operation will be 2.
*/

#include <iostream>

using namespace std;

int make_gcd_array_multiple_k(int arr[], int n, int k){
    int operations = 0;
    for(int i=0; i<n; i++){
        // for each element, we find how far the number is from a multiple of k
        int rem = arr[i] % k;
        // we decide to increase or decrease based on which multiple is closer
        operations += min(rem, k - rem);
    }
    return operations;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int k;
    cin>>k;
    int operations = make_gcd_array_multiple_k(arr, n, k);
    cout<<operations<<endl;
    return 0;
}
