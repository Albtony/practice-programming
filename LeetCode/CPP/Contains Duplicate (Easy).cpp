/*
Given an integer array nums, return true if any value appears at least twice in the array, 
and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true

Explanation:
The element 1 occurs at the indices 0 and 3.

Example 2:
Input: nums = [1,2,3,4]
Output: false

Explanation:
All elements are distinct.

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

Constraints:
1 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<int> exist;
    bool containsDuplicate(vector<int>& nums) {
        for(auto elem : nums) {
            if (exist.contains(elem)) return true;
            exist.insert(elem);
        }

        return false;
    }
};

int main() {
    Solution sol;

    assert(sol.containsDuplicate(vector<int> {1}) == false);
    assert(sol.containsDuplicate(vector<int> {1,1}) == true);
    assert(sol.containsDuplicate(vector<int> {1,2}) == false);
    assert(sol.containsDuplicate(vector<int> {1,2,3}) ==  false);
    assert(sol.containsDuplicate(vector<int> {1,2,2,3}) == true);
    assert(sol.containsDuplicate(vector<int> {1,2,3,3}) == true);
    assert(sol.containsDuplicate(vector<int> {1,1,2,3,3}) == true);
    assert(sol.containsDuplicate(vector<int> {1,2,3,1}) == true);
    cout << "solution has passed all of the defined testcases";

    return 0;
}

/*
Write up

its an easy problem, just keep tracks of which number you have seen and return if you encounter it more than one time
using unordered_map is great here since its o(1) at insertion time, but its o(n) memory tho

for o(1) memory, i think sorting is the best here but with the downside being o(nlogn) time complexity
*/