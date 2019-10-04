#include <iostream>

struct Node
{
	int data;
	Node* next;

	Node(int data) : data(data), next(nullptr) {}
};

Node* init(int a[], int n)
{
	Node* head = nullptr, * p = nullptr;

	for (int i = 0; i < n; ++i)
	{
		Node* node = new Node(a[i]);

		if (i == 0)
		{
			head = node;
			p = node;
			continue;
		}
		p->next = node;
		p = node;
	}

	return head;
}

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

void print(Node* head)
{
	while (head)
	{
		std::cout << head->data << " ";
		head = head->next;
	}
	std::cout << std::endl;
}

int main()
{
	int n = 10;
	int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Node* head = init(a, n);

	// get a pointer
	int pp = 3;
	Node* p1 = head, * p2 = head;
	for (int i = 1; i < pp; ++i) p1 = p1->next;
	while (p2->next != nullptr) p2 = p2->next;

	std::cout << "Original linked list: " << std::endl;
	print(head);

	std::cout << "Remove the third element: " << std::endl;
	remove(p1);
	print(head);

	std::cout << "Remove the last element: " << std::endl;
	remove(p2);
	print(head);
}