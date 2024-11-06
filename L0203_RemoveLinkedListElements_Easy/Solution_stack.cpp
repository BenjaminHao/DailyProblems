/**
 * Problem:
 *   https://leetcode.com/problems/remove-linked-list-elements/description/
 * Solution:
 *   https://leetcode.com/problems/remove-linked-list-elements/submissions/1442315374/
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
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode dummyhead;
        dummyhead.next = head;
        ListNode* cur = &dummyhead;
        while (cur->next != nullptr)
        {
            if (cur->next->val == val)
                cur->next = cur->next->next;
            else
                cur = cur->next;
        }

        return dummyhead.next;
    }
};
