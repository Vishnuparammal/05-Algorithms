/*

References:
[1] https://www.codesdope.com/course/algorithms-egyptian-fraction/
[2] https://www.geeksforgeeks.org/greedy-algorithm-egyptian-fraction/
[3] https://www.geeksforgeeks.org/fraction/

Every positive fraction can be represented as sum of unique unit fractions.
A fraction is unit fraction if numerator is 1 and denominator is a positive integer
For example 1/3 is a unit fraction.
Such a representation is called Egyptian Fraction.

Egyptian Fraction Representation of 2/3 is 1/2 + 1/6
Egyptian Fraction Representation of 6/14 is 1/3 + 1/11 + 1/231
Egyptian Fraction Representation of 12/13 is 1/2 + 1/3 + 1/12 + 1/156

Input: 
3 4

Output:
1/2 1/4

Solution:
We start by removing the biggest unit fraction possible from the given fraction.
This unit fraction is given by 1 / ceil(denom/num) ... proof in reference [1]
From the fraction left after this step, a biggest unit fraction is removed again
This step repeated till the fraction that remains is itself unit fraction.
i.e recursion base case is num = 1
The proof that, every fraction will reach the base case is also given in [1]

Fractional arithmetic can be revised from reference [3]

We also face a special case when numerator is an integer multiple of denominator
the base case here is num = 0 

We will be revising:
1. classes
2. vectors
3. recursion
4. finding lcm and gcd of a number

*/

#include<iostream>
#include<vector>
#include<cmath>         // for ceil function
using namespace std;

int gcd(int a, int b){ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
} 

class fraction{
    public:
    
    int num;
    int denom;

    fraction(int a, int b){
        num = a;
        denom = b;
    }
    
    fraction subtract(fraction frac){
        int lcm = denom*frac.denom/gcd(denom,frac.denom);
        return fraction(num*(lcm/denom) - frac.num*(lcm/frac.denom), lcm);
    }

    void show(){
        cout<< num<< " / "<< denom<< endl;
    }
};


int egyptianFraction(fraction frac, vector<fraction> &fracArray){
    if (frac.num == 1 || frac.num == 0){
        fracArray.push_back(frac);
        return 1;
    }
    fraction unitFraction(1,ceil( frac.denom / (float)frac.num ));
    fracArray.push_back(unitFraction);
    return 1 + egyptianFraction( frac.subtract(unitFraction), fracArray);
}

int main(){
    fraction frac(0,0);
    cin>> frac.num>> frac.denom;
    vector<fraction> fracArray;
    int count = egyptianFraction(frac, fracArray);
    for(int i=0; i<count; i++)
        fracArray[i].show();
    return 0;
}