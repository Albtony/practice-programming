
/*
Source: https://leetcode.com/problems/merge-two-sorted-lists/description/
Title: Merge Two Sorted Lists
Diff: Easy

Instruction
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Example
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Input: list1 = [], list2 = []
Output: []

Input: list1 = [], list2 = [0]
Output: [0]

Constraints
The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
*/

#include <bits/stdc++.h>
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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode pth(0);
            ListNode* curr = &pth;
    
            while (list1 && list2) {
                if (list1->val <= list2->val) {
                    curr->next = list1;
                    list1 = list1->next;
                } else { 
                    curr->next = list2;
                    list2 = list2 ->next;
                }
                curr = curr->next;
            }

            curr->next = list1 ? list1 : list2;
            return pth.next;
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

    ListNode* list1_1 = util.easyConstructor({1,2,4});
    ListNode* list2_1 = util.easyConstructor({1,3,4});
    ListNode* answer1 = solution.mergeTwoLists(list1_1, list2_1);
    assert(util.checker(answer1, {1,1,2,3,4,4}));

    ListNode* list1_2 = util.easyConstructor({});
    ListNode* list2_2 = util.easyConstructor({});
    ListNode* answer2 = solution.mergeTwoLists(list1_2, list2_2);
    assert(util.checker(answer2, {}));

    ListNode* list1_3 = util.easyConstructor({});
    ListNode* list2_3 = util.easyConstructor({0});
    ListNode* answer3 = solution.mergeTwoLists(list1_3, list2_3);
    assert(util.checker(answer3, {0}));

    cout << "solution has passed all of the defined testcases";

    return 0;
}

/*
Since the lists are sorted, you can combine the two iteratively while minding which value is smaller
The easiest way of doing this is to create a new list, then examine the values, and adding the smallest to the new list
since it is sorted ascendingly, if one list terminates faster, then add the remaining list, since it's already sorted
*/