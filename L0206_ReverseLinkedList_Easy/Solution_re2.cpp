/**
 * Problem:
 *   https://leetcode.com/problems/reverse-linked-list/description/
 * Solution:
 *   https://leetcode.com/problems/reverse-linked-list/submissions/1442450623/
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution_re2
{
public:
    ListNode* reverseList(ListNode* head)
    {
        // if no nodes or only one nodes, it's already reversed
        if (!head || !head->next) return head;
        // reverse the rest List except head
        ListNode* rest = reverseList(head->next);
        // the reversed list points to the head
        head->next->next = head;
        // head is reversed and is the end of the list
        head->next = nullptr;
        // pass back the reversed list
        return rest;
    }
};
