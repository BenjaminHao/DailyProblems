# Question
## Given a circular linked list, implement an algorithm which returns node at the beginning of the loop.
### Definition
Circular linked list: A (corrupt) linked list in which a node’s next pointer points to an earlier node, so as to make a loop in the linked list.
### Example
Input: A->B->C->D->E->C [the same C as earlier]  
Output: C

## Thinking
The method to solve circular linked list is very tricky. We are using two pointer technique. One slow pointer and one fast pointer(the speed of fast pointer is 2, and slow pointer is 1) iterate through the linked list. If there's a circle in the linked list, then the fast pointer will meet the slow pointer.(They will point to the same node.)  
The next question is, when fast pointer meets slow pointer, how can we find the beginning node of the loop?  
Let's think about when fast pointer will meet slow pointer first:
![Circular Linked List](http://hawstein.com/img/2012/12/17/circularlist.jpg)

