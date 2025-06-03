/*
Source: https://leetcode.com/problems/symmetric-tree/
Title: Symmetric Tree
Diff: Easy

Instruction
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Examples
Input: root = [1,2,2,3,4,4,3]
Output: true

Input: root = [1,2,2,null,3,null,3]
Output: false

Constraints:
The number of nodes in the tree is in the range [1, 1000].
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
        // O(n) time and space, recursive DFS approach
        bool isSymmetric(TreeNode* root) {
            if (!root) return true;

            return isSame(root->left, root->right);
        }

        bool isSame(TreeNode* p, TreeNode* q) {
            if (!p && !q) return true;
            if (!p || !q || p->val != q->val) return false;

            return isSame(p->left, q->right) && isSame(p->right, q->left);
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

    vector<optional<int>> v1 = {1,2,2,3,4,4,3};
    TreeNode* tree1 = util.treeBuilder(v1);
    assert(solution.isSymmetric(tree1) == true);

    vector<optional<int>> v2 = {1,2,2,NULL,3,NULL,3};
    TreeNode* tree2 = util.treeBuilder(v2);
    assert(solution.isSymmetric(tree2) == false);

    cout << "solution has passed all of the defined testcases";

    return 0;
}

/**
 * This problem is essentially the "Same Tree" problem with an added layer of complexity.
 * Instead of being given two separate trees to compare, you are provided with a single tree
 * and need to determine if it is symmetrical.
 *
 * The symmetry of a tree is defined by its root's children. The left and right children
 * must mirror each other structurally and in terms of their node values.
 * 
 * You can treat this left and right children to be 2 different trees
 * and check for left == right and right == left instead of the normal left == left and right == right to check symmetricality 
 */