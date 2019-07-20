/*  PROBLEM:
    Given an unsorted array of integers, find a subarray 
    which adds to a given number. If there are more than 
    one subarrays with the sum as the given number, print 
    any of them.

    Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33
    Ouptut: Sum found between indexes 2 and 4

    Input: arr[] = {10, 2, -2, -20, 10}, sum = -10
    Ouptut: Sum found between indexes 0 to 3

    Input: arr[] = {-10, 0, 2, -2, -20, 10}, sum = 20
    Ouptut: No subarray with given sum exists

    SOLUTION:
    The idea is to maintain sum of elements encountered so far 
    in a variable (say curr_sum). Let the given number is sum. 
    Now for each element, we check if curr_sum – sum exists in 
    the map or not. If we found it in the map that means, we 
    have a subarray present with given sum, else we insert 
    curr_sum into the map and proceed to next element. If all 
    elements of the array are processed and we didn’t find 
    any subarray with given sum, then subarray doesn’t exist.

    Time and Space Complexity: O(n)
*/

#include<bits/stdc++.h> 
using namespace std; 
  
// Main Logic 
void subArraySum(int arr[], int n, int sum) { 
    unordered_map<int, int> map; 
    int curr_sum = 0; 
  
    for (int i = 0; i < n; i++) { 
        curr_sum = curr_sum + arr[i]; 
        if (curr_sum == sum) { 
            cout << "Sum found between indexes "
                 << 0 << " to " << i << endl; 
            return; 
        } 
        if (map.find(curr_sum - sum) != map.end()) { 
            cout << "Sum found between indexes "
                 << map[curr_sum - sum] + 1 
                 << " to " << i << endl; 
            return; 
        } 
        map[curr_sum] = i; 
    } 
    cout << "No subarray with given sum exists"; 
} 
  
/* ------------ MAIN DRIVER CODE ------------- */
int main() 
{ 
    int arr[] = {10, 2, -2, -20, 10}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int sum = -10; 
  
    subArraySum(arr, n, sum); 
  
    return 0; 
} 