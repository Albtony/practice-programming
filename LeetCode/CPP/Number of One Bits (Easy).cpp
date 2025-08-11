/*
Source: https://leetcode.com/problems/number-of-1-bits/description
Diff: Easy

Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

Example 1:
Input: n = 11
Output: 3
Explanation:
The input binary string 1011 has a total of three set bits.

Example 2:
Input: n = 128
Output: 1
Explanation:
The input binary string 10000000 has a total of one set bit.

Example 3:
Input: n = 2147483645
Output: 30
Explanation:
The input binary string 1111111111111111111111111111101 has a total of thirty set bits.

Constraints:
1 <= n <= 231 - 1

Follow up: If this function is called many times, how would you optimize it?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // we take advantage of bitset to convert n to bits
    // then cast it to string to iterate and count how many 1's exist
    // then we return the value
    int hammingWeight(int n) {
        bitset<32> bits(n);
        string bitString = bits.to_string();
        int num = 0;
        for (char c : bitString) 
            if (c == '1')
                num++;
        return num; 
    }
};

int main () {
    Solution solution;

    assert(solution.hammingWeight(11) == 3);
    assert(solution.hammingWeight(128) == 1);
    assert(solution.hammingWeight(2147483645) == 30);

    cout << "solution has passed all of the defined testcases";
}