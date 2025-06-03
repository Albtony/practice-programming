/*
Source: https://leetcode.com/problems/largest-perimeter-triangle/
Title: Largest Perimeter Triangle
Diff: Easy

Instruction
Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. 
If it is impossible to form any triangle of a non-zero area, return 0.

Example
Input: nums = [2,1,2]
Output: 5

Input: nums = [1,2,1]
Output: 0

Constraints
3 <= nums.length <= 104
1 <= nums[i] <= 106
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
            sort(nums.begin(), nums.end());                 // sort the array
            for(int i=nums.size()-3; i>=0; i--){            // traverse from n-3 to 0
                if(nums[i]+nums[i+1] > nums[i+2]) {         // if at any instant a + b > c, return perimenter (a+b+c)
                    return  nums[i]+nums[i+1]+nums[i+2];    // a=nums[i], b=nums[i+1], c=nums[i+2];
                }
            }
            return 0;                                       // else return 0
    }
};

int main() {
    Solution solution;

    vector<int> v1 = {2,1,2};
    int testcase1 = 5;
    assert(solution.largestPerimeter(v1) == testcase1);
    vector<int> v2 = {1,2,1};
    int testcase2 = 0;
    assert(solution.largestPerimeter(v2) == testcase2);
    vector<int> v3 = {6,3,3,2};
    int testcase3 = 8;
    assert(solution.largestPerimeter(v3) == testcase3);
    cout << "solution has passed all of the defined testcases\n";

    return 0;
}

/*
my struggles while solving this problem:
- i thought sorting array is bad because of the large input size
- because of that, i waste time on trying another way without using sort
*/