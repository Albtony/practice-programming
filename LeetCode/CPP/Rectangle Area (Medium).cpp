/*
Source: https://leetcode.com/problems/Rectangle Area/
Title: Rectangle Area
Diff: Medium

Instruction
Given the coordinates of two rectilinear rectangles in a 2D plane, return the total area covered by the two rectangles.
The first rectangle is defined by its bottom-left corner (ax1, ay1) and its top-right corner (ax2, ay2).
The second rectangle is defined by its bottom-left corner (bx1, by1) and its top-right corner (bx2, by2).

Examples
Input: ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
Output: 45

Input: ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2
Output: 16

Constraints
-104 <= ax1 <= ax2 <= 104
-104 <= ay1 <= ay2 <= 104
-104 <= bx1 <= bx2 <= 104
-104 <= by1 <= by2 <= 104
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int temp;
        int res = 0;
        if(ax1 > bx1) {
            temp = ax1; ax1 = bx1; bx1 = temp;
            temp = ax2; ax2 = bx2; bx2 = temp;
            temp = ay1; ay1 = by1; by1 = temp;
            temp = ay2; ay2 = by2; by2 = temp;
        }
        res = abs(ax2 - ax1) * abs(ay2 - ay1) + abs(bx2 - bx1) * abs(by2 - by1);
        if((ax1 <= bx1 && bx1 <= ax2) && !((by2 < ay1) || (by1 > ay2)))
            res -= abs(min(bx2, ax2) - bx1) * abs(max(by1, ay1) - min(by2, ay2));
        return res;
    }
};

int main() {
    Solution solution;

    int testcase1 = 45;
    assert(solution.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) == testcase1);
    int testcase2 = 16;
    assert(solution.computeArea(-2, -2, 2, 2, -2, -2, 2, 2) == testcase2);
    int testcase3 = 4;
    assert(solution.computeArea(0, 0, 0, 0, -1, -1, 1, 1) == testcase3);
    int testcase4 = 16;
    assert(solution.computeArea(-2, -2, 2, 2, -1, -1, 1, 1) == testcase4);
    int testcase5 = 20;
    assert(solution.computeArea(-2, -2, 2, 2, -1, 4, 1, 6) == testcase5);
    int testcase6 = 41;
    assert(solution.computeArea(-5, 4, 0, 5, -3, -3, 3, 3) == testcase6);
    cout << "solution has passed all of the defined testcases";

    return 0;
}

/**
 * Some problems i encounter while solving this problem are:
 * 1. i struggled on isolating some testcase category
 * 2. i struggled on visualizing the rectangles
 */