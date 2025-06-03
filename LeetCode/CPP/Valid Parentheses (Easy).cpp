/*
Source: https://leetcode.com/problems/valid-parentheses/
Title: Valid Parentheses
Diff: Easy

Instruction
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Example
Input: s = "()"
Output: true

Input: s = "()[]{}"
Output: true

Input: s = "(]"
Output: false
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto chr : s) {
            if(chr == '(' || chr == '[' || chr == '{') stk.push(chr);
            else if(stk.size() > 0) {
                if((stk.top() == '(' && chr != ')') ||
                   (stk.top() == '{' && chr != '}') ||
                   (stk.top() == '[' && chr != ']')) return false;
                stk.pop();
            } else {
                return false;
            }
        }
        return stk.empty();
    }
};

int main() {
    Solution solution;
    string s1 = "()";
    bool testcase1 = true;
    assert(solution.isValid(s1) == testcase1);
    string s2 = "()[]{}";
    bool testcase2 = true;
    assert(solution.isValid(s2) == testcase2);
    string s3 = "]";
    bool testcase3 = false;
    assert(solution.isValid(s3) == testcase3);
    cout << "solution has passed all of the defined testcases";

    return 0;
}


/*
struggles i've met while doing this problem:
- i didn't understand the instruction perfectly
- i thought the testcases is more complex, ex: "({{{{)"
- i thought "({{{{)" is a valid expression as the "{{{{" is nullified by the "(" and ")"
*/