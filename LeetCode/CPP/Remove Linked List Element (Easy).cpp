/*
Source: https://leetcode.com/problems/remove-linked-list-elements/description/
Title: Remove Linked List Element
Diff: Easy

Given the head of a linked list and an integer val, remove all the nodes of the linked list that 
has Node.val == val, and return the new head.

Example 1:
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Example 2:
Input: head = [], val = 1
Output: []

Example 3:
Input: head = [7,7,7,7], val = 7
Output: []

Constraints:
The number of nodes in the list is in the range [0, 104].
1 <= Node.val <= 50
0 <= val <= 50
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
    ListNode* removeElements(ListNode* head, int val) {
        while (head && head->val == val) {
            head = head->next; 
        }

        ListNode* current = head;
        ListNode* prev = current;
        
        while (current && current->next) {
            if (current->val == val) {
                prev->next = current->next;
                current = current->next;
                continue;
            }
            prev = current;
            current = current->next;
        }

        if (current && current->val == val) {
            prev->next = current->next;
        }

        return head;
    }

    ListNode* betterRemoveElements(ListNode* head, int val) {
        while (head && head->val == val) {
            head = head->next;
        }

        ListNode* current = head;
        while (current && current->next) {
            if (current->next->val == val) {
                current->next = current->next->next;  
            } else {
                current = current->next;  
            }
        }

        return head;
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

    void printList(ListNode* head) {
        while (head) {
            cout << head->val << endl;
            if (head->next) 
                head = head->next;
            else 
                head = nullptr;
        } 
    }
};

int main() {
    Solution solution;
    Util util;

    int toBeRemoved = 6;

    vector<optional<int>> input1 = {1, 2, 3};
    vector<optional<int>> result1 = {1, 2, 3};
    ListNode* inputList1 = util.buildList(input1);
    ListNode* expectedList1 = util.buildList(result1);
    assert(util.listIsEqual(solution.removeElements(inputList1, toBeRemoved), expectedList1));

    vector<optional<int>> input2 = {6, 1, 2, 3, 6};
    vector<optional<int>> result2 = {1, 2, 3};
    ListNode* inputList2 = util.buildList(input2);
    ListNode* expectedList2 = util.buildList(result2);
    assert(util.listIsEqual(solution.removeElements(inputList2, toBeRemoved), expectedList2));


    vector<optional<int>> input3 = {1, 6, 2, 6, 6, 3};
    vector<optional<int>> result3 = {1, 2, 3};
    ListNode* inputList3 = util.buildList(input3);
    ListNode* expectedList3 = util.buildList(result3);
    assert(util.listIsEqual(solution.removeElements(inputList3, toBeRemoved), expectedList3));

    vector<optional<int>> input4 = {6};
    vector<optional<int>> result4 = {};
    ListNode* inputList4 = util.buildList(input4);
    ListNode* expectedList4 = util.buildList(result4);
    assert(util.listIsEqual(solution.removeElements(inputList4, toBeRemoved), expectedList4));

    
    vector<optional<int>> input5 = {};
    vector<optional<int>> result5 = {};
    ListNode* inputList5 = util.buildList(input5);
    ListNode* expectedList5 = util.buildList(result5);
    assert(util.listIsEqual(solution.removeElements(inputList5, toBeRemoved), expectedList4));

    cout << "solution has passed all of the defined testcases";
    return 0;
}