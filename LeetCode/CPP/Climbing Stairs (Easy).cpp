/*
Source: https://leetcode.com/problems/climbing-stairs/
Title: Climbing Stairs
Diff: Easy

Instruction
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Examples
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Constraints
1 <= n <= 45
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<uint64_t> res = {1, 2};
        int size = res.size();  
        while(n > size) {
            res.push_back(res[size-1] + res[size-2]);
            size++;
        }
        
        return res[n-1];
    }
};

int main() {
    Solution solution;

    int testcase1 = 1;
    assert(solution.climbStairs(1) == testcase1);
    int testcase2 = 2;
    assert(solution.climbStairs(2) == testcase2);
    int testcase3 = 3;
    assert(solution.climbStairs(3) == testcase3);
    int testcase4 = 5;
    assert(solution.climbStairs(4) == testcase4);
    int testcase5 = 8;
    assert(solution.climbStairs(5) == testcase5);
    int testcase6 = 1836311903;
    assert(solution.climbStairs(45) == testcase6);
    
    cout << "solution has passed all of the defined testcases";
    return 0;
}

/*
my struggle/mistake while solving this problem:
- index that i use are out of bounds
*/