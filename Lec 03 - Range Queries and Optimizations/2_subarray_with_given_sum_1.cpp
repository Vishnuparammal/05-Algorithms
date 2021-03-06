/*  PROBLEM:
    Given an unsorted array of nonnegative integers, find a 
    continous subarray which adds to a given number.

    Examples :

        Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33
        Ouptut: Sum found between indexes 2 and 4

        Input: arr[] = {1, 4, 0, 0, 3, 10, 5}, sum = 7
        Ouptut: Sum found between indexes 1 and 4

        Input: arr[] = {1, 4}, sum = 0
        Output: No subarray found

    SOLUTION:

    a) Initialize a variable curr_sum as first element. 
       curr_sum indicates the sum of current subarray. 
    b) Start from the second element and add all elements 
       one by one to the curr_sum. 
    c) For every iteration do following:
       - If curr_sum becomes equal to sum, then print the solution. 
       - If curr_sum exceeds the sum, then remove trailing elements 
         while curr_sum is greater than sum.
    
    Time complexity: O(n)
*/

#include <iostream>
using namespace std;

// Main Logic
int subArraySum (int arr[], int n, int sum) { 
    int curr_sum = arr[0], start = 0, i; 
    for (i = 1; i <= n; i++) { 
        while (curr_sum > sum && start < i-1) { 
            curr_sum = curr_sum - arr[start]; 
            start++; 
        }
        if (curr_sum == sum) { 
            printf ("Sum found between indexes %d and %d", start, i-1); 
            return 1; 
        } 
        if (i < n) 
          curr_sum = curr_sum + arr[i]; 
    } 
    printf("No subarray found"); 
    return 0; 
} 
  
/* ------------- MAIN DRIVER CODE --------------- */ 
int main() 
{ 
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int sum = 23; 
    subArraySum(arr, n, sum); 
    return 0; 
} 