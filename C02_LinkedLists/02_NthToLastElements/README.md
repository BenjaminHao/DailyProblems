# Question 2.2
## Implement an algorithm to find the `n`th to last element of a singly linked list.

## Thinking
### Solution 1
This question is to test how we find the `n`th to last element(not to find the elements from the nth element till the last element). Because it is a singly linked list, we cannot just start from the last element and count `n` backwards. But, the direction we made is clearly right. Then is there any other way to do the similar thing?  
There's one data structure that we can think of: **stack**(first in, last out).

If we iterate the singly linked list once and push elements into a stack and then pop them out. Then the `n`th element that pops out is what we want.

Is it the best way to use stack? No. When we use stack, the first thing we need to think of should be **Recursion**.  
The implementation is easy. If the pointer points to the singly linked list is not null, we keep recurring. When the pointer is null, we return. In these recursions, `n` keeps `-1`. When `n = 1`,
we get the element.
```cpp
Node* pp;
int nn;
void findNthToLast(Node* head)
{
    if (head == nullptr) return;
    findNthToLast(head->next);
    if (nn == 1) pp = head;
    --nn;
}
```
### Solution 2
Is there any other ways solve this question?  
Yes. Although we cannot count backwards, we can have two pointers that have distance of `n`. Then, we move these two pointer simultaneously and keep the distance. Finally, when the second pointer become null, the element that the first pointer points to is what we want. It is a tricky solution.
```cpp
Node* findNthToLast(Node* head, int n)
{
    if (head == nullptr || n < 1) return nullptr;
    Node* p = head, *q = head;

    while (n > 0 && q)
    {
        q = q->next;
        --n;
    }

    if (n > 0) return nullptr;

    while(q)
    {
        p = p->next;
        q = q->next;
    }
    return p;
}
```