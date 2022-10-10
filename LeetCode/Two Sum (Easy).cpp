/*
Source: https://leetcode.com/problems/two-sum/
Title: Two Sum
Diff: Easy

Instruction
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Input: nums = [3,2,4], target = 6
Output: [1,2]

Input: nums = [3,3], target = 6
Output: [0,1]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int i = 0; i < nums.size(); i++) {
            // if map find any pair that if summed up with nums[i] result to target
            // return their indexes as array
            if(map.count(target - nums[i])) {
                // i is the index of nums[i]

                // "target - nums[i]" is the value of some element from nums (e.g nums[j])
                // that if summed up with nums[i] result to target (nums[i] + nums[j] = target)

                // the value of map[target-nums[i]] is the index of nums[j] which is j
                return {i, map[target - nums[i]]};
            }
            // maps every num element to their index
            map[nums[i]] = i;
        }

        // return empty array
        return {};
    }
};

// reference: https://leetcode.com/problems/two-sum/discuss/2680899/Super-efficient-and-simple-solution-using-Hashmap