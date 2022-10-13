/*
Source: https://leetcode.com/problems/search-insert-position/
Title: Search Insert Position
Diff: Easy

Instruction
Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

Example
Input: nums = [1,3,5,6], target = 5
Output: 2

Input: nums = [1,3,5,6], target = 2
Output: 1

Input: nums = [1,3,5,6], target = 7
Output: 4

Constraints
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0; int high = nums.size()-1; int res = 0;
        while(high - low > 1) {
            int mid = (high + low) / 2;
            if(nums[mid] < target) low = mid + 1;
            else high = mid;
        }
        
        if(nums[low] == target) return low;
        else if(nums[high] == target) return high;

        if(target < nums[low]) return low;
        else if (nums[high] < target) return high + 1;
        else return low + 1;
    }
};

int main() {
    Solution solution;
    
    vector<int> v = {1,3,5,6};
    int testcase1 = 2;
    assert(solution.searchInsert(v, 5) == testcase1);
    int testcase2 = 1;
    assert(solution.searchInsert(v, 2) == testcase2);
    int testcase3 = 4;
    assert(solution.searchInsert(v, 7) == testcase3);
    int testcase4 = 0;
    assert(solution.searchInsert(v, 0) == testcase4);
    cout << "solution has passed all of the defined testcases";

    return 0;
}

/*
my struggle while solving this problem:
- i was not very thorough on defining my if-else statement
- i wasted so much time tweaking and testing my if-else without too much thought
*/