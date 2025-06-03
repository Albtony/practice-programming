
/*
Source: https://leetcode.com/problems/remove-element/description/
Title: Remove Element
Diff: Easy

Instruction
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. 
Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of 
nums are not important as well as the size of nums. Return k.

Example
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).

Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).

Constraints
0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        // O(n) time O(1) space, 2 pointers approach
        int removeElement(vector<int>& nums, int val) {
            int writeIndex = 0;
            int curr = 0;
            while(curr < nums.size() && writeIndex < nums.size()){
                if(nums[curr] != val) {
                    if(curr != writeIndex) { 
                        nums[writeIndex] = nums[curr];
                    }
                    writeIndex++;
                }
                curr++;
            }
            return nums.size() - (nums.size() - writeIndex);
        }

        // same performances but benefits from c++ stdl optimization
        int betterRemoveElement(vector<int>& nums, int val) {
            nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
            return(nums.size());
        }
};

int main() {
    Solution solution;

    vector<int> nums1 = {3,2,2,3};
    int val1 = 3;
    int k1 = solution.removeElement(nums1, val1);
    vector<int> expected1 = {2,2};
    sort(nums1.begin(), nums1.begin() + k1);
    assert(k1 == expected1.size());
    for (int i = 0; i < k1; i++) {
        assert(nums1[i] == expected1[i]);
    }

    vector<int> nums2 = {0,1,2,2,3,0,4,2};
    int val2 = 2;
    int k2 = solution.removeElement(nums2, val2);
    vector<int> expected2 = {0,0,1,3,4};
    sort(nums2.begin(), nums2.begin() + k2);
    assert(k2 == expected2.size());
    for (int i = 0; i < k2; i++) {
        assert(nums2[i] == expected2[i]);
    }

    vector<int> nums3 = {};
    int val3 = 2;
    int k3 = solution.removeElement(nums3, val3);
    vector<int> expected3 = {};
    sort(nums3.begin(), nums3.begin() + k3);
    assert(k3 == expected3.size());
    for (int i = 0; i < k3; i++) {
        assert(nums3[i] == expected3[i]);
    }
    
    cout << "solution has passed all of the defined testcases";
}

/*
The 2-pointer approach is better because it optimizes time complexity from O(n²) to O(n) 
by removing unnecessary rewrites commonly encountered when using simple loops with correct index targeting (writeIndex).

Why does it work? It essentially recognizes the discrepancy between the read pointer (i) and the write pointer (writeIndex). 
This discrepancy is caused by encountering the target value (val). The growing gap between these two pointers indicates 
how many elements have been skipped (or effectively removed) so far. Consequently, the program knows how much to shift the 
subsequent elements in each iteration, thereby overwriting the targeted values and correcting the position of the remaining elements.
*/