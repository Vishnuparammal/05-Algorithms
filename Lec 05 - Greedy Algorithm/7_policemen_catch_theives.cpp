/*
Reference: https://www.geeksforgeeks.org/policemen-catch-thieves/

Given an array of size n that has the following specifications:
1. Each element in the array contains either a policeman or a thief.
2. Each policeman can catch only one thief.
3. A policeman cannot catch a thief who is more than K units away from the policeman.
We need to find the maximum number of thieves that can be caught.

Input : arr[] = {'P', 'T', 'T', 'P', 'T'},
            k = 1.
Output : 2.
Here maximum 2 thieves can be caught, first
policeman catches first thief and second police-
man can catch either second or third thief.

Input : arr[] = {'T', 'T', 'P', 'P', 'T', 'P'}, 
            k = 2.
Output : 3.

Input : arr[] = {'P', 'T', 'P', 'T', 'T', 'P'},
            k = 3.
Output : 3.
*/
#include <iostream>

using namespace std;

int policemen_theives(char arr[], int n, int k){
    int police = 0;
    int thief = 0;
    int catches = 0;
    while(police < n && thief < n ){

        // get the location of police and thief
        while( arr[police] != 'P' && police < n) police++;
        while( arr[thief] != 'T' && thief < n) thief++;

        // if index within limits and police close to thief catch him
        if (police >=n || thief >=n)
            break;
        else if( abs(police - thief) <= k){
            catches++;
            police++;
            thief++;
        }
        // if police not in range, increment the lower one
        else if (police < thief)
            police++;
        else
            thief++;
    }
    return catches;
}

int main(){
    int k, n;
    cin>>k>>n;
    char arr[n] = {' '};
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int catches = policemen_theives(arr, n, k);
    cout<<catches<<'\n';
    return 0;
}