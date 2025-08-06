/*
Source: https://leetcode.com/problems/balanced-binary-tree/description/
Diff: Easy

Given a binary tree, determine if it is height-balanced.
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:
Input: root = []
Output: true

Constraints:
The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
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
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }

    // A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
    // this goes down to each node recursively and check their left and right subtrees length, if > 1, return -1 (false)
    int check(TreeNode* node) {
        if (!node) return 0;
        int left = check(node->left);
        if (left == -1) return -1;
        int right = check(node->right);
        if (right == -1) return -1;

        if(abs(right - left) > 1) return -1;
        return max(left, right) + 1;
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

    // Test 1: [3,9,20,null,null,15,7] => true
    vector<optional<int>> input1 = {3,9,20,nullopt,nullopt,15,7};
    TreeNode* root1 = util.buildTree(input1);
    assert(solution.isBalanced(root1) == true);

    // Test 2: [1,2,2,3,3,null,null,4,4] => false
    vector<optional<int>> input2 = {1,2,2,3,3,nullopt,nullopt,4,4};
    TreeNode* root2 = util.buildTree(input2);
    assert(solution.isBalanced(root2) == false);

    cout << "solution has passed all of the defined testcases";

    return 0;
}