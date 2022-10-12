/*
Source: https://leetcode.com/problems/increasing-triplet-subsequence/
Title: Longest Common Prefix
Diff: Easy

Instruction
Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and 
nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

Example
Input: nums = [1,2,3,4,5]
Output: true
Explanation: Any triplet where i < j < k is valid.

Input: nums = [5,4,3,2,1]
Output: false
Explanation: No triplet exists.

Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.

Constraints
1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // we just need to find 3 elements that is strictly increasing
    bool increasingTriplet(vector<int>& nums) {
        // if total element is less than 3, return false as we need at least 3 elements
        int size = nums.size();
        if(size < 3) return false;

        int left = INT_MAX;
        int mid = INT_MAX;

        // find the 3 elements with greedy method
        // smallest known element is left
        // anything bigger than left is mid
        // if we find another element that is bigger than mid, return true, as we already found the 3 elements
        for(int i = 0; i < size; i++) {
            if(nums[i] > mid) return true;
            if(nums[i] < mid && nums[i] > left) mid = nums[i];
            if(nums[i] < left) left = nums[i];
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> v1 = {20, 100, 10, 12, 5, 13};
    bool testcase1 = true;
    assert(solution.increasingTriplet(v1) == testcase1);
    vector<int> v2 = {5,4,3,2,1};
    bool testcase2 = false;
    assert(solution.increasingTriplet(v2) == testcase2);
    vector<int> v3 = {2,1,5,0,4,6};
    bool testcase3 = true;
    assert(solution.increasingTriplet(v3) == testcase3);
    vector<int> v4 = {1,2,1,2,1,2,1};
    bool testcase4 = false;
    assert(solution.increasingTriplet(v4) == testcase4);
    cout << "solution has passed all of the defined testcases";
    return 0;
}

// Reference : https://leetcode.com/problems/increasing-triplet-subsequence/discuss/2688292/C%2B%2B-EASY-AND-SIMPLE-O(N)-TIME-AND-O(1)-SPACE
/*
    // i used dynamic programming of longest increasing subsequence
    // but that is too complex for the current problem (O(n^2)) because its too general
    // we can solve this problem more efficient (O(n)) with more clever tactics
    bool increasingTriplet(vector<int>& nums) {
        int size = nums.size();
        // dp data
        int lis[size];
        fill_n(lis, size, 1);
        // start from back to front, scan from i to back to find lis
        for(int i = size-1; i >= 0; i--) {
            for(int j = i+1; j < size; j++) {
                // printf("front: %d | back: %d", nums[i], nums[j]);
                if(nums[i] < nums[j]){
                    lis[i] = max(lis[i], 1+lis[j]);
                    // cout << " | yes";
                } 
                // cout << endl;
                if(lis[i] >= 3) return true;
            }
        }
        return false;
    }
*/  