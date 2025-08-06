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
    int minDepth(TreeNode* root) {
        return minSubtree(root);
    }

    // goes down to each node recursively and compares valid left and right subtrees height
    int minSubtree(TreeNode* node) {
        if (!node) return 0;

        // this ensures us to only account for existing node or leaf node height
        // if left is null, go right, if it exist, find its height, if its null then curr node is leaf node, find its height
        if (!node->left) return minSubtree(node->right) + 1;
        if (!node->right) return minSubtree(node->left) + 1;


        // if both nodes exist, find and compare height of both
        return min(minSubtree(node->right), minSubtree(node->left)) + 1;
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

    // Test 1: [3,9,20,null,null,15,7] => 2
    vector<optional<int>> input1 = {3,9,20,nullopt,nullopt,15,7};
    TreeNode* root1 = util.buildTree(input1);
    assert(solution.minDepth(root1) == 2);

    // Test 2: [2,null,3,null,4,null,5,null,6] => 5
    vector<optional<int>> input2 = {2,nullopt,3,nullopt,4,nullopt,5,nullopt,6};
    TreeNode* root2 = util.buildTree(input2);
    assert(solution.minDepth(root2) == 5);

    cout << "solution has passed all of the defined testcases";

    return 0;
}