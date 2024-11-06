/**
 * Problem:
 *   https://leetcode.com/problems/reverse-linked-list/description/
 * Solution:
 *   https://leetcode.com/problems/reverse-linked-list/submissions/1442379421/
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

class Solution_re1
{
public:
    ListNode* reverseList(ListNode* head) { return reverse(nullptr, head); }

private:
    ListNode* reverse(ListNode* prev, ListNode* curr)
    {
        if (curr == nullptr) return prev;
        ListNode* next = curr->next;
        curr->next = prev;
        return reverse(curr, next);
    }
};
