/*
Source: https://leetcode.com/problems/pascals-triangle/description/
Diff: Easy

Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]

Constraints:
1 <= numRows <= 30
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result = {{1}};
        vector<int> currRow = result[0];
        for (int i = 1; i < numRows; i++) {
            currRow = generateRows(currRow, i);
            result.push_back(currRow);
        }

        return result;
    }

    // basically, generate next row from prev row
    // first and last is always one, due for them not being summed by any other element
    // only 1 to n-1 elems are needed to be generated, hence the loop condition
    vector<int> generateRows(vector<int> prevRow, int rowNum) {
        vector<int> newRow = {1};
        for (int i = 1; i <= rowNum-1; i++) 
            newRow.push_back(prevRow[i-1]+prevRow[i]);
        newRow.push_back(1);
        return newRow;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> expected0 = {
        {1}
    };
    vector<vector<int>> expected1 = {
        {1},
        {1, 1}
    };
    vector<vector<int>> expected2 = {
        {1},
        {1, 1},
        {1, 2, 1}
    };
    vector<vector<int>> expected5 = {
        {1},
        {1, 1},
        {1, 2, 1},
        {1, 3, 3, 1},
        {1, 4, 6, 4, 1}
    };
    assert(solution.generate(1) == expected0);
    assert(solution.generate(2) == expected1);
    assert(solution.generate(3) == expected2);
    assert(solution.generate(5) == expected5);

    cout << "solution has passed all of the defined testcases\n";
}