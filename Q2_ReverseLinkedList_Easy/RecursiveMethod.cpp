#include <iostream>

/** 1. Divide the list in two parts - first node and rest of the linked list.
 *  2. Call reverse for the rest of the linked list.
 *  3. Link rest to first.
 * 4. Fix head pointer
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

    // reverse method: recusive method
    Node* reverse(Node* head)
    {
        // exist condition
        if (head == nullptr || head->next == nullptr) return head;

        // reverse the rest list and put the first element at the end
        Node* rest = reverse(head->next);
        head->next->next = head;

        head->next = nullptr;

        // fix the head pointer
        return rest;
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
    ll.head = ll.reverse(ll.head);
    ll.print();

    return 0;
}