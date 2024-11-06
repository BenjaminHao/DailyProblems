/**
 * Problem:
 *   https://leetcode.com/problems/design-linked-list/description/
 * Solution:
 *   https://leetcode.com/problems/design-linked-list/submissions/1444236899/
 * -----------------------------------------------------------------
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
struct Node
{
    int val;
    Node* next;
    Node(int n) : val(n), next(nullptr) {}
};

class MyLinkedList
{
private:
    int size;
    Node* head;

public:
    MyLinkedList() : size(0), head(nullptr) {}

    int get(int index)
    {
        if (index < 0 || index >= size) return -1;
        Node* cur = head;
        while (index--) cur = cur->next;
        return cur->val;
    }

    void addAtHead(int val)
    {
        Node* newHead = new Node(val);
        newHead->next = head;
        head = newHead;
        size++;
    }

    void addAtTail(int val)
    {
        Node* newTail = new Node(val);
        if (!head)
            head = newTail;
        else
        {
            Node* cur = head;
            while (cur->next) cur = cur->next;
            cur->next = newTail;
        }
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > size)
            return;
        else if (index == 0)
            addAtHead(val);
        else if (index == size)
            addAtTail(val);
        else
        {
            Node* cur = head;

            while (index > 1)
            {
                cur = cur->next;
                index--;
            }
            Node* newNode = new Node(val);
            newNode->next = cur->next;
            cur->next = newNode;
            size++;
        }
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size) return;
        Node* cur = head;
        if (index == 0)
        {
            head = head->next;
            delete cur;
        }
        else
        {
            while (index > 1)
            {
                cur = cur->next;
                index--;
            }
            Node* tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        }
        size--;
    }

    ~MyLinkedList()
    {
        while (head)
        {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
        }
    }
};
