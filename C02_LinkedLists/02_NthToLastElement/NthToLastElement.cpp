#include <iostream>

struct Node
{
	int data;
	Node *next;

	Node(int data) : data(data), next(nullptr) {}
};

Node *init(int a[], int n)
{
	Node *head = nullptr, *p = nullptr;

	for (int i = 0; i < n; ++i)
	{
		Node *node = new Node(a[i]);
		if (i == 0)
		{
			head = p = node;
			continue;
		}
		p->next = node;
		p = node;
	}
	return head;
}

// Method 1: two pointers
Node *findNthToLast(Node *head, int n)
{
	if (head == nullptr || n < 1)
		return nullptr;
	Node *p = head, *q = head;

	// move q to the right spot
	while (n > 0 && q)
	{
		q = q->next;
		--n;
	}
	// if q is null, n is still bigger than 0, n is too big, return null
	if (n > 0)
		return nullptr;

	// move p to the right spot
	while (q)
	{
		p = p->next;
		q = q->next;
	}

	return p;
}

// Method 2: recursion
Node *p2;
int n2;
void findNthToLastRecursion(Node *head)
{
	if (head == nullptr)
		return;
	findNthToLastRecursion(head->next);
	if (n2 == 1)
		p2 = head;
	--n2;
}

int main()
{
	int n = 10;
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	Node *head = init(a, n);

	// The result should be 4
	Node *p = findNthToLast(head, 6);
	if (p)
		std::cout << p->data << std::endl;
	else
		std::cout << "The length of linked list is not long enough" << std::endl;

	n2 = 6;
	findNthToLastRecursion(head);
	if (p2)
		std::cout << p->data << std::endl;
	else
		std::cout << "The length of linked list is not long enough" << std::endl;

	return 0;
}