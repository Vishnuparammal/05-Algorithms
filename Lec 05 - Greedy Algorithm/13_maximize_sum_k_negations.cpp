/*
Reference: https://www.geeksforgeeks.org/maximize-array-sun-after-k-negation-operations/

Given an array of size n and a number k.
We must modify array K number of times.
Here modify array means in each operation we can replace any array element arr[i] by -arr[i].
We need to perform this operation in such a way that after K operations, sum of array must be maximum

Examples :

Input : arr[] = {-2, 0, 5, -1, 2} 
        K = 4
Output: 10
// Replace (-2) by -(-2), array becomes {2, 0, 5, -1, 2}
// Replace (-1) by -(-1), array becomes {2, 0, 5, 1, 2}
// Replace (0) by -(0), array becomes {2, 0, 5, 1, 2}
// Replace (0) by -(0), array becomes {2, 0, 5, 1, 2}

Input : arr[] = {9, 8, 8, 5} 
        K = 3
Output: 20
*/

#include <iostream>
#include <algorithm>

using namespace std;

int max_sum_k_negations(int arr[], int n, int k){
    // we will find the lowest number in each step
    // and negate it so that the sum remains max

    // sorting the array initially
    // finding minimum element will be less expensive
    sort(arr, arr + n);

    for(int i=0; i<k; i++){
        int minPos = min_element(arr, arr+n) - arr;
        arr[minPos] *= -1;
    }

    int sum = 0;
    
    for(int i=0; i<n; i++)
        sum += arr[i];
    
    return sum;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    int k;
    cin>>k;
    int sum = max_sum_k_negations(arr, n, k);
    cout<<sum<<endl;
    return 0;
}