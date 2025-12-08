/*
Source: https://leetcode.com/problems/count-square-sum-triples/description
Title: Count Square Sum Triples
Diff: Easy

A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2.
Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.

Example 1:
Input: n = 5
Output: 2
Explanation: The square triples are (3,4,5) and (4,3,5).

Example 2:
Input: n = 10
Output: 4
Explanation: The square triples are (3,4,5), (4,3,5), (6,8,10), and (8,6,10).

Constraints:
1 <= n <= 250
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bruteForceCountTriples(int n) {
        int count = 0;
        for (int i = 3; i <= n; i++) 
            for (int j = 2; j <= n; j++)
                for (int k = 1; k <= n; k++) 
                    if (k*k + j*j == i*i) 
                        count++;

        return count;      
    }

    int countTriples(int n) {
        int count = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = a+1; b <= n; b++) {
                int c = sqrt(a*a + b*b);
                if (c > n) break;
                if (c * c == a*a + b*b) count++;
            }
        }
        return count;      
    }
};

/*
1. bruteForceCountTriples(int n)
is just your classic overdone brute force approach with negligible optimization to starting combination (starts at 3,2,1)
instead of (1,1,1). this function basically checks all combination without an ounce of shame, final time complexity is O(n^3)

2. countTriples(int n)
this is a better bruteforce approach, it ran on O(n^2) compared to previous O(n^3), the improvement comes from the
elimination of c loop, because you just need to check if c formed from a and b is actually an integer or not.
*/