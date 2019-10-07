#include <iostream>

struct Node
{
	int data;
	Node* prev;
	Node* next;

	Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

struct LinkedList
{
	Node* head = nullptr, * tail = nullptr, * p = nullptr;

	void push(int a)
	{
		if (head == nullptr)
		{
			head = new Node(a);
			tail = head;
		}
		else
		{
			p = new Node(a);
			p->prev = tail;
			tail->next = p;
			tail = tail->next;
		}
	}

	void printReverse()
	{
		while (tail != head)
		{
			std::cout << tail->data;
			tail = tail->prev;
		}
		std::cout << head->data << std::endl;
	}

	LinkedList() : head(nullptr), tail(nullptr) {}
};

Node* AddTwoNumbers(Node* l1, Node* l2)
{
	Node dummy(0);
	Node* p = &dummy;
	int carry = 0;

	while (l1 != nullptr || l2 != nullptr || carry != 0)
	{
		int sum = (l1 == nullptr ? 0 : l1->data)
			+ (l2 == nullptr ? 0 : l2->data) + carry;
		carry = sum / 10;
		p->next = new Node(sum % 10);

		p = p->next;
		l1 = l1 == nullptr ? nullptr : l1->next;
		l2 = l2 == nullptr ? nullptr : l2->next;
	}

	return dummy.next;
}

int main()
{
	LinkedList l1, l2, res;
	// l1: 513
	l1.push(3);
	l1.push(1);
	l1.push(5);
	// l2: 195
	l2.push(5);
	l2.push(9);
	l2.push(1);

	std::cout << "Two Numbers: " << std::endl;
	l1.printReverse();
	std::cout << " + " << std::endl;
	l2.printReverse();
	std::cout << " = " << std::endl;

    // tmp Node pointer to store value
	Node* tmp = AddTwoNumbers(l1.head, l2.head);
	while (tmp)
	{
        // tmp_d is used for deleting tmp Nodes
		Node* tmp_d = tmp;
        // push data into Linked List to print it reversely
		res.push(tmp->data);
		tmp = tmp->next;
        // delete tmp Nodes to get rid of memory leak
		delete tmp_d;
	}
	res.printReverse();
	return 0;
/* Output:
** Two Numbers:
** 513
**  +
** 195
**  =
** 708
*/
}