/**
 * Problem:
 *   https://leetcode.com/problems/swap-nodes-in-pairs/description/
 * Solution:
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
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

class Solution
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        ListNode* dummyHead = new ListNode(-1, head);
        ListNode* curr = dummyHead;
    }
};
