/*
Reference: https://www.geeksforgeeks.org/fractional-knapsack-problem/

Given weights and values of n items, we need to put these items
in a knapsack of capacity W to get the maximum total value in the knapsack.

In Fractional Knapsack, we can break items for maximizing the total value of knapsack.
This problem in which we can break an item is also called the fractional knapsack problem.

Input Format:
The first line of the input contains the number 𝑛 of items and the capacity 𝑊 of a knapsack.
The next 𝑛 lines define the values and weights of the items. The 𝑖-th line contains integers 𝑣𝑖 and 𝑤𝑖—the
value and the weight of 𝑖-th item, respectively.

Constraints: 1 ≤ 𝑛 ≤ 103, 0 ≤ 𝑊 ≤ 2 · 106; 0 ≤ 𝑣𝑖 ≤ 2 · 106, 0 < 𝑤𝑖 ≤ 2 · 106 for all 1 ≤ 𝑖 ≤ 𝑛. All the
numbers are integers.

Output Format: Output the maximal value of fractions of items that fit into the knapsack. The absolute
value of the difference between the answer of your program and the optimal value should be at most
10−3. To ensure this, output your answer with at least four digits after the decimal point (otherwise
your answer, while being computed correctly, can turn out to be wrong because of rounding issues).

Sample 1:

Input:
3 50
60 20
100 50
120 30

Output:
180.0000

To achieve the value 180, we take the first item and the third item into the bag.

Sample 2:

Input:
1 10
500 30

Output:
166.6667

Here, we just take one third of the only available item.
*/

#include <iostream>
#include <algorithm>

using namespace std;

struct item{
    int value;
    int weight;
};

bool compare(item a, item b){
    double i = (double)a.value/a.weight;
    double j = (double)b.value/b.weight;
    return i>j;
}

double fractional_knapsack(int w, item items[], int n){
    double total = 0.0;
    
    // we sort the items as per its value by weight (most valueable)
    // we fill the items in this order till the bag is full
    sort(items, items + n, compare);
    int i=0;
    while(w>0){
        // typecasting is important, do not miss it
        total += (double)items[i].value/items[i].weight * min(w, items[i].weight);
        w -= min(w, items[i].weight);
        i++;
    }
    return total;
}

int main(){
    int n;
    cin>>n;
    int w;
    cin>>w;
    item items[n];
    for(int i=0; i<n; i++){
        cin>>items[i].value;
        cin>>items[i].weight;
    }
    double total = fractional_knapsack(w, items, n);
    cout<<total<<endl;
    return 0;
}

