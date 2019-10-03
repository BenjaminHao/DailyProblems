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
	Node* head, * tail;

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

	// pointer used for traversing linked list
	Node* p = head;
	// hash table used for store occurrences
	std::unordered_set<int> hash;

	hash.insert(p->data);

	while (p->next)
	{
		// if the element has already existed
		if (hash.find(p->next->data) != hash.end())
		{
			// tmp pointer used for deleting Node
			Node* tmp = p->next;
			// p->next points to p->next->next
			p->next = p->next->next;
			// remove duplicate
			delete tmp;
		}
		// if the element does not exist
		else
		{
			hash.insert(p->next->data);
			// p points to next node
			p = p->next;
		}

	}
}

void removeDuplicateWithoutExtraSpace(Node* head)
{
	if (head == nullptr) return;
	// two pointers technique
	Node* p = head, * q = head->next, *r = head;

	while (r)
	{
		p = r;
		q = r->next;
		int data = r->data;

		while (q)
		{
			// if the next data equals to current data
			if (q->data == data)
			{
				// tmp pointer used for deleting node
				Node* tmp = q;
				// p->next points to next->next
				p->next = q->next;
				// q->next points to next->next
				q = p->next;
				// delete node
				delete tmp;
			}
			else
			{
				// p points to q
				p = q;
				// q points to next node
				q = q->next;
			}

		}
		r = r->next;
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
	ll.push(0);

	std::cout << "Original Linked List:" << std::endl;
	ll.print();

	std::cout << "\nAfter removing duplicates:" << std::endl;
	removeDuplicate(ll.head);
	ll.print();
}