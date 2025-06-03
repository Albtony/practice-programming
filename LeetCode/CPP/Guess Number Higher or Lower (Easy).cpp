/*
Source: https://leetcode.com/problems/guess-number-higher-or-lower/
Title: Guess Number Higher or Lower
Diff: Easy

Instruction
We are playing the Guess Game. The game is as follows:
I pick a number from 1 to n. You have to guess which number I picked.
Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.
You call a pre-defined API int guess(int num), which returns three possible results:

-1: Your guess is higher than the number I picked (i.e. num > pick).
1: Your guess is lower than the number I picked (i.e. num < pick).
0: your guess is equal to the number I picked (i.e. num == pick).
Return the number that I picked.

Examples
Input: n = 10, pick = 6
Output: 6

Input: n = 1, pick = 1
Output: 1

Input: n = 2, pick = 1
Output: 1

Constraints
1 <= n <= 231 - 1
1 <= pick <= n
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans = 0;
    int guessNumber(int n) {
        uint64_t lo = 1;
        uint64_t hi = n;
        uint64_t mid = (hi + lo)/2;      

        while(guess(mid) != 0) {
            if(mid == lo) mid++;
            else if(mid == hi) mid--;

            if(guess(mid) == -1) hi = mid;
            else lo = mid; 

            mid = (hi + lo)/2;      
        }

        return mid;
    }

    int guess(int n) {
        if(ans == n) return 0;
        else if(ans < n) return -1;
        else return 1;
    }
};

int main() {
    Solution solution;

    int upperlimit = 100;
    for(int i = 1; i <= upperlimit; i++) {
        solution.ans = i;
        int testcase = i;
        assert(solution.guessNumber(upperlimit) == testcase);
    }

    solution.ans = 2147483646;
    int testcase = 2147483646;
    assert(solution.guessNumber(INT_MAX) == testcase);
    cout << "solution has passed all of the defined testcases";

    return 0;
}