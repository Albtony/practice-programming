/*
Source: https://leetcode.com/problems/Excel Sheet Column Number/
Title: Excel Sheet Column Number
Diff: Easy

Instruction
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
Given an integer n, return true if n is an ugly number.

Examples
Input: n = 6
Output: true
Explanation: 6 = 2 × 3

Input: n = 14
Output: false
Explanation: 14 is not ugly since it includes the prime factor 7.

Constraints
-231 <= n <= 231 - 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if(n == 0) return false;
        while(n % 2 == 0) n /= 2;
        while(n % 3 == 0) n /= 3;
        while(n % 5 == 0) n /= 5;
        if(n == 1 || n == 2 || n == 3 || n == 5) return true;
        else return false;
    }
};

int main() {
    Solution solution;
    
    bool testcase1 = true;
    assert(solution.isUgly(2) == testcase1);
    bool testcase2 = true;
    assert(solution.isUgly(3) == testcase2);
    bool testcase3 = true;
    assert(solution.isUgly(5) == testcase3);
    bool testcase4 = false;
    assert(solution.isUgly(7) == testcase4);
    bool testcase5 = false;
    assert(solution.isUgly(INT_MAX) == testcase5);
    bool testcase6 = false;
    assert(solution.isUgly(-2) == testcase6);
    bool testcase7 = false;
    assert(solution.isUgly(-3) == testcase7);
    bool testcase8 = false;
    assert(solution.isUgly(-5) == testcase8);
    bool testcase9 = false;
    assert(solution.isUgly(-7) == testcase4);
    bool testcase10 = false;
    assert(solution.isUgly(INT_MIN) == testcase10);
    bool testcase11 = true;
    assert(solution.isUgly(1) == testcase11);
    cout << "solution has passed all of the defined testcases";

    return 0;
}