#include "List.h"
#include <iostream>
#include <exception>
namespace list
{
	List* FindItem(int ind, List* head)
	{
		if (head == nullptr) throw std::out_of_range("List is empty");
		if (ind < 0) throw std::invalid_argument("Negative index");
		int num = 0;
		List* p = head;
		while (num != ind)
		{
			if (p->next == nullptr) break;
			num++;
			p = p->next;
		}
		if (num < ind) throw std::out_of_range("");
		return p;
	}
	List* AddLast(int val, List* head)
	{
		List* q = new List(val), * p = head;
		if (head == nullptr) return q;
		while (p->next != nullptr)
			p = p->next;
		p->next = q;
		return head;
	}
	List* Change(int A, int B, List* head)
	{
		if (head == nullptr) throw std::out_of_range("Empty list");
		List* p = head, * q = nullptr;
		int num = 0;
		while (p->next != nullptr)
		{
			if (p->value == A) { p->value = B; q = p; }
			p = p->next;
			num++;
		}
		if (p->value == A) { p->value = B; q = p; }
		return q;
	}
	List* AddReverseList(List* head1, List* head2)
	{
		if (head2 == nullptr) return head1;
		List* head = head1, * p = head2;
		if (p->next == nullptr)
		{
			head = AddLast(p->value, head);
			return head;
		}
		head = AddReverseList(head, p->next);
		head = AddLast(p->value, head);
		return head;
	}
}