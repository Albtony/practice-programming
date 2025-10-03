/*
Source: https://leetcode.com/problems/contains-duplicate-ii/
Diff: Easy

Given an integer array nums and an integer k, return true if there are two distinct indices i and j 
in the array such that nums[i] == nums[j] and abs(i - j) <= k.

Example 1:
Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:
Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:
Input: nums = [1,2,3,1,2,3], k = 2
Output: false

Constraints:
1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if(m.find(nums[i]) == m.end()) 
                m[nums[i]] = i;
            else if (abs(m[nums[i]] - i) <= k)
                return true;
            else 
                m[nums[i]] = i;
        }
        return false;
    }
};

int main() {
    Solution sol;

    assert(sol.containsNearbyDuplicate(vector<int> {1,4,2,3,1,2}, 3) == true);
    assert(sol.containsNearbyDuplicate(vector<int> {1,2,3,1}, 3) == true);
    assert(sol.containsNearbyDuplicate(vector<int> {1,0,1,1}, 1) == true);
    assert(sol.containsNearbyDuplicate(vector<int> {1,2,3,1,2,3}, 2) == false);
    cout << "solution has passed all of the defined testcases";

    return 0;
}