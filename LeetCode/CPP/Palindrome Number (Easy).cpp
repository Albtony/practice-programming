/*
Source: https://leetcode.com/problems/palindrome-number/
Title: Palindrome Number
Diff: Easy

Instruction
Given an int64_teger x, return true if x is palindrome int64_teger. An int64_teger is a palindrome when it reads the same backward as forward.
For example, 121 is a palindrome while 123 is not.

Example
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Follow up: Could you solve it without converting the integer to a string? (yes)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int64_t x) {
        string num = to_string(x);
        for(int64_t i = 0; i < num.length()/2; i++) {
            if(num[i] != num[num.length()-i-1]) {
                return false;
            }
        }
        return true;
    }

    bool isPalindromeButWithoutString(int x) {
        if(x < 0) return false;
        int64_t newNum = 0;
        int64_t tempNum = x;
        while(tempNum > 0) {
            int64_t remainder = tempNum % 10;
            int64_t multiplier = 1;
            int64_t processedNum = tempNum;
            while(processedNum >= 10) {
                processedNum /= 10;
                multiplier *= 10;
            }
            newNum += (remainder * multiplier);
            tempNum /= 10;
        }
        
        if(newNum == x) return true;
        else return false;
    }
};

int main () {
    Solution solution;

    // testcases
    int testcase1 = true;
    assert(solution.isPalindrome(1) ==  testcase1);
    assert(solution.isPalindromeButWithoutString(1) ==  testcase1);
    int testcase2 = true;
    assert(solution.isPalindrome(313) ==  testcase2);
    assert(solution.isPalindromeButWithoutString(313) ==  testcase2);
    int testcase3 = false;
    assert(solution.isPalindrome(1234567899) ==  testcase3);
    assert(solution.isPalindromeButWithoutString(1234567899) ==  testcase3);
    int testcase4 = false;
    assert(solution.isPalindrome(10) ==  testcase4);
    assert(solution.isPalindromeButWithoutString(10) ==  testcase4);
    int testcase5 = false;
    assert(solution.isPalindrome(12345321) ==  testcase5);
    assert(solution.isPalindromeButWithoutString(12345321) ==  testcase5);
    cout << "solution has passed all of the defined testcases";

    return 0;
}