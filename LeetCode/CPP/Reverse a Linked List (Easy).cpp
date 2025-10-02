/*
Source: https://leetcode.com/problems/reverse-linked-list/description/
Diff: Easy

Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []

Constraints:
The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
*/
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* next;
        ListNode* prev = nullptr;
        while (head != nullptr) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

class Util {
public:
    bool listIsEqual(ListNode* head1, ListNode* head2) {

        while (head1 && head2) {
            if(head1->val != head2->val) 
                return false;
            head1 = head1->next;
            head2 = head2->next;
        }

        return head1 == nullptr && head2 == nullptr;
    }

    ListNode* buildList(const vector<optional<int>>& values) {
        if (values.empty() || !values[0].has_value()) return nullptr;

        ListNode* head = new ListNode(values[0].value());
        ListNode* current = head;
        for(int i = 1; i < values.size(); i++) {
            if (values[i].has_value()) {
                current->next = new ListNode(values[i].value());
                current = current->next;
            }
        }
        return head;
    }
};

int main () {
    Solution sol;
    Util util;

    vector<optional<int>> v1 = {1,2,3,4};
    vector<optional<int>> r1 = {4,3,2,1};
    ListNode* result1 = sol.reverseList(util.buildList(v1));
    ListNode* expected1 = util.buildList(r1);
    assert(util.listIsEqual(result1, expected1));

    vector<optional<int>> v2 = {};
    vector<optional<int>> r2 = {};
    ListNode* result2 = sol.reverseList(util.buildList(v2));
    ListNode* expected2 = util.buildList(r2);
    assert(util.listIsEqual(result2, expected2));

    vector<optional<int>> v3 = {1};
    vector<optional<int>> r3 = {1};
    ListNode* result3 = sol.reverseList(util.buildList(v3));
    ListNode* expected3 = util.buildList(r3);
    assert(util.listIsEqual(result3, expected3));
    cout << "solution has passed all of the defined testcases";

    return 0;
}