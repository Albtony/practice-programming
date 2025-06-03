/*
Source: https://leetcode.com/problems/maximum-depth-of-binary-tree/
Title: Maximum Depth of Binary Tree
Diff: Easy

Instruction
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Examples
Input: root = [3,9,20,null,null,15,7]
Output: 3

Input: root = [1,null,2]
Output: 2

Constraints:
The number of nodes in the tree is in the range [0, 104].
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
        // O(n) time and space complexity, recursive DFS approach
        int maxDepth(TreeNode* root) {
            if (!root) return 0;
            
            int leftDepth = maxDepth(root->left);
            int rightDepth = maxDepth(root->right);
    
            return 1 + max(leftDepth, rightDepth);
        }

        // O(n) time and space complexity, iterative BFS approach   
        int iterativeMaxDepth(TreeNode* root) {
            queue<TreeNode*> q;
            if (!root) return 0;

            q.push(root);
            int depth = 0;

            while (!q.empty()) {    
                for (int i = 0; i < q.size(); i++) {
                    TreeNode* current = q.front(); q.pop();
                    if (current->left) q.push(current->left);
                    if (current->right) q.push(current->right);
                }
                depth++;
            }

            return depth;
        }
};

class Util {
    public:
        TreeNode* treeBuilder (const vector<optional<int>>& v) {
            if (v.empty() || !v[0].has_value()) return nullptr;
            
            TreeNode* root = new TreeNode(v[0].has_value());
            queue<TreeNode*> q;
            q.push(root);
            int i = 1;

            while (!q.empty() && i < v.size()) {
                TreeNode* current = q.front(); q.pop();

                if (i < v.size()) {
                    if (v[i].has_value()) {
                        current->left = new TreeNode(v[i].value());
                        q.push(current->left);
                    }
                    i++;
                }

                if (i < v.size()) {
                    if (v[i].has_value()) {
                        current->right = new TreeNode(v[i].value());
                        q.push(current->right);
                    }
                    i++;
                }
            }

            return root;
        }
};

int main() {
    Solution solution;
    Util util;

    vector<optional<int>> v1 = {3,9,20,NULL,NULL,15,7};
    TreeNode* tree1 = util.treeBuilder(v1);
    assert(solution.maxDepth(tree1) == 3);

    vector<optional<int>> v2 = {1,NULL,2};
    TreeNode* tree2 = util.treeBuilder(v2);
    assert(solution.maxDepth(tree2) == 2);

    // this somehow ouputs 5 instead of 4 in leetcode
    vector<optional<int>> v3 = {0,2,4,1,NULL,3,-1,5,1,NULL,6,NULL,8};
    TreeNode* tree3 = util.treeBuilder(v3);
    assert(solution.iterativeMaxDepth(tree3) == 4);

    cout << "solution has passed all of the defined testcases";

    return 0;
}

/**
 * You can approach this problem recursively or iteratively
 * 
 * recursive DFS
 * classic recursive DFS approach, but to count the depth, you need 2 variable, left depth and right depth
 * these variables hold count of the current max depth for each left and right children, giving us the true
 * max depth on the finall stack call
 * 
 * iterative BFS
 * simply use a variable and increment it everytime you move down, dont forget to group the process into levels
 * so you need to process all children on the same level at the same time, so your depth counter is accurate
 */