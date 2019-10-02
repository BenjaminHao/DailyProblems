# Question 2.1
## Write code to remove duplicates from an unsorted linked list.
### Follow up  
How would you solve this problem if a temporary buffer is not allowed?

## Thinking
If we can use extra space, we can just create an array to save the occurrence of elements. The best way to solve this problem is to use hash table.  
Iterate the linked list, if the element has been existed, then remove this element. The time complexity is $O(n)$.
```cpp
void removeDuplicate(node *head)
{
    if (head == nullptr) return;
    node* p = head, *q = head->next;
    hash[head->data]++;

    while(q)
    {
        if (hash[q->data] != 0)
        {
            node* t = q;
            p->next = q->next;
            q = p->next;
            delete t;
        }
        else
        {
            hash[q->data]++;
            p = q;
            q = q->next;
        }
    }
}
```
If we are not allowed to use a temporary buffer, then we need two pointers, when the first pointer points to one element, the second will delete the same elements after the current one. The time complexity is $O(n^2)$.
```cpp
void removeDuplicate(node* head)
{
    if (head == nullptr) return;
    node *p, *q, *c = head;
    while (c)
    {
        p = c;
        q = c->next;
        int d = c->data;
        while (q)
        {
            if (q->data == d)
            {
                node* t = q;
                p->next = q->next;
                q = p->next;
                delete t;
            }
            else
            {
                p = q;
                q = q->next;
            }
        }
        c = c->next;
    }
}
```