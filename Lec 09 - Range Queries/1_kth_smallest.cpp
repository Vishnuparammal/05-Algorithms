//Expected time complexity: O(n)

#include<iostream> 
#include<climits> 
#include<cstdlib> 
using namespace std; 

void swap(int *a, int *b) 
{ 
	int temp = *a; 
	*a = *b; 
	*b = temp; 
} 

/* Standard partition process of QuickSort(). It considers the last element as pivot and moves all smaller element to left of it 
   and greater elements to right.*/ 
int partition(int arr[], int low, int high) 
{ 
	int x = arr[high], i = low; 
	for (int j = low; j <= high - 1; j++)  
		if (arr[j] <= x) 
			swap(&arr[i++], &arr[j]);
			 
	swap(&arr[i], &arr[high]);
	return i; 
}

int randomPartition(int arr[], int low, int high) 
{ 
	int n = high - low + 1; 
	int pivot = rand() % n; 
	swap( &arr[low + pivot], &arr[high]); 
	return partition(arr, low, high); 
} 

// This function returns k'th smallest element in arr[l..r] using QuickSort based method. 
// ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT 
int kthSmallest(int arr[], int low, int high, int k) 
{  
	if (k > 0 && k <= high - low + 1) 				// If k is smaller than number of elements in array
	{ 
		int pos = randomPartition(arr, low, high); 	// Get position of pivot element in sorted array 

		if (pos-low == k-1) 
			return arr[pos]; 
		if (pos-low > k-1) 							// If position is more, recur for left subarray 
			return kthSmallest(arr, low, pos-1, k); 
		else
			return kthSmallest(arr, pos+1, high, k-pos+low-1); 
	} 
	return INT_MAX; 
} 

int main() 
{ 
	int arr[] = {12, 3, 5, 7, 4, 19, 26, 15, 11}; 
	int n = sizeof(arr)/sizeof(arr[0]), k = 3; 
	cout << "K'th smallest element is " << kthSmallest(arr, 0, n-1, k) << endl; 
	return 0; 
}
