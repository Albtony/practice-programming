#include<bits/stdc++.h>
#include <optional>
#include <iostream>
using namespace std;

/*
Source: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
Diff: Medium

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]

Constraints:
The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

Follow up: Could you do this in one pass?
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) return nullptr;

        ListNode* tail = head;
        ListNode* prevTarget = nullptr;
        ListNode* target = head;
        while(--n) tail = tail->next;
        while(tail && tail->next) {
            tail = tail->next;
            prevTarget = target;
            target = target->next;
        }

        if (!prevTarget) return target->next;
        prevTarget->next = target->next;
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
    Solution sol;
    Util util;

    vector<optional<int>> input = {1, 2, 3};
    vector<optional<int>> result = {1, 2};
    ListNode* inputList = util.buildList(input);
    ListNode* expectedList = util.buildList(result);
    assert(util.listIsEqual(sol.removeNthFromEnd(inputList, 1), expectedList));
    
    input = {1, 2};
    result = {1};
    inputList = util.buildList(input);
    expectedList = util.buildList(result);
    assert(util.listIsEqual(sol.removeNthFromEnd(inputList, 1), expectedList));

    input = {1, 2};
    result = {2};
    inputList = util.buildList(input);
    expectedList = util.buildList(result);
    assert(util.listIsEqual(sol.removeNthFromEnd(inputList, 2), expectedList));

    input = {1};
    result = {};
    inputList = util.buildList(input);
    expectedList = util.buildList(result);
    assert(util.listIsEqual(sol.removeNthFromEnd(inputList, 1), expectedList));

    cout << "solution has passed all of the defined test cases";

    return 0;
}

/*
this problem is pretty simple, we just have to traverse to the targeted notes, 
take the previous node, and point it to target-next, effectively deleting it from the list

its just about how you do it, the simplest and cleanest way i can simulate gaps is to let the main traverser (tail)
to actually take n step first, and then the target and the node behind the target (prev target) follow suit

this way we maintain n-step gap between target and tail, when tail reach the end, target is basically n-step from end
so we just need to "delete" it, so we set prevTarget->next = target->next

you just need to be mind of edge cases such as 1 length list, which is simple enough, just return null
*/