/**
 * Problem:
 *   https://leetcode.com/problems/swap-nodes-in-pairs/description/
 * Solution: TODO:revisit
 *
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

class Solution_re
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        // if no nodes or one node, no need to swap
        if (!head || !head->next) return head;
        // save pair node
        ListNode* pairNode = head->next;
        // head->next points to the head of the swapped list
        head->next = swapPairs(pairNode->next);
        // swaps the current pair
        pairNode->next = head;
        // return the head of the swapped pair
        return pairNode;
    }
};
