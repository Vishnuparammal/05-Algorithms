// Q. Given an array arr[] of size n, find a subarray of size k such that its average is least.

#include <iostream> 
using namespace std; 

// Prints beginning and ending indexes of subarray with minimum average of size k
void findMinAvgSubarray(int arr[], int n, int k) 
{ 
	if (n < k) 								// k must be smaller than or equal to n 
		return; 
		
	int start_index = 0; 					// Initialize beginning index of result
	
	int curr_sum = 0; 						// Compute sum of first subarray of size k 
	for (int i = 0; i < k; i++) 
		curr_sum += arr[i]; 

	int min_sum = curr_sum; 				// Initialize minimum sum as current sum 

	for (int i = k; i < n; i++)				// Traverse from (k+1)'th element to n'th element  
	{  
		curr_sum += arr[i] - arr[i - k];	// Add current item and remove first item of previous subarray

		if (curr_sum < min_sum) 
		{ 			
			min_sum = curr_sum; 			// Update result if needed 
			start_index = (i - k + 1); 
		} 
	} 

	cout << "Subarray between [" << start_index << ", "
		<< start_index + k - 1 << "] has minimum average" << endl; 
} 

int main() 
{ 
	int arr[] = { 3, 7, 90, 20, 10, 50, 40 }; 
	int k = 3;
	int n = sizeof arr / sizeof arr[0]; 
	findMinAvgSubarray(arr, n, k); 
	return 0; 
} 

