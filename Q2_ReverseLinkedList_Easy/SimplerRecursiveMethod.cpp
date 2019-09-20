#include <iostream>

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
    Node* reverse(Node* node)
    {
        if (node == nullptr) return nullptr;
        if (node->next == nullptr)
        {
            head = node;
            return node;
        }
        Node* node1 = reverse(node->next);
        node1->next = node;
        node->next = nullptr;
        return node;
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
    ll.reverse(ll.head);
    ll.print();

    return 0;
}