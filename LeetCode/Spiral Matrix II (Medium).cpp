/*
Source: https://leetcode.com/problems/spiral-matrix-ii/description/
Title: Spiral Matrix II
Diff: Medium

Instruction
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Examples
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Input: n = 1
Output: [[1]]

Constraints
1 <= n <= 20
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int size = n;
        vector<vector<int>> result(n, vector<int> (n, 0));

        int counter = 1;
        int rowStart = 0, rowEnd = n - 1;
        int colStart = 0, colEnd = n - 1;

        while ( counter <= n*n ) {
            for (int i  = colStart; i <= colEnd; i++)
                result[rowStart][i] = counter++;
            rowStart++;
            for (int i = rowStart; i <= rowEnd; i++) 
                result[i][colEnd] = counter++;
            colEnd--;
            for (int i = colEnd; i >= colStart; i--)
                result[rowEnd][i] = counter++;
            rowEnd--;
            for (int i = rowEnd; i >= rowStart; i--)
                result[i][colStart] = counter++;
            colStart++;
        }
        
        return result;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> testcase1 = {
		{ 1 }
	};

    vector<vector<int>> testcase2 = {
		{ 1, 2 },
        { 4, 3 }
	};

    vector<vector<int>> testcase3 = {
		{ 1, 2, 3 },
		{ 8, 9, 4 },
		{ 7, 6, 5 }
	};

    vector<vector<int>> testcase4 = {
		{ 1,  2,  3,  4 },
        { 12, 13, 14, 5 },
        { 11, 16, 15, 6 },
        { 10, 9,  8,  7 },
	};

    
    vector<vector<int>> testcase5 = {
        { 1,  2,  3,  4,  5,  6 },
        { 20, 21, 22, 23, 24, 7 },
        { 19, 32, 33, 34, 25, 8 },
        { 18, 31, 36, 35, 26, 9 },
        { 17, 30, 29, 28, 27, 10 },
        { 16, 15, 14, 13, 12, 11 },
    };

    assert(solution.generateMatrix(1) == testcase1);
    assert(solution.generateMatrix(2) == testcase2);
    assert(solution.generateMatrix(3) == testcase3);
    assert(solution.generateMatrix(4) == testcase4);
    assert(solution.generateMatrix(5) == testcase5);
    cout << "solution has passed all of the defined testcases";
}

/**
 * better solution
 * 99% people use this approach
 */