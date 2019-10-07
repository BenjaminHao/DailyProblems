# Question
## You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1’s digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.
### Example
Input: (3->1->5), (5->9->1)  
Output: 8->0->8
> Explain: 513 + 195 = 708

## Thinking
Same question with LeetCode #2. Medium level question. Not very hard. Some points:
1. Empty linked list. 
2. Carry bit
3. Linked lists with different lengths

## Code
```cpp
Node* AddTwoNumbers(Node* l1, Node* l2)
{
    Node dummy(0);
    Node* p = &dummy;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0)
    {
        int sum = (l1 == nullptr? 0 : l1->data) + (l2 == nullptr? 0 : l2->data) + carry;
        carry = sum / 10;
        p->next = new Node(sum % 10);

        p = p->next;
        l1 = l1 == nullptr? nullptr : l1->next;
        l2 = l2 == nullptr? nullptr : l2->next;
    }

    return dummy.next;
}
```
The **ternary operator** using is very tricky here. It reduced a lot of code.
> For detailed info, check LeetCode #2.