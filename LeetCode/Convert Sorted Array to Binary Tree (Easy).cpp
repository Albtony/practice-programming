/*
Source: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
Title: Convert Sorted Array to Binary Search Tree
Diff: Easy

Instruction
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

Examples
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.

Constraints:
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        // o(n) time complexity, recursive middle element subarray insertion for balanced bst.
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            if (nums.empty()) return nullptr;
    
            return balancedBST(nums, 0, nums.size()-1);
        }
    
        TreeNode* balancedBST(vector<int> sortedArray, int left, int right) {
            if (left > right) return nullptr;
    
            int mid = left + (right - left) / 2;
            TreeNode* root = new TreeNode(sortedArray[mid]);
    
            root->left = balancedBST(sortedArray, left, mid - 1);
            root->right = balancedBST(sortedArray, mid+1, right);
    
            return root;
        }

        // just a rogue func
        TreeNode* insertBST(TreeNode* root, int key) {
            if (!root) return new TreeNode(key)  ;
            if (key < root->val) root->left = insertBST(root->left, key);
            else if (key > root->val) root->right = insertBST(root->right, key);
        } 
};

class Util {
    public:
        int maxDepth(TreeNode* root) {
            if (!root) return 0;

            int leftDepth = maxDepth(root->left);
            int rightDepth = maxDepth(root->right);

            return 1 + max(leftDepth, rightDepth);
        }

        int minBalancedDepth(int length) {
            if (length == 0) return 0; 
            return 1 + floor(log2(length));
        }

        bool isBST(TreeNode* root, int maxVal, int minVal) {
            if (!root) return true;

            if (root->val <= minVal || root->val >= maxVal) return false;

            return isBST(root->left, root->val, minVal) && isBST(root->right, maxVal, root->val);
        }
};

int main() {
    Solution solution;
    Util util;

    vector<int> v1 = {-10,-3,0,5,9};
    TreeNode* r1 = solution.sortedArrayToBST(v1); 
    assert((util.minBalancedDepth(v1.size()) == util.maxDepth(r1)) && util.isBST(r1, INT_MAX, INT_MIN));

    vector<int> v2 = {1,3};
    TreeNode* r2 = solution.sortedArrayToBST(v2);
    assert((util.minBalancedDepth(v2.size()) == util.maxDepth(r2)) && util.isBST(r2, INT_MAX, INT_MIN));

    cout << "solution has passed all of the defined testcases";

    return 0;
}

/**
 * A height-balanced BST should have a height of 1+log2(n), where n is the number of nodes present.
 * A BST is formed by placing keys with values lower than a node on the left side and higher values on the right side. 
 * This is true for all nodes.
 * 
 * To have a perfectly balanced BST, as the question asks, each subtree must be perfectly balanced.
 * A perfectly balanced tree is as follows:
 * 1. For every node, the height difference between its left and right subtrees is at most 1.
 * 2. All levels are completely filled except the very last one.
 * 
 * BST insertion is typically done recursively. For each node, it checks: 
 * 1. If the node is null, then a new node is created.
 * 2. If the node is not null and the value is lower than the node's value, then it goes to the left node.
 * 3. If the node is not null and the value is higher than the node's value, then it goes to the right node.
 * This is done recursively until the correct position at the very bottom of the tree is reached, where a new node will be created.
 * 
 * We have a sorted array. This doesn't inherently help us in creating a perfectly balanced BST.
 * Since it is sorted, if we insert the elements from the beginning to the end without any modification, we will produce a skewed tree, which is a very imbalanced BST.
 * This is literally the worst case of BST construction, so the order of insertion matters, and the value that we are inserting matters.
 * 
 * With this information, we need to carefully choose the sequence of insertion into a BST so that it produces a perfectly balanced BST.
 * Since the smallest balanced subtrees of a tree consist of 3 nodes (root, right, and left), we need to insert in a way that we produce this structure for every subtree.
 * For each node: val (root), lower val (left), higher val (right).
 * 
 * The way to do this for every node is to use a divide and conquer approach, where we start at the middle element. This will act as the root of the tree.
 * Then, we recursively do the same for the left and right subarrays. These will act as the left and right subtrees.
 * This process will be repeated until the array is fully divided and conquered. This method generates the correct insertion order to produce a perfectly balanced BST.
 */

// pt
// aos
// qt