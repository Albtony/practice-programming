/*
Source : https://leetcode.com/problems/add-two-numbers/description/
Title : Add Two Numbers
Diff : Medium

You are given two non-empty linked lists representing two non-negative integers. The digits are 
stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and 
return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbersInplace(ListNode* l1, ListNode* l2) {
        ListNode* anchor = l1;
        ListNode* prev;
        int carry = 0;
        while (l1) {
            int l2val = l2 == nullptr ? 0 : l2->val;
            int sum = l1->val + l2val + carry;
            l1->val = sum % 10;
            carry = sum / 10;
            if (!l1->next && l2 && l2->next) {
                l1->next = l2->next;
                l2 = nullptr;
            }
            prev = l1;
            l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        if (carry) prev->next = new ListNode(carry);
        return anchor;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode();
        ListNode* anchor = result;
        int carry = 0;
        while (l1 || l2 || carry) {
            int l1v = l1 ? l1->val : 0;
            int l2v = l2 ? l2->val : 0;
            int sum = l1v + l2v + carry;
            result->next = new ListNode(sum % 10);
            carry = sum / 10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            result = result->next;
        }

        return anchor->next;
    }
};

/*
SOLUTION ONE is efficient for both time and space complexity

this solution use in place mutation to reduce on memory to o1
though it increases the code complexity dramaticlalya

the idea is to take l1 as the main list, and add l2 into it
and if l1 is shorter, then append l2 and normalize the values

but an extra result variable like SOLUTION TWO will reduce the complexity by leaps and bounds
and definitely must be considered if space is not an issue
*/