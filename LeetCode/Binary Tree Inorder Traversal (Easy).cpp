/*
Source: https://leetcode.com/problems/binary-tree-inorder-traversal/
Title: Binary Tree Inorder Traversal
Diff: Easy

Instruction
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Examples
Input: root = [1,null,2,3]
Output: [1,3,2]

Input: root = []
Output: []

Input: root = [1]
Output: [1]

Constraints
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        __inorder(root, result);
        return result;
    }
    
    void __inorder(TreeNode* root, vector<int>& result) {
        if(root == NULL) return;
        __inorder(root->left, result);
        result.push_back(root->val);
        __inorder(root->right, result);
    }
};

/*
my struggle/mistake while solving this problem:
- wrong order for inorder traversal
*/