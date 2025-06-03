/*
Source: https://leetcode.com/problems/add-binary/
Title: Add Binary
Diff: Easy

Instruction
Given two binary strings a and b, return their sum as a binary string.

Example
Input: a = "11", b = "1"
Output: "100"

Input: a = "1010", b = "1011"
Output: "10101"

Constraints
1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        // stadardizes format
        if(b.size() > a.size()) {
            string temp = a;
            a = b; 
            b = temp;
        }

        for(int i = b.size()-1; i >= 0; i--) {
            // yyyyy + 1
            if(b[i] == '1') {
                int index = a.size() + i - b.size();

                // x11111 + 1 -> x00000
                while(index >= 0 && a[index] == '1') a[index--] = '0';

                // 0 + 1 -> 1
                if(index >= 0) a[index] = '1';
                // 11111 + 1 = 100000
                else a.insert(0, "1");
            }
        }

        return a;
    }
};

int main() {
    Solution solution;

    string testcase1 = "100";
    assert(solution.addBinary("11","1") == testcase1);
    string testcase2 = "100";
    assert(solution.addBinary("1","11") == testcase2);
    string testcase3 = "10";
    assert(solution.addBinary("1","1") == testcase3);
    string testcase4 = "10101";
    assert(solution.addBinary("1010","1011") == testcase4);
    string testcase5 = "101101";
    assert(solution.addBinary("100001","1100") == testcase5);
    string testcase6 = "0";
    assert(solution.addBinary("0","0") == testcase6);
    string testcase7 = "1";
    assert(solution.addBinary("1","0") == testcase7);
    cout << "solution has passed all of the defined testcases";

    return 0;
}