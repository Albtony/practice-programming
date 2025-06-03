/*
Source: https://leetcode.com/problems/same-tree/description/
Title: Same Tree
Diff: Easy

Instruction
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Examples
Input: p = [1,2,3], q = [1,2,3]
Output: true

Input: p = [1,2], q = [1,null,2]
Output: false

Input: p = [1,2,1], q = [1,1,2]
Output: false

Constraints
The number of nodes in both trees is in the range [0, 100].
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
        // iterative BFS approach, O(n) time and space
        bool isSameTree(TreeNode* p, TreeNode* q) {
            queue<TreeNode*> qp, qq;
    
            qp.push(p);
            qq.push(q);

            while (!qp.empty() && !qq.empty()) {
                TreeNode* currP = qp.front(); qp.pop();
                TreeNode* currQ = qq.front(); qq.pop();
    
                if (!currP && !currQ) continue;
                if (!currP || !currQ || currP->val != currQ->val) return false;
    
                qp.push(currP->left);
                qp.push(currP->right);
                qq.push(currQ->left);
                qq.push(currQ->right);
            }
    
            return qp.empty() && qq.empty();
        }

        // recursive DFS approach, O(n) time and space
        bool recursiveIsSameTree (TreeNode* p, TreeNode* q) {
            if (!p && !q) return true;
            if (!p || !q || p->val != q->val) return false;
            return recursiveIsSameTree(p->left, q->left) && recursiveIsSameTree(p->right, q->right);    
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

    vector<optional<int>> vp1 = {1,2,3};
    vector<optional<int>> vq1 = {1,2,3};
    TreeNode* p1 = util.treeBuilder(vp1);
    TreeNode* q1 = util.treeBuilder(vq1);
    assert(solution.isSameTree(p1, q1) == true);

    vector<optional<int>> vp2 = {1,2};
    vector<optional<int>> vq2 = {1,NULL,2};
    TreeNode* p2 = util.treeBuilder(vp2);
    TreeNode* q2 = util.treeBuilder(vq2);
    assert(solution.isSameTree(p2, q2) == false);

    vector<optional<int>> vp3 = {1,2,1};
    vector<optional<int>> vq3 = {1,1,2};
    TreeNode* p3 = util.treeBuilder(vp3);
    TreeNode* q3 = util.treeBuilder(vq3);
    assert(solution.isSameTree(p3, q3) == false);

    cout << "solution has passed all of the defined testcases";

    return 0;
}

/**
 * To determine if two trees are structurally identical, we must traverse both trees and 
 * compare the values of their corresponding nodes. The key condition is that corresponding 
 * nodes in both trees (p and q) must have the same value, regardless of whether they are null or non-null. 
 * This condition needs to be checked at every node visited.
 * 
 * both BFS and DFS only visit each node once, so time complexity is O(n)
 * BFS can hold up to n nodes in a skewed tree so space complexity is O(n)
 * DFS can hold up to n stack call in a skewed tree so space complexity is also O(n)
 * 
 * iterative DFS is easier for complex operation, less constant memory, and more error resistant
 * but is harder to both read and write.
 * 
 * recursive DFS is more concise, easier to read, easier to understand
 * but also harder to do complex operation, and prone to stack overflow error
 * 
 * stack overflow error happens when you get such a big tree to the point you are calling too many stack calls
 * and that stacks doesn't fit your memory. So stack overflow is a type of buffer overflow which are very dangerous
 * because it allows very powerful exploit such as code injection by modifying function return address
 */