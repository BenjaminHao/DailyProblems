#include <iostream>
#include <unordered_set>

struct Node
{
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

struct LinkedList
{
    Node* head, *tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    // push method
    void push(int data)
    {
        Node* tmp = new Node(data);
        
        if (head == nullptr)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
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
};

void removeDuplicate(Node* head)
{
    // if no elements, return
    if (head == nullptr) return;
    
    // two pointers p and q used for traversing linked list
    Node* p = head, *q = head->next;
    // hash table used for store occurrences
    std::unordered_set<int> hash;

    hash.insert(head->data);

    while(q)
    {   
        // if the element has already existed
        if (hash.find(q->data) != hash.end())
        {
            // tmp pointer used for deleting Node
            Node *tmp = q;
            // p moves to p->next->next
            p->next = q->next;
            // q moves to next
            q = p->next;
            // remove duplicate
            delete tmp;
        }
        // if the element does not exist
        else
        {
            hash.insert(q->data);
            p = q;
            q = q->next;
        }
        
    }
}

int main()
{
    LinkedList ll;
    ll.push(1);
    ll.push(2);
    ll.push(3);
    ll.push(4);
    ll.push(5);
    ll.push(6);
    ll.push(7);
    ll.push(8);
    ll.push(9);
    ll.push(1);
    ll.push(2);
    ll.push(3);
    ll.push(3);

    std::cout << "Original Linked List:" << std::endl;
    ll.print();

    std::cout << "\nAfter removing duplicates:" << std::endl;
    removeDuplicate(ll.head);
    ll.print();
}