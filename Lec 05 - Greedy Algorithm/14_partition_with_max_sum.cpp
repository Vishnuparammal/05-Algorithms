/*
Reference: https://www.geeksforgeeks.org/partition-into-two-subarrays-of-lengths-k-and-n-k-such-that-the-difference-of-sums-is-maximum/

Given an array of non-negative integers of length N and an integer k.
Partition the given array into two subarrays of length K and N – k so that
the difference between the sum of both subarray is maximum.

Examples :

Input : arr[] = {8, 4, 5, 2, 10}
        k = 2
Output : 17
Explanation :
Here, we can make first subarray of length k = {4, 2}
and second subarray of length N - k = {8, 5, 10}. Then,
the max_difference = (8 + 5 + 10) - (4 + 2) = 17.

Input : arr[] = {1, 1, 1, 1, 1, 1, 1, 1}
        k = 3
Output : 2
Explanation :
Here, subarrays would be {1, 1, 1, 1, 1} and {1, 1, 1}.
So, max_difference would be 2.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int partition_with_max_sum(int arr[], int n, int k){
    // we will divide the array in such a way that
    // there will be smaller numbers in short part of array
    // and bigger numbers in larger part of array
    int partition = min(k, n-k);
    sort(arr, arr + n);

    int suml = 0;
    int sumh = 0;
    for(int i=0; i<partition; i++)
        suml += arr[i];
    for(int i=partition; i<n; i++)
        sumh += arr[i];

    return (sumh - suml);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int k;
    cin>>k;
    int sum = partition_with_max_sum(arr, n, k);
    cout<<sum<<endl;
    return 0;
}