/*
Source: https://leetcode.com/problems/binary-tree-preorder-traversal/
Diff: Easy

Given the root of a binary tree, return the preorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,2,3]

Example 2:
Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [1,2,4,5,6,7,3,8,9]

Example 3:
Input: root = []
Output: []

Example 4:
Input: root = [1]
Output: [1]

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result = {};
        preorder(root, result);
        return result;
    }

    // you want to traverse and register node from root -> left -> right, so just do the register as stated
    // you do it before going left (root), and recursion will take care of the rest (left to right)
    void preorder(TreeNode* node, vector<int> &result) {
        if (!node) return;
        result.push_back(node->val);
        preorder(node->left, result);
        preorder(node->right, result);
    }
};

class Util {
public:
    TreeNode* buildTree(const vector<optional<int>>& values) {
        if (values.empty() || !values[0].has_value()) return nullptr;

        TreeNode* root = new TreeNode(values[0].value());
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;

        while (!q.empty() && i < values.size()) {
            TreeNode* current = q.front(); q.pop();

            if (i < values.size() && values[i].has_value()) {
                current->left = new TreeNode(values[i].value());
                q.push(current->left);
            }
            i++;

            if (i < values.size() && values[i].has_value()) {
                current->right = new TreeNode(values[i].value());
                q.push(current->right);
            }
            i++;
        }
        return root;
    }
};

int main() {
    Solution solution;
    Util util;

    vector<optional<int>> input1 = {1,nullopt,2,3};
    vector<int> result1 = {1,2,3};
    TreeNode* root1 = util.buildTree(input1);
    assert(solution.preorderTraversal(root1) == result1);

    
    vector<optional<int>> input2 = {1,2,3,4,5,nullopt,8,nullopt,nullopt,6,7,9};
    vector<int> result2 = {1,2,4,5,6,7,3,8,9};
    TreeNode* root2 = util.buildTree(input2);
    assert(solution.preorderTraversal(root2) == result2);

    
    vector<optional<int>> input3 = {};
    vector<int> result3 = {};
    TreeNode* root3 = util.buildTree(input3);
    assert(solution.preorderTraversal(root3) == result3);

    
    vector<optional<int>> input4 = {1};
    vector<int> result4 = {1};
    TreeNode* root4 = util.buildTree(input4);
    assert(solution.preorderTraversal(root4) == result4);


    cout << "solution has passed all of the defined testcases";

    return 0;
}