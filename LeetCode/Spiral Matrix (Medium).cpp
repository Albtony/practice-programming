/*
Source: https://leetcode.com/problems/spiral-matrix/description/
Title: Spiral Matrix
Diff: Medium

Instruction
Given an m x n matrix, return all elements of the matrix in spiral order.

Examples
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

Constraints
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result = {};
        int row = matrix.size();          
        int col = matrix[0].size();       
        int layer = 0;
        int rrow = row, rcol = col;

        while(result.size() < (col * row)) {
            for (int i = layer; i < rcol; i++) 
                result.push_back(matrix[layer][i]);
            for (int i = layer+1; i < rrow; i++) 
                result.push_back(matrix[i][rcol-1]);

            if (abs(rrow - layer) <= 1 || abs(rcol - layer) <= 1) break;

            for (int i = rcol-1; i > layer; i--) 
                result.push_back(matrix[rrow-1][i-1]);
            for (int i = rrow-1; i > layer+1; i--) 
                result.push_back(matrix[i-1][layer]);   
            layer++;
            rrow = row - layer;
            rcol = col - layer;
        }

        return result;
    }
};

int main() {
    Solution solution;

    vector<int> testcase1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<vector<int>> matrix1 = {
		{ 1, 2, 3 },
		{ 8, 9, 4 },
		{ 7, 6, 5 }
	};

    vector<int> testcase2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    vector<vector<int>> matrix2 = {
		{ 1,  2,  3,  4 },
        { 12, 13, 14, 5 },
        { 11, 16, 15, 6 },
        { 10, 9,  8,  7 },
	};

    vector<int> testcase3 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    vector<vector<int>> matrix3 = {
        { 1,  2,  3,  4 },
        { 10, 11, 12, 5 },
        { 9,  8,  7,  6 }
    };

    vector<int> testcase4 = { 1, 2 };
    vector<vector<int>> matrix4 = {
        { 1, 2 }
    };

    vector<int> testcase5 = { 1, 2 };
    vector<vector<int>> matrix5 = {
        { 1 },
        { 2 }
    };

    assert(solution.spiralOrder(matrix1) == testcase1);
    assert(solution.spiralOrder(matrix2) == testcase2);
    assert(solution.spiralOrder(matrix3) == testcase3);
    assert(solution.spiralOrder(matrix4) == testcase4);
    assert(solution.spiralOrder(matrix5) == testcase5);
    cout << "solution has passed all of the defined testcases";
}

/**
 * better solution
 * same approach, better exeution: https://leetcode.com/problems/spiral-matrix/solutions/3503815/beginner-friendly-simple-fastest-c-explanation-optimal-solution-beats-100/
 * dfs approach: https://leetcode.com/problems/spiral-matrix/solutions/3503387/c-beats-100-dfs-clean-codes/
 * diff approach: https://leetcode.com/problems/spiral-matrix/solutions/3503186/better-than-100-in-runtime-easiest-c-solution/
 */