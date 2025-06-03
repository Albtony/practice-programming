/*
Source: https://leetcode.com/problems/single-number/
Title: Single Number
Diff: Easy

Instruction
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.

Examples
Input: nums = [2,2,1]
Output: 1

Input: nums = [4,1,2,1,2]
Output: 4

Input: nums = [1]
Output: 1

Constraints
1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto elem: nums) 
            map[elem]++;
        for(auto elem: map) 
            if(elem.second == 1) 
                return elem.first;
        return -1;
    }
};

int main() {
    Solution solution;

    vector<int> v1 = {2,2,1};
    int testcase1 = 1;
    assert(solution.singleNumber(v1) == testcase1);
    vector<int> v2 = {2};
    int testcase2 = 2;
    assert(solution.singleNumber(v2) == testcase2);
    vector<int> v3 = {4,1,2,1,2};
    int testcase3 = 4;
    assert(solution.singleNumber(v3) == testcase3);
    cout << "solution has passed all of the defined testcases";

    return 0;
}

/*
a better solution for this specific problem is doing it with XOR operator:

a ^ a = 0
0 ^ b = b
a ^ a ^ b = b ^ a ^ a = a ^ b ^ a = b

so, because every non-unique element always occurs in pairs, we can use XOR properties to single out the unique one with
ans = 0;
for(auto elem: nums)
    ans ^= elem;
return ans;

reference: https://leetcode.com/problems/single-number/discuss/1771720/C%2B%2B-EASY-SOLUTIONS-(SORTING-XOR-MAPS-(OR-FREQUENCY-ARRAY))
*/