# Question
## Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node.
### Example:
Input: The node '`c`' from the linked list `a->b->c->d->e`  
Result: nothing is returned, but the new linked list looks like `a->b->d->e`

## Thinking
The key of this question is that we only have one pointer points to the node you want to delete. If we delete it directly, then the linked list is broken. And there's no way to get the pointer before the node because it's a singly linked list. We also don't know the head pointer of the linked list.

How to solve this problem with only one pointer points what we want to delete?  
As the example shows, we know the pointer points to node `c`. Then we can point to any nodes behind node `c` using `next` pointer. If we want to delete some nodes after node `c`, it would be easy. For example, if we want to delete node `d`. We only need to make `c->next` point to `e`, then `delete d`. After deleting `d`, we get `a->b->c->e`. Wait, is it very similar with the result?  
Yes! The only difference is `c` and `d`. What can we do to make them the same? Easy. Just give the `data` of `d` to `c`. The data structure is the same, there's no differences deleting one or the other. The key is the data. It is correct result as long as we get `a->b->d->e`.

We've already known how we solve this problem. Let's think of the different situations. The pointer could point to head node, middle node, tail node, and could be null pointer. The first two situations are normal cases. The last case is null, we can return directly. But if the pointer points to the tail node, what should we do? Should we just delete the tail node? Because there are no nodes behind, we don't need to care about break the data structure. Actually, **NO**. If we delete the node, the `next` pointer points to tail node is not going to be null. With that being said, if we print the linked list, it still prints the linked list with the same length, and the last value is undefined.
As the book said, this is exactly what the interviewer wants you to point out. You need to handle this issue. For example, if the pointer points to tail node, we can set the data to some unique character so we don't print it, or we can throw an error.
```cpp
void remove(Node* p)
{
    if (p == nullptr) return;
    if (p->next == nullptr)
    {
		std::cerr << "Unable to remove Tail Node." << std::endl;
        return;
    }
        

    Node* q = p->next;
    p->data = q->data;
    p->next = q->next;

    delete q;
}
```