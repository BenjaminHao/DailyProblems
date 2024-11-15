/**
 * Problem:
 *   https://leetcode.com/problems/swap-nodes-in-pairs/description/
 * Solution:
 *   https://leetcode.com/problems/swap-nodes-in-pairs/submissions/1453773114/
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
        ListNode* currNode = dummyHead;

        while (currNode->next && currNode->next->next)
        {
            ListNode* nextNode = currNode->next;
            ListNode* nextPair = currNode->next->next->next;
            currNode->next = nextNode->next;
            currNode->next->next = nextNode;
            nextNode->next = nextPair;
            currNode = nextNode;
        }

        return dummyHead->next;
    }
};
