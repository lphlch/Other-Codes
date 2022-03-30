/*
2. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

2. 两数相加
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* node = new ListNode(0);
	ListNode* nextNode = node;
	int jw = 0;

	while (l1 != nullptr || l2 != nullptr)
	{
		int l1val = 0;
		int l2val = 0;
		if (l1 != nullptr)
		{
			l1val = l1->val;
		}
		if (l2 != nullptr)
		{
			l2val = l2->val;
		}
		ListNode* thisNode = new ListNode((l1val + l2val + jw) % 10);
		jw = (l1val + l2val + jw) / 10;
		nextNode->next = thisNode;
		nextNode = thisNode;
		if (l1 != nullptr)
		{
			l1 = l1->next;
		}
		if (l2 != nullptr)
		{
			l2 = l2->next;
		}
	}
	if (jw)
	{
		ListNode* thisNode = new ListNode(jw);
		nextNode->next = thisNode;
		nextNode = thisNode;
	}
	nextNode->next = nullptr;
	return node->next;
}

int main()
{
	ListNode* l1 = new ListNode(9);
	ListNode* l12 = new ListNode(9);
	l1->next = l12;
	ListNode* l2 = new ListNode(9);
	cout << addTwoNumbers(l1, l2);
	return 0;
}

