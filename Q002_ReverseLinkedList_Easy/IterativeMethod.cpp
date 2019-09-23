#include <iostream>

/** 
 *  1. Initialize three pointers prev, curr, next
 *  2. Iterate through the linked list
 *      a. before changing next of current, store next node
 *      b. change next of current
 *      c. move prev and curr one step forward
**/

// Linked list node
struct Node
{
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {} 
};

struct LinkedList
{
    Node* head;

    LinkedList() : head(nullptr) {}

    //push method
    void push(int data)
    {
        Node* tmp = new Node(data);
        tmp->next = head;
        head = tmp;
    }

    // print method
    void print()
    {
        Node* tmp = head;

        while (tmp != nullptr)
        {
            std::cout << tmp->data << " ";
            tmp = tmp->next;
        }
    }

    // reverse method: iterative method
    void reverse()
    {
        // initialize the current, previous, and next pointers
        Node* curr = head;
        Node *prev = nullptr, *next = nullptr;

        while (curr != nullptr)
        {
            // store next
            next = curr->next;
            // reverse the current node's pointer
            curr->next = prev;
            // move pointers one position ahead
            prev = curr;
            curr = next;
        }
        head = prev;
    }
};

int main()
{
    LinkedList ll;
    ll.push(20);
    ll.push(12);
    ll.push(9);
    ll.push(18);
    ll.push(4);

    std::cout << "Given Linked List: " << std::endl;
    ll.print();

    std::cout << std::endl;

    std::cout << "Reversed Linked List: " << std::endl;
    ll.reverse();
    ll.print();

    return 0;
}