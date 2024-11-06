/**
 * Problem:
 *   https://leetcode.com/problems/reverse-linked-list/description/
 * Solution:
 *   https://leetcode.com/problems/reverse-linked-list/submissions/1442370987/
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

class Solution_it
{
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr != nullptr)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};
