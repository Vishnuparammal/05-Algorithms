/*
Reference: https://www.geeksforgeeks.org/assign-mice-holes/

There are N Mice and N holes are placed in a straight line.
Each hole can accommodate only 1 mouse.
A mouse can stay at his position,
move one step right from x to x + 1,
or move one step left from x to x -1.
Any of these moves consumes 1 minute.
Assign mice to holes so that
the time when the last mouse gets inside a hole is minimized.

Examples:

Input : positions of mice are:
          4 -4 2
        positions of holes are:
          4 0 5
Output :  4
Assign mouse at position x = 4 to hole at 
position x = 4 : Time taken is 0 minutes 
Assign mouse at position x=-4 to hole at 
position x = 0 : Time taken is 4 minutes 
Assign mouse at position x=2 to hole at 
position x = 5 : Time taken is 3 minutes 
After 4 minutes all of the mice are in the holes.
Since, there is no combination possible where
the last mouse's time is less than 4, 
answer = 4.

Input :  positions of mice are:
        -10, -79, -79, 67, 93, -85, -28, -94 
          positions of holes are:
         -2, 9, 69, 25, -31, 23, 50, 78 
Output : 102
*/

#include <iostream>
#include <algorithm>

using namespace std;

int assign_mice_to_holes(int mice[], int holes[], int n){
    int time = -1;
    // we can assign every mouse to its nearest hole
    // sort the array and find
    // the max time taken out of all pairs
    sort(mice, mice + n);
    sort(holes, holes + n);
    for(int i=0; i<n; i++){
        if( abs(mice[i] - holes[i]) > time ){
            time = abs(mice[i] - holes[i]);
        }
    }
    return time;
}

int main(){
    int n;
    cin>>n;
    int mice[n];
    int holes[n];
    for(int i=0; i<n; i++)
        cin>>mice[i];
    for(int i=0; i<n; i++)
        cin>>holes[i];

    int time = assign_mice_to_holes(mice, holes, n);
    cout<<time<<endl;
    return 0;
}