/*
Source: https://leetcode.com/problems/binary-tree-postorder-traversal/
Diff: Easy

Given the root of a binary tree, return the postorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [3,2,1]

Example 2:
Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [4,6,7,5,2,9,8,3,1]

Example 3:
Input: root = []
Output: []

Example 4:
Input: root = [1]
Output: [1]

Constraints:
The number of the nodes in the tree is in the range [0, 100].
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root, result);
        return result;
    }

    // you want to traverse and register node from the leaf nodes, from left to right
    // so just register the node as follows, do it after the end of the recursion (leaf), 
    // and recursion will take care of the reset (left to right) 
    void postorder(TreeNode* node, vector<int>& result) {
        if (!node) return;
        postorder(node->left, result);
        postorder(node->right, result);
        result.push_back(node->val);
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
    vector<int> result1 = {3,2,1};
    TreeNode* root1 = util.buildTree(input1);
    assert(solution.postorderTraversal(root1) == result1);

    
    vector<optional<int>> input2 = {1,2,3,4,5,nullopt,8,nullopt,nullopt,6,7,9};
    vector<int> result2 = {4,6,7,5,2,9,8,3,1};
    TreeNode* root2 = util.buildTree(input2);
    assert(solution.postorderTraversal(root2) == result2);

    
    vector<optional<int>> input3 = {};
    vector<int> result3 = {};
    TreeNode* root3 = util.buildTree(input3);
    assert(solution.postorderTraversal(root3) == result3);

    
    vector<optional<int>> input4 = {1};
    vector<int> result4 = {1};
    TreeNode* root4 = util.buildTree(input4);
    assert(solution.postorderTraversal(root4) == result4);


    cout << "solution has passed all of the defined testcases";

    return 0;
}