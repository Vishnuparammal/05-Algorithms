/*	PROBLEM:
	Given an array of size N which is initialized with all zeros. 
	We are given many range add queries, which should be applied 
	to this array.

	Examples:

	N = 6
	Arr = [0, 0, 0, 0, 0, 0]
	rangeUpdate1 [0, 2], add 100

	Arr = [100, 100, 100, 0, 0, 0]
	rangeUpdate1 [1, 5], add 100

	Arr = [100, 200, 200, 100, 100, 100]
	rangeUpdate1 [2, 3], add 100

	Arr = [100, 200, 300, 200, 100, 100]
	Which is the final updated array.

	We can process each query in constant time using this logic, 
	when a query to add V is given in range [a, b] we will add V 
	to arr[a] and –V to arr[b+1]. Now if we want to get the actual 
	value of the array we will convert the above array into prefix 
	sum array. So in effect, when we add a value V to specific 
	index range of array.
*/

#include <iostream> 
using namespace std; 

// Utility function
void printArray(int arr[], int size) { 
	for (int i = 0; i < size; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

// Main Logic of Code
// Query Handler
void add(int arr[], int size, int start, int end, int value) { 
	arr[start] += value; 
	if (end != size - 1) 
		arr[end + 1] -= value; 
} 

void prefixSum(int arr[], int size) { 
	for (int i = 0; i < size; i++) 
		arr[i + 1] += arr[i]; 
} 

/* ------------ MAIN DRIVER CODE ------------ */
int main() 
{ 
	int N = 6; 

	int arr[N] = {0}; 
 	add(arr, N, 0, 2, 100); 	
	add(arr, N, 1, 5, 100); 	 
	add(arr, N, 2, 3, 100); 
	prefixSum(arr, N); 
	printArray(arr, N); 
	return 0; 
}
