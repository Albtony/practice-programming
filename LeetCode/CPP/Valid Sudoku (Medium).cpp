/*
Source: https://leetcode.com/problems/valid-sudoku/description/
Diff: Medium

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according 
to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:
A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.

Example 1:
Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true

Example 2:
Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

Constraints:
board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool isValid = true;
        set<int> seen;
        vector<vector<set<int>>> gridSeen(3, vector<set<int>>(3)); 

        for (int i = 0; i < 9; i++) {
            seen.clear();
            for (int j = 0; j < 9; j++) {
                int digit = board[i][j] - '0';
                if (isdigit(board[i][j])) {
                    if (seen.find(digit) == seen.end()) 
                        seen.insert(digit);
                    else 
                        return false;
                    if (gridSeen[i/3][j/3].find(digit) == gridSeen[i/3][j/3].end())
                        gridSeen[i/3][j/3].insert(digit);
                    else 
                        return false;
                }
            }
        }
        
        for (int i = 0; i < 9; i++) {
            seen.clear();
            for (int j = 0; j < 9; j++) {
                int digit = board[j][i] - '0';
                if (isdigit(board[j][i])) {
                    if (seen.find(digit) == seen.end()) 
                        seen.insert(digit);
                    else 
                        return false;
                }
            }
        }

        return true;
    }

    bool isValidSudokuPlus(vector<vector<char>>& board) {
        int row[9] = {};
        int col[9] = {};
        int box[9] = {};

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                int digit = board[i][j] - '0';
                int mask = 1 << digit;
                int k = (i / 3) * 3 + (j / 3);

                if ((row[i] & mask) || (col[j] & mask) || (box[k] & mask))
                    return false;
                row[i] |= mask;
                col[j] |= mask;
                box[k] |= mask;
            }
        }

        return true;
    }
};

/*
assumptions:
1. there exist a set called digit which includes integers from 1 to 9
2. the 9 x 9 grid is divided into 3 x 3 non-overlapping quadrant with a total of 9 quadrants

requirements that must be satisfied:
1. each horizontal line must have at most 1 occurence of any element on set digit
2. each vertical line must have at most 1 occurence of any element on set digit
3. each quadrant must have at most 1 occurence of any element on set digit

in order for a sudoku to be valid (doesn't mean its solvable) we need to satisfy the condition above
to satisfy condition one, we can just iterate over each horizontal line and keep trakcs of the item encountered,
then return false if a non unique element is found
same with condition two, just iterate over each vertical line and keep tracks of the set like how we satisfy condition one
for condition 3, its a little bit more complex since its a 2d area, not a 1d line, so we need to do some indices mapping
to map the correct sets of is and js to the correct quadrant

we use a 2d 3 x 3 vector of sets to check whether the quadrant satisfy condition 3, then we map i and j into the 
respective quadrant by dividing them by 3, where item of grid[i][j] belongs to quadrant[i/3][j/3]

this way, we can merge the check of condition 3 with the nested for loop and check the requirement of each quadrant
simultaneusly with either the horizontal or the vertical checks, of which if we find any non unique element, we
can short circuit and return false.
*/