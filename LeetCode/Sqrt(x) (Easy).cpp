/*
Source: https://leetcode.com/problems/sqrtx/
Title: Sqrt(x)
Diff: Easy

Instruction
Given a non-negative integer x, compute and return the square root of x.
Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.
Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.

Examples
Input: x = 4
Output: 2

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.

Constraints
0 <= x <= 231 - 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;
        uint64_t i = 1;
        uint64_t result = 1;
        while(result <= x) {
            if(result == x) return i;
            i *= 2;
            if(i > 46341) i = 46341;
            result = i * i;
        }

        while(result >= x) {
            if(result == x) return i;
            i--;
            result = i * i;
        }
        
        return i;
    }
};

int main() {
    Solution solution;

    for(int i = 0; i <= 10; i++) {
        int num = i;
        int testcase = sqrt(num);
        int result =  solution.mySqrt(num);
        assert(solution.mySqrt(num) == testcase);
    }

    for(int i = 10; i <= 100; i+=5) {
        int num = i;
        int testcase = sqrt(num);
        int result =  solution.mySqrt(num);
        assert(solution.mySqrt(num) == testcase);
    }

    int num = INT_MAX;
    int testcase = sqrt(num);
    assert(solution.mySqrt(num) == testcase);

    cout << "solution has passed all of the defined testcases";

    return 0;
}

/*
my struggle/mistake while solving this problem:
- i let "i*i" to be out of its datatype max value
*/