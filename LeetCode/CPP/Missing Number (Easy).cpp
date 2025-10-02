/*
Source: https://leetcode.com/problems/missing-number/description/
Diff: Easy

Given an array nums containing n distinct numbers in the range [0, n], return the only number in 
the range that is missing from the array.

Example 1:
Input: nums = [3,0,1]
Output: 2

Explanation:
n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number 
in the range since it does not appear in nums.

Example 2:
Input: nums = [0,1]
Output: 2

Explanation:
n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number 
in the range since it does not appear in nums.

Example 3:
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8

Explanation:
n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number 
in the range since it does not appear in nums.

Constraints:
n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
All the numbers of nums are unique.

Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(const vector<int>& nums) {
        int n = nums.size();
        return ((n+1)*n)/2 - reduce(nums.begin(), nums.end());  
    }

    int betterMissingNumber(const vector<int>& nums) {
        int res = 0;
        for (int i = 0; i <= nums.size(); i++) {
            res ^= i ^ nums[i];
        }

        return res;
    }
};

int main() {
    Solution sol;

    assert(sol.missingNumber(vector<int> {0,2}) == 1);
    assert(sol.missingNumber(vector<int> {0,1,2}) == 3);
    assert(sol.missingNumber(vector<int> {0,1,3}) == 2);
    assert(sol.missingNumber(vector<int> {0,2,3}) == 1);
    assert(sol.missingNumber(vector<int> {1,2}) == 0);
    cout << "solution has passed all of the defined testcases";


    return 0;
}

/*
write up

to find the missing one, we can calculate via arithmetics, where the total sum of an arithmetic set is (a + un) * n/2 
then we sum the vector up and substract them to single out the missing number

another better solution is to use xor trick with for loop index,
we can generate 0-n via for loop i=0 to n, then we can cancel anything that exist via xor,
since a ^ a is 0, and a ^ 0 is a, meaning, we are xor-ing the incomplete sequence with a complete sequence
and by xoring both of them, it will single out the missing number

the xor approach is better because there is no overflow risk
*/