/**
 * Problem: https://leetcode.com/problems/add-two-numbers/
 * Solution: https://leetcode.com/problems/add-two-numbers/submissions/1388158400
 * Time complexity:O(n)
 * Space complexity:O(n)
 */
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution_year2024
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* result = new ListNode();
        ListNode* p = result;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = (l1? l1->val:0) + (l2? l2->val:0) + carry;
            carry = sum / 10;
            p->next = new ListNode(sum % 10);

            p = p->next;
            l1 = (l1? l1->next:nullptr);
            l2 = (l2? l2->next:nullptr);
        }

        return result->next;
    }
};
