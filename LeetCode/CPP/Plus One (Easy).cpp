/*
Source: https://leetcode.com/problems/plus-one/
Title: Plus One
Diff: Easy

Instruction
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. 
The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain 
any leading 0's.

Increment the large integer by one and return the resulting array of digits.

Example
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].

Constraints
1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int index = size-1;
        // x99999 -> x00000
        while(index >= 0 && digits[index] == 9) digits[index--] = 0;
        // x -> x + 1
        if(index >= 0) digits[index]++;
        else digits.insert(digits.begin(), 1);
        return digits;
    }
};

int constructInt(vector<int> digits) {
    string res;
    for(int i = 0; i < digits.size(); i++) {
        char d = digits[i] + 48;
        res.push_back(d);
    }
   
    return stoi(res);
}

int main() {
    Solution solution;
    vector<int> v1 = {0};
    int testcase1 = 1;
    assert(constructInt(solution.plusOne(v1)) == testcase1);
    vector<int> v2 = {9};
    int testcase2 = 10;
    assert(constructInt(solution.plusOne(v2)) == testcase2);
    vector<int> v3 = {9,9};
    int testcase3 = 100;
    assert(constructInt(solution.plusOne(v3)) == testcase3);
    vector<int> v4 = {1,0,1};
    int testcase4 = 102;
    assert(constructInt(solution.plusOne(v4)) == testcase4);
    cout << "solution has passed all of the defined testcases";

    return 0;
}

/*
my struggle/mistake while solving this problem:
- i let index to be out of bounds while checking digits values
*/