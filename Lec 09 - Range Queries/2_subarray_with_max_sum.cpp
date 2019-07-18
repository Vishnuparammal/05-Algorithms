/* Given an array of n elements, our task is to calculate the maximum subarray sum i.e. the largest 
   possible sum of a sequence of consecutive values in the array. For example, 
   
   For array[] = {-1, 2, 4, -3, 5, 2, -5, 2}, the maximum sum of subarray is from element 1 to 
   element 5 (2 to 2). The value of this maximum sum is 2 + 4 -3 + 5 + 2 = 10. If we took another 
   subarray, the sum will definitely be less than 10. 
   
   So the brute-force method is to check every subarray and update the maximum subarray sum obtained.
   i.e. We will take -1 as start and then add each element till we reach the end. Once this traversal
   is done, we will take 2 as start and then we will do similar steps till we reach the end. This 
   process will go on with 4, -3, 5, 2, -5 and finally 2. Time complexity of this method is O(n^2).
   
   Now the efficient algorithm to solve this problem in O(n) time i.e. in single traversal was 
   given by JB Kadane and hence it is called as - KADANE's ALGORITHM.
   
   for (int i = 0; i < size; i++)
   {
		current_max = max (array[i], current_max + array[i]);
		maximum 	= max (maximum, current_max );
   }
   
   Now how does this algorithm work? Consider the same array taken above as example. 
   
   If current_max and maximum are initially initialized to 0, then 
   For i = 0; current_max = max(-1, -1) i.e. -1 	and 	maximum = max (0, -1) i.e. 0
   So if you observe, if your array contains only negative numbers, then maximum will always be 0.
   So the answer at the end will be 0 i.e. do not take any element in the subarray and 0 is maximum.
   
   But if you want to have atleast one element in the subarray, then this problem reduces to a 
   problem of finding maximum element in the array of negative numbers and in such case, the subarray
   has to contain only that element for maximum sum, because adding another element in subarray will
   surely reduce the sum. If we want this case, we need to run for loop from i = 1 and initialize
   current_max = maximum = array[0]. 
   
   So assuming we are running this loop for positive numbers as well, continuing the former case, 
   For i = 1; current_max = max (2, -1+2) i.e. 2	and		maximum = max (0, 2) i.e. 2
   Now let me tell you what current_max and maximum is. If the array was only two elements long, 
   i.e. {-1, 2}, then maximum sum subarray is 2. So current_max stores the maximum sum of subarray
   upto the array element on which it is at that instant. As current_max will proceed further, 
   the value of current_max will change. Hence to keep track of maximum value of subarray sum, we 
   update another variable maximum. 
   
   Here is the tabular view of the values of these variables, for each iteration:
   
   For i = 				current_max				maximum
   
   	0						-1					   0
   	1						 2					   2
   	2						 6					   6
   	3						 3					   6
   	4						 8					   8
   	5						10					  10
   	6						 5					  10
   	7						 7					  10
   	
   	So the answer is 10.
*/

#include<iostream> 
using namespace std; 

int maxSubArraySum(int arr[], int size) 
{ 
	int current_max, maximum; 
	current_max = maximum = arr[0]; 

	for (int i = 1; i < size; i++) 
	{ 
		current_max = (arr[i] < arr[i]+current_max) ? (arr[i] + current_max) : arr[i];
		maximum     = (maximum < current_max) ? current_max : maximum;
	} 
	return maximum; 
} 

int main() 
{ 
	int a[] = {-2, -3, 4, -1, -2, 1, 5, -3}; 
	int n = sizeof(a)/sizeof(a[0]); 
	int max_sum = maxSubArraySum(a, n); 
	cout << "Maximum contiguous sum is " << max_sum << endl; 
	return 0; 
}
