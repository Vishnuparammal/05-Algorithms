/*
Reference: https://www.geeksforgeeks.org/minimum-swaps-bracket-balancing/

You are given a string of 2N characters consisting of N ‘[‘ brackets and N ‘]’ brackets.
A string is considered balanced if it can be represented in the for S2[S1] where S1 and S2 are balanced strings.
We can make an unbalanced string balanced by swapping adjacent characters.
Calculate the minimum number of swaps necessary to make a string balanced.

Examples:

Input  : []][][
Output : 2
First swap: Position 3 and 4
[][]][
Second swap: Position 5 and 6
[][][]

Input  : [[][]]
Output : 0
String is already balanced.
*/
#include <iostream>
#include <string>

using namespace std;

int min_swaps_bracket_balancing(string s){
    int swaps = 0;
    int swapPos = 0;
    int bracket = 0;
    for(int i=0; i<s.length(); i++, swapPos++){

        if(s[i]=='[') bracket++;
        else if(s[i]==']') bracket--;
        
        // bracket unbalanced if more ] than [
        if (bracket < 0){

            // find position of next [
            while(s[swapPos] != '[' && swapPos < s.length()) swapPos++;

            // since we can swap only adjacent positions
            // we need to swaps twice if swapping position 2 and 4 (3-4, 2-3)
            s[i] = '[';
            s[swapPos] = ']';
            swaps += swapPos - i;

            // we had bracket = -1 as there was ] at this position
            // but now we should have 1 here as there is [ at this pos
            // to compensate for this, we add 2
            bracket += 2;
        }
    }
    return swaps;
}

int main(){
    string s;
    cin>>s;
    int swaps = min_swaps_bracket_balancing(s);
    cout<<swaps<<endl;
    return 0;
}