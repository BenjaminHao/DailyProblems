/**
 * Problem: https://leetcode.com/problems/add-two-numbers/
 * Solution: https://leetcode.com/problems/add-two-numbers/submissions/261428994
 * Runtime: 28ms, faster than 28.42%
 * Memory usage: 10.4MB, less than 76%
 */
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution_year2019
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode dummy(0); // create a dummy ListNode to get the start point
        ListNode* p = &dummy;
        int carry = 0; // carry bit, may be 0 or 1;

        while (l1 != nullptr || l2 != nullptr || carry != 0) // itertate ListNode until there's no next bit
        {
            int sums = (l1 == nullptr? 0 : l1->val) + (l2 == nullptr? 0 : l2->val) + carry; // Ternary operator, clean code
            carry = sums / 10;
            p->next = new ListNode(sums % 10); // next node of p

            p = p->next; // p points to next node
            l1 = (l1 == nullptr? 0 : l1->next); // l1 points to next node
            l2 = (l2 == nullptr? 0 : l2->next); // l2 points to next node
        }

        return dummy.next;
    }
};
