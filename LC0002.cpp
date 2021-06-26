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

