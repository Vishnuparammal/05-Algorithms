/*

Given a number of activities with start and end time for each,
try to find maximum number of non conflicting activities.

_________________________
| Activity  | Time slot |
|___________|___________|
| A1        | 2 - 4     |
| A2        | 1 - 2     |
| A3        | 3 - 4     |
|___________|___________|

Here, A2 -> A1 can be done. So the answer is 2.

Input:
8
1 3
0 4
1 2
4 6
2 9
5 8
3 5
4 5


Output:
3

<1-2> <3-5> <5-8>

Solution: 

Order of activity is not important
Find MAXIMUM number of activities. (length of activity is not important)
This gives a hint that Greedy Algorithm MAY apply

1. Sort all the activities according to end time in ascending order
2. Pick the first activity
3. Choose the next activity such that its start time is greater than
    or equal to the end time of previous activity.

We will be revising:
1. sorting
2. pairs

*/

#include<iostream>
#include<utility>           // for pair
#include<algorithm>         // for sort

using namespace std;

bool compare( pair<int,int> a, pair<int,int> b){
    return a.second<b.second;
}

int activitySelection( pair<int,int>* time,int n){
    sort(time, time+n, compare);
    int count = 1;
    for(int i=1,j=0; i<n; i++){
        if(time[i].first >= time[j].second){
            count++;
            j=i;
        }
    }
    return count;
}

int main(){
    int n = 0, start = 0, end = 0;
    cin>>n;
    pair<int,int> time[n];
    for(int i=0; i<n; i++){
        cin>>start>>end;
        time[i] = make_pair(start,end);
    }

    cout<< "answer: "<< activitySelection(time,n)<< endl;

    return 0;
}