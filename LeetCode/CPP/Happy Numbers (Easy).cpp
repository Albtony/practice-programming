/*
Source: https://leetcode.com/problems/happy-number/description/
Title: Happy Number
Diff: Easy

Instruction
Write an algorithm to determine if a number n is happy.
A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

Example 1:
Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Example 2:
Input: n = 2
Output: false

Constraints:
1 <= n <= 231 - 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        while (n > 9) {
            n = sumOfSquares(n);
        } 

        return n == 1 || n == 7;
    }

    bool isHappyWithCycleCheck(int n) {
        unordered_set<int> seen;
        while (n != 1 || !seen.count(n)) {
            seen.insert(n);
            n = sumOfSquares(n);
        } 

        return n == 1;
    }

    unsigned long long sumOfSquares(unsigned long long n) {
        unsigned long long sum = 0;
        while (n > 0) {
            int digit = n%10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
};

int main() {
    Solution sol;

    assert(sol.isHappy(1) == true);
    assert(sol.isHappy(2) == false);
    assert(sol.isHappy(7) == true);
    assert(sol.isHappy(19) == true);
    assert(sol.isHappy(123) == false);
    cout << "solution has passed all of the defined testcases";

    return 0;
}