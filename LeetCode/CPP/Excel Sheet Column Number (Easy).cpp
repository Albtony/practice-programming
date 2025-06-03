/*
Source: https://leetcode.com/problems/Excel Sheet Column Number/
Title: Excel Sheet Column Number
Diff: Easy

Instruction
Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...

Examples
Input: columnTitle = "A"
Output: 1   

Input: columnTitle = "AB"
Output: 28

Input: columnTitle = "ZY"
Output: 701

Constraints
1 <= columnTitle.length <= 7
columnTitle consists only of uppercase English letters.
columnTitle is in the range ["A", "FXSHRXW"].
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        int len = columnTitle.length() - 1;
        for(int i = len; i >= 0; i--) {
            int num = columnTitle[i] - 64;
            // printf("%c : %d : %d : %d : %d\n", columnTitle[i], len, i, len - i, num);
            res += (num * pow(26, len - i));
        }
        return res;
    }
};

int main() {
    Solution solution;
    
    int testcase1 = 1;
    assert(solution.titleToNumber("A") == testcase1);
    int testcase2 = 2;
    assert(solution.titleToNumber("B") == testcase2);
    int testcase3 = 26;
    assert(solution.titleToNumber("Z") == testcase3);
    int testcase4 = 701;
    assert(solution.titleToNumber("ZY") == testcase4);
    int testcase5 = INT_MAX;
    assert(solution.titleToNumber("FXSHRXW") == testcase5);
    cout << "solution has passed all of the defined testcases";

    return 0;
}