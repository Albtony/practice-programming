/*
Source: https://leetcode.com/problems/swap-nodes-in-pairs/
Diff: Medium

Given a linked list, swap every two adjacent nodes and return its head. You must solve 
the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]
Explanation:

Example 2:
Input: head = []
Output: []

Example 3:
Input: head = [1]
Output: [1]

Example 4:
Input: head = [1,2,3]
Output: [2,1,3]

Constraints:
The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100
*/

#include <bits/stdc++.h>
#include <iostream>
#include <optional>
#include <assert.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) return nullptr;

        ListNode* first = head->next;
        ListNode* second = head;
        ListNode* front = nullptr;
        ListNode* back = nullptr;

        if (head->next) head = head->next;

        while(first) {
            front = first->next;
            first->next = second;
            second->next = front;

            if(back) back->next = first;

            back = first;
            first = second;
            second = back;

            first = first->next;
            second = second->next;
            back = back->next;

            if(!first) break;
            first = first->next;
            second = second->next;
        }

        return head;
    }

    ListNode* betterSwapPairs(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        while (head && head->next) {
            ListNode* first = head;
            ListNode* second = head->next;

            first->next = second->next;
            second->next = first;
            prev->next = second;

            prev = first;
            head = first->next;
        }

        return dummy.next;
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

    vector<optional<int>> input = {1, 2, 3, 4};
    vector<optional<int>> result = {2, 1, 4, 3};
    ListNode* inputList = util.buildList(input);
    ListNode* expectedList = util.buildList(result);
    assert(util.listIsEqual(sol.swapPairs(inputList), expectedList));

    input = {1, 2};
    result = {2, 1};
    inputList = util.buildList(input);
    expectedList = util.buildList(result);
    assert(util.listIsEqual(sol.swapPairs(inputList), expectedList));

    input = {1};
    result = {1};
    inputList = util.buildList(input);
    expectedList = util.buildList(result);
    assert(util.listIsEqual(sol.swapPairs(inputList), expectedList));

    input = {1, 2, 3};
    result = {2, 1, 3};
    inputList = util.buildList(input);
    expectedList = util.buildList(result);
    assert(util.listIsEqual(sol.swapPairs(inputList), expectedList));

    input = {};
    result = {};
    inputList = util.buildList(input);
    expectedList = util.buildList(result);
    assert(util.listIsEqual(sol.swapPairs(inputList), expectedList));

    cout << "solution has passed all of the defined testcase";


    return 0;
}

/*
i have 2 solutions for this problem, the first one is my first attempt
and the second one is AI-assisted, apparently im juggling pointers unnecessarily

fist solution:
so, we want to do reversal of 2 nodes at a time, ofc we going to need 2 pointers for this
so i defined first as the first node to go, second to follow

but then to reverse, i need to put second->next to first, and since second->next is gone now, 
i made front to hold it for me and set first->next = front 
(absolutely missing the point i should do first->next = second->next first lol)

and then i rearrange the pointer to the initial set up, where first is the infornt of second
thats why i saved `first` to `back`, then swap first and second

and then move both of them forward twice, so now we have back->second->first->front

then i can just repeat this until the list is fully reversed, but there is an edge case
if head is empty, i need to return nullptr immediately since since I access head->next, I need to ensure head isn’t null
and i need to put head at head->next because the first pair's order is going to be reversed, 
so the head->next becomes the new head

second solution:
the second solution is much better since the pointer swapping is much more straight forward
it doesnt check head==null or back==null whatsoever because it cleverly integrates these edgecases to the main routine

it create dummy->head which mean we have a reliable head variable, it use pointer to avoid reasigning and to integrate it
with prev logic inside the main routine

it swap nodes with the corret order (first->next = second->next first) hence it doesn't need to use `front` temp variable
it actually kinda use `front` and `back` in the form of `head` and `prev`, but it handles things more elegantly 
than how mine does it

after reordering, it moves forward with setting prev = first, and head = first next
then in the next loop it moves forward again if head and head->next is available, hence moving 2 step at each iteration

and since it initialize prev as dummy, and set prev->next to first
it handles the wrong head problem naturally inside the loop
*/