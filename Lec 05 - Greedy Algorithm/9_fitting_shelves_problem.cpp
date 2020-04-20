/*
Reference: https://www.geeksforgeeks.org/fitting-shelves-problem/

Given length of wall w and shelves of two lengths m and n,
find the number of each type of shelf to be used and the remaining empty space in the optimal solution
so that the empty space is minimum. The larger of the two shelves is cheaper so it is preferred.
However cost is secondary and first priority is to minimize empty space on wall.

Examples:

Input : w = 24 m = 3 n = 5
Output : 3 3 0
We use three units of both shelves
and 0 space is left.
3 * 3 + 3 * 5 = 24
So empty space  = 24 - 24 = 0
Another solution could have been 8 0 0
but since the larger shelf of length 5
is cheaper the former will be the answer.

Input : w = 29 m = 3 n = 9 
Output : 0 3 2
0 * 3 + 3 * 9 = 27
29 - 27 = 2

Input : w = 24 m = 4 n = 7 
Output : 6 0 0
6 * 4 + 0 * 7 = 24
24 - 24 = 0
*/

#include <iostream>
using namespace std;

void fitting_shelves(int w, int m, int n){
    int minSpace = w;
    int space = w;
    int big,small;

    if(m<n){
        small = m;
        big = n;
    }
    else{
        small = n;
        big = m;
    }

    // start with as many large box as possible
    int i = w/big;
    int j=0;
    while(space != 0 && i>=0){
        space = w;                  // max empty space will be the entire wall
        j = (w - i*big) / small;    // find number of small boxes that can be placed
        space -= i*big + j*small;   // find remaining space
        if (space < minSpace)
            minSpace = space;
        if (space==0)               // if no space left, this is the most optimum solution
            break;
        else
            i--;                    // decrease number of small boxes
    }

    if(m<n)
        cout<<j<<' '<<i<<' '<<space<<endl;
    else
        cout<<i<<' '<<j<<' '<<space<<endl;
    
}

int main(){
    int w, m, n;
    cin>>w>>m>>n;
    fitting_shelves(w, m, n);
    return 0;
}