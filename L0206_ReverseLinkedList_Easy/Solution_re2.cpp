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
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* tmp = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return tmp;
    }
};
