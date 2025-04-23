
/*
Source: https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
Title: Remove Duplicates From Sorted List
Diff: Easy

Instruction
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Example
Input: head = [1,1,2]
Output: [1,2]

Input: head = [1,1,2,3,3]
Output: [1,2,3]

Constraints
The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
    public:
        // O(1) space and O(n) time complexity 
        ListNode* deleteDuplicates(ListNode* head) {
            ListNode* prev = head;
            ListNode* anchor = head;
            while(head) {
                head = head->next;
                if (head && head->val == prev->val) 
                    prev->next = head->next;
                else 
                    prev = prev->next;
            }
            return anchor;
        }

        // same performance, better space (1 vs 2 additional pointers), better edge case handling (null head), and more readable
        ListNode* betterDeleteDuplicates(ListNode* head) {
            if(!head) return head;

            ListNode* current = head;
            while (current && current->next) {
                if (current->val == current->next->val) 
                    current->next = current->next->next;
                else
                    current = current->next;
            }
            return head;
        }
};

class Util {
    public:
        ListNode* easyConstructor(vector<int> arr) {
            ListNode pth(0);
            ListNode* curr = &pth;
            for (auto elem : arr) {
                curr->next = new ListNode(elem);
                curr = curr->next;
            }
            return pth.next;
        }

        bool checker(ListNode* list, vector<int> arr) {
            for (auto elem : arr) {
                if (elem != list->val) return false;
                list = list->next;
            }
            return true;
        }

        void deleteList(ListNode* head) {
            while (head) {
                ListNode* next = head->next;
                delete head;
                head = next;
            }
        }
};

int main () {
    Solution solution;
    Util util;

    ListNode* list1 = util.easyConstructor({1,1,2});
    ListNode* answer1 = solution.betterDeleteDuplicates(list1);
    assert(util.checker(answer1, {1,2}));

    ListNode* list2 = util.easyConstructor({1,1,2,3,3});
    ListNode* answer2 = solution.betterDeleteDuplicates(list2);
    assert(util.checker(answer2, {1,2,3}));

    ListNode* list3 = util.easyConstructor({});
    ListNode* answer3 = solution.betterDeleteDuplicates(list3);
    assert(util.checker(answer3, {}));

    cout << "solution has passed all of the defined testcases";

    return 0;
}

/**
 * The list is already sorted
 * so you just need to window slide over 2 adjacent nodes, compare their values, skip if equal or continue if different
 */