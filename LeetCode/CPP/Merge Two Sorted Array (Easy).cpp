
/*
Source: https://leetcode.com/problems/merge-sorted-array/description/
Title: Merge Two Sorted Array
Diff: Easy

Instruction
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, 
representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. 
To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, 
and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

Constraints:

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109

Follow up: Can you come up with an algorithm that runs in O(m + n) time?
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        // my initial solution O(m+n) time, O(m) space
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            vector<int> temp1 = nums1;
            int i = 0, j = 0;
    
            while (i < m && j < n) {
                if (temp1[i] < nums2[j]) {
                    nums1[i+j] = temp1[i];
                    i++;
                } else {
                    nums1[i+j] = nums2[j];
                    j++;
                }
            }
    
            while (i < m) {
                nums1[i+j] = temp1[i];
                i++;
            }
    
            while (j < n) {
                nums1[i+j] = nums2[j];
                j++;
            }
        }

        // better solution, more readable, and less space complexity O(1), it use 2 pointer approach
        void betterMerge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int i = m - 1;
            int j = n - 1;
            int k = m + n - 1;
            
            while (j >= 0) {
                if (i >= 0 && nums1[i] > nums2[j]) {
                    nums1[k--] = nums1[i--];
                } else {
                    nums1[k--] = nums2[j--];
                }
            }
        }
};

int main () {
    Solution solution;
    
    vector<int> nums1_1 = {1,2,3,0,0,0};
    vector<int> nums2_1 = {2,5,6}; 
    vector<int> ans_1 = {1,2,2,3,5,6};
    int m_1 = 3;
    int n_1 = 3;
    solution.betterMerge(nums1_1, m_1, nums2_1, n_1);
    assert(nums1_1 == ans_1);

    vector<int> nums1_2 = {1};
    vector<int> nums2_2 = {}; 
    vector<int> ans_2 = {1};
    int m_2 = 1;
    int n_2 = 0;
    solution.betterMerge(nums1_2, m_2, nums2_2, n_2);

    
    vector<int> nums1_3 = {0};
    vector<int> nums2_3 = {1}; 
    vector<int> ans_3 = {1};
    int m_3 = 0;
    int n_3 = 1;
    solution.betterMerge(nums1_3, m_3, nums2_3, n_3);


    cout << "solution has passed all of the defined testcases";

    return 0;
}

/*
The basic principles are the same as in the "Merge Two Sorted Lists" problem.

Since both arrays are already sorted, we can iterate through them and insert the smaller value each time.
However, because we're working with arrays (not singly linked lists), we can use a double pointer approach to reduce space usage.

This method works particularly well with arrays because we can start merging from the end. This avoids overwriting values in nums1 that haven't been processed yet — something that's not possible with singly linked lists.

What does the double pointer approach do?
It uses two pointers, i and j, to compare elements in the two arrays:
  - i points to the last valid element in nums1 (i.e., m - 1)
  - j points to the last element in nums2 (i.e., n - 1)

A third pointer, k, is used to track the current position in nums1 where the next largest value should be placed (starting from m + n - 1).

Using these three pointers, we can compare and merge the arrays into nums1 in-place, without allocating additional space — achieving O(1) space complexity.
*/
