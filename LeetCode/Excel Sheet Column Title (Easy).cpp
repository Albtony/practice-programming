/*
Source: https://leetcode.com/problems/excel-sheet-column-title/
Title: excel-sheet-column-title
Diff: Easy

Instruction
Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...


Examples
Input: columnNumber = 1
Output: "A"

Input: columnNumber = 28
Output: "AB"

Input: columnNumber = 701
Output: "ZY"

Constraints
1 <= columnNumber <= 231 - 1
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string title = "";

        while(columnNumber != 0) {
            --columnNumber;
            int remainder = columnNumber % 26;
            string stringedChar(1, intToChar(remainder));
            title.insert(0, stringedChar);
            columnNumber /= 26;
        }
        
        return title;
    }

    char intToChar(int num) {
        return num + 65;
    }
};

int main() {
    Solution solution;

    string testcase1 = "A";
    assert(solution.convertToTitle(1) == testcase1);
    string testcase2 = "Z";
    assert(solution.convertToTitle(26) == testcase2);
    string testcase3 = "AB";
    assert(solution.convertToTitle(28) == testcase3);
    string testcase4 = "ZY";
    assert(solution.convertToTitle(701) == testcase4);    
    
    cout << "solution has passed all of the defined testcases";

    return 0;
}

/*
my struggle/mistake while solving this problem:
- i have difficullties setting alphabet to start on 1 instead of 0 for every loop
*/