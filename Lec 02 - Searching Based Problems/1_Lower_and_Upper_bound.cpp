/*  We need to implement "lower_bound" and "upper_bound" functions
    using binary search. 
*/

#include <bits/stdc++.h>
using namespace std;

// Main Logic
int bs_lower_bound (int arr[], int n, int x) {
    int low = 0;
    int high = n;   // Not n-1
    while (low < high) {
        int mid = (low+high)/2;
        if (x <= arr[mid])
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int bs_upper_bound (int arr[], int n, int x) {
    int low = 0;
    int high = n;   // Not n-1
    while (low < high) {
        int mid = (low+high)/2;
        if (x >= arr[mid])
            low = mid+1;
        else
            high = mid;
    }
    return low;
}

/* ---------------- MAIN DRIVER CODE --------------- */
int main() {
    int arr[] = {1, 7, 8, 10, 13, 20, 25, 30, 33};
    int size = sizeof(arr)/sizeof(arr[0]);

    // Case when key doesn't exist in array
    int* lb1 = lower_bound(arr, arr+size, 12);
    int lb2 = bs_lower_bound(arr, size, 12);
    cout << *lb1 << " " << arr[lb2] << endl;

    int* ub1 = upper_bound(arr, arr+size, 15);
    int ub2 = bs_upper_bound(arr, size, 15);
    cout << *ub1 << " " << arr[ub2] << endl;

    // Case when key exists in array
    int* lb3 = lower_bound(arr, arr+size, 13);
    int lb4 = bs_lower_bound(arr, size, 13);
    cout << *lb3 << " " << arr[lb4] << endl;

    int* ub3 = upper_bound(arr, arr+size, 20);
    int ub4 = bs_upper_bound(arr, size, 20);
    cout << *ub3 << " " << arr[ub4] << endl;
    return 0;
}

/*  OUTPUT:
        13 13
        20 20
        13 13
        25 25
*/
