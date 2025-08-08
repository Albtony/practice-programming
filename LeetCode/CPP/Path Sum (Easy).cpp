/*
Source: https://leetcode.com/problems/minimum-depth-of-binary-tree/
Diff: Easy

Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
Note: A leaf is a node with no children.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 2

Example 2:
Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5

Constraints:
The number of nodes in the tree is in the range [0, 105].
-1000 <= Node.val <= 1000
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false; 
        return pathSumUtil(root, targetSum, 0);
    }


    // visit all node recursively and build the currentSum variable, when it reaches a leaf node (has no children at all), 
    // it checks whether the curr sum is equal the target sum
    bool pathSumUtil(TreeNode* node, int targetSum, int currentSum) {
        if (!node) return currentSum == targetSum;
        currentSum += node->val;

        if (!node->right) return pathSumUtil(node->left, targetSum, currentSum);
        if (!node->left) return pathSumUtil(node->right, targetSum, currentSum);

        return pathSumUtil(node->left, targetSum, currentSum) || pathSumUtil(node->right, targetSum, currentSum);
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

    vector<optional<int>> input1 = {1, 2};
    TreeNode* root1 = util.buildTree(input1);
    assert(solution.hasPathSum(root1, 1) == false);

    vector<optional<int>> input2 = {1, 2, 3};
    TreeNode* root2 = util.buildTree(input2);
    assert(solution.hasPathSum(root2, 5) == false);
    
    vector<optional<int>> input3 = {5,4,8,11,nullopt,13,4,7,2,nullopt,nullopt,nullopt,1};
    TreeNode* root3 = util.buildTree(input3);
    assert(solution.hasPathSum(root3, 22) == true);

    vector<optional<int>> input4 = {nullopt};
    TreeNode* root4 = util.buildTree(input4);
    assert(solution.hasPathSum(root4, 0) == false);
    cout << "solution has passed all of the defined testcases";

    return 0;
}