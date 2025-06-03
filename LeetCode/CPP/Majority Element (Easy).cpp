/*
Source: https://leetcode.com/problems/Majority Element/
Title: Majority Element
Diff: Easy

Instruction
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always 
exists in the array.

Examples
Input: nums = [3,2,3]
Output: 3

Input: nums = [2,2,1,1,1,2,2]
Output: 2

Constraints
n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // O(N) time and O(1) with moore's voting algorithm
        int majority = 0;
        int count = 1;
        for(auto elem: nums) {
            if(majority != elem) count--;
            else count++;

            if(count == 0) {
                majority = elem;
                count = 1;
            }
        }
        return majority;
    }
};

int main() {
    Solution solution;
    
    vector<int> v1 = {3,2,3};
    int testcase1 = 3;
    assert(solution.majorityElement(v1) == testcase1);
    vector<int> v2 = {2,2,1,1,1,2,2};
    int testcase2 = 2;
    assert(solution.majorityElement(v2) == testcase2);
    vector<int> v3 = {1,2,3,4,5,6,6,6,6,6,6,6};
    int testcase3 = 6;
    assert(solution.majorityElement(v3) == testcase3);
    vector<int> v4 = {3,3,4};
    int testcase4 = 3;
    assert(solution.majorityElement(v4) == testcase4);
    cout << "solution has passed all of the defined testcases";

    return 0;
}