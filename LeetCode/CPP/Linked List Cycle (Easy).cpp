/*
Source: https://leetcode.com/problems/linked-list-cycle/description/
Diff: Easy

Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, 
pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.

Follow up: Can you solve it using O(1) (i.e. constant) memory?
Answer: yes, with hare and tortoise algorithm
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
    // keep a list of visited node and checks it periodically
    bool hasCycle(ListNode *head) {
        set<ListNode*> visited;
        while(head) {
            if (visited.find(head) != visited.end()) return true;
            visited.insert(head);
            head = head->next;
        }
        return false;
    }

    // imagine a race between a hare and a tortoise
    // hare is faster, and since the track is a loop
    // eventually hare will lap and pass the tortoise
    // so, if hare meet tortoise after the race started
    // then a loop exist :)
    bool floydTortoiseAndHare(ListNode *head) {
        ListNode* hare = head;
        ListNode* tortoise = head;
        while (head && head->next) {
            hare = hare->next->next;
            tortoise = tortoise->next;
            if (hare == tortoise) return true;
        }
        return false;
    }
};

ListNode* createCyclicList(const vector<int>& vals, int pos) {
    if (vals.empty()) return nullptr;

    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    ListNode* cycleNode = nullptr;

    for (int i = 1; i < vals.size(); ++i) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
        if (i == pos) cycleNode = curr;
    }

    if (pos == 0) cycleNode = head;
    if (cycleNode) curr->next = cycleNode;

    return head;
}

int main() {
    Solution solution;

    vector<int> vals1 = {3, 2, 0, -4};
    ListNode* head1 = createCyclicList(vals1, 1);
    vector<int> vals2 = {1,2};
    ListNode* head2 = createCyclicList(vals2, 0);
    vector<int> vals3 = {1};
    ListNode* head3 = createCyclicList(vals3, -1);
    vector<int> vals4 = {};
    ListNode* head4 = createCyclicList(vals4, -1);

    assert(solution.hasCycle(head1) == true);
    assert(solution.floydTortoiseAndHare(head1) == true);
    assert(solution.hasCycle(head2) == true);
    assert(solution.floydTortoiseAndHare(head2) == true);
    assert(solution.hasCycle(head3) == false);
    assert(solution.floydTortoiseAndHare(head3) == false);
    assert(solution.hasCycle(head4) == false);
    assert(solution.floydTortoiseAndHare(head4) == false);

    cout << "solution has passed all of the defined testcases";
}