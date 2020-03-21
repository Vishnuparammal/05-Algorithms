/*
This problem is an extension of activity_selection_problem

Given N jobs where every job is represented by following three elements of it.
Start Time
Finish Time
Profit or Value Associated (>= 0)
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.

Input:

4
1 2 50
3 5 20
6 19 100
2 100 200


Output:
250

We can get the maximum profit by scheduling jobs 1 and 4.
Note that there is longer schedules possible Jobs 1, 2 and 3 
but the profit with this schedule is 20+50+100 which is less than 250. 

Solution:
Initially sort all jobs according to end time
Now, we will surely do job J1
The question is, should we do job Ji or not
If we decide not to do job Ji,
our profit is the same as profit til job J(i-1) ... (1)
If we decide to do job Ji, we need to find a previous job Jk that does not conflict with Ji
our profit now is the sum of profit till job Jk + profit of job Ji ... (2)
we compare the profits (1) and (2) and decide whether to do job Ji or not depending on which profit is greater
repeat this for every i

This problem is a combination of greedy and dynamic programming

We will be revising:
1. sorting
2. binary search
3. dynamic programming
*/

#include<iostream>
#include<algorithm>
using namespace std;

struct node{
    int start;
    int end;
    int profit;
};

bool compare(node a, node b){
    return(a.end<b.end);
}


// using the linear search makes this code an n^2 algorithm
int nonConflict(node job[], int n){
    for(int i=n-1;i>=0;i--)
        if(job[i].end <= job[n].start)
            return i;
    return -1;
}

// using the binary search makes this code an nlogn algorithm
/*
int nonConflict(node job[], int n) {
	int lo = 0, hi = n - 1; 
	while (lo <= hi) { 
		int mid = (lo + hi) / 2; 
		if (job[mid].end <= job[n].start) { 
			if (job[mid + 1].end <= job[n].start) 
				lo = mid + 1; 
			else
				return mid; 
		} 
		else
			hi = mid - 1; 
	} 
	return -1; 
}
*/

int jobSchedule(node job[], int n){ 
    sort(job, job+n, compare);
    int* profitArr = new int[n];
    profitArr[0] = job[0].profit;
    for(int i=1; i<n; i++){
        int k = nonConflict(job, i);
        if (k != -1)
            profitArr[i] = max(profitArr[i-1], profitArr[k] + job[i].profit);
        else
            profitArr[i] = max(profitArr[i-1], job[i].profit);
    }
    return(profitArr[n-1]);
}

int main(){
    int n;
    cin>>n;
    node job[n];

    for(int i=0; i<n; i++){
        cin>>job[i].start>>job[i].end>>job[i].profit;
    }
    
    cout<< jobSchedule(job,n)<<endl;


    return 0;
}