/*
Source: https://leetcode.com/problems/3sum-closest/description/
Diff: Medium

Given an integer array nums of length n and an integer target, find three integers in nums 
such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

Constraints:
3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-104 <= target <= 104
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int best = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) 
                continue;

            int left = i+1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(sum - target) < abs(best - target)) {
                    best = sum;
                }

                if (sum == target) {
                    return sum;
                } else if (sum > target) {
                    right--;
                } else {
                    left++;
                }
            }
        }

        return best;
    }
};

int main() {
    Solution sol;

    assert(sol.threeSumClosest(vector<int> {-1,2,1,-4}, 1) == 2);
    assert(sol.threeSumClosest(vector<int> {0, 0, 0}, 1) == 0);
    cout << "Solution has passed all of the defined testcases";

    return 0;
}

/*
its a modification of 3 sum

instead of finding a collections of qualified triplets, you just want to know the closest
sum your triplets can get to target

so the main idea stays the same, using 1 + 2 pointers to traverse the list
but its slightly easier since you dont have to mind duplicates

and since perfectly equal is the best you can get, you can just return it when you find it
instead of doing extra work to avoid duplicates, so just wire things together again
track the best, and return it!
*/
