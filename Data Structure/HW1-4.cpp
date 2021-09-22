//2021/9/20

#define DEBUG_MODE 1
#include <iostream>
using namespace std;

struct PNode
{
	int coef;	//系数
	int expn;	//指数
	PNode* nextNode;
};

struct PNodeHead
{
	int length = 0;
	PNode* firstNode;
};

/// <summary>
/// 输入多项式链表
/// </summary>
/// <param name="pNodeHead">头结点</param>
/// <param name="length">长度</param>
void inputList(PNodeHead& pNodeHead, int length)
{
	if (length == 0)
	{
		pNodeHead.firstNode = NULL;
		return;
	}
	PNode* node = new(PNode);
	pNodeHead.firstNode = node;
	pNodeHead.length = length;
	while (length != 0)
	{
		length--;
		int coef, expn;
		cin >> node->coef >> node->expn;
		PNode* nextNode = new(PNode);
		node->nextNode = nextNode;
		if (length != 0)
		{
			node = node->nextNode;
		}
	}
	node->nextNode = NULL;
}

/// <summary>
/// 打印链表，元素和地址
/// </summary>
/// <param name="pNodeHead">头结点</param>
void printList(PNodeHead& pNodeHead)
{
	PNode* nextNode = pNodeHead.firstNode;
	int count = 1;
	if (nextNode == NULL)
	{
		cout << "NULL" << endl;
		return;
	}
	while (nextNode != NULL)
	{
		if (DEBUG_MODE)
		{
			cout << "pos:" << count << ' ' << nextNode->coef << ' ' << nextNode->expn << ' ' << nextNode->nextNode << endl;
		}
		else
		{
			cout << nextNode->coef << ' ' << nextNode->expn << ' ';
		}
		nextNode = nextNode->nextNode;
		count++;
	}
	if (DEBUG_MODE)
	{
		cout << "length: " << pNodeHead.length << endl;
	}
}

/// <summary>
/// 复制链表
/// </summary>
/// <param name="pNodeHeadSou">源链表头结点</param>
/// <param name="pNodeHeaDst">目标链表头结点</param>
void copyList(PNodeHead& pNodeHeadSou, PNodeHead& pNodeHeaDst)
{
	PNode* nodeSou = pNodeHeadSou.firstNode;
	PNode* nodeDst = new(PNode);
	pNodeHeaDst.length = pNodeHeadSou.length;
	if (pNodeHeadSou.firstNode != NULL)	//若下一个节点不是空
	{
		pNodeHeaDst.firstNode = nodeDst;
		nodeDst->coef = nodeSou->coef;
		nodeDst->expn = nodeSou->expn;
		nodeSou = nodeSou->nextNode;
		nodeDst->nextNode = NULL;
	}
	while (nodeSou != NULL)
	{
		PNode* nodeNew = new(PNode);
		nodeDst->nextNode = nodeNew;
		nodeNew->coef = nodeSou->coef;
		nodeNew->expn = nodeSou->expn;
		nodeNew->nextNode = NULL;
		nodeDst = nodeDst->nextNode;
		nodeSou = nodeSou->nextNode;
	}
}

PNode* searchNodeByExpn(PNodeHead& pNodeHead, int expn)
{
	PNode* nextNode = pNodeHead.firstNode;
	if (nextNode == NULL)
	{
		return NULL;
	}
	while (nextNode != NULL)
	{
		if (nextNode->expn == expn)
		{
			return nextNode;
		}
		nextNode = nextNode->nextNode;
	}
	return NULL;
}

PNode* getLastNode(PNodeHead& pNodeHead)
{
	PNode* node = pNodeHead.firstNode;
	if (node == NULL)
	{
		return (PNode*)&pNodeHead;
	}
	else
	{
		while (node->nextNode != NULL)
		{
			node = node->nextNode;
		}
		return node;
	}
}

/// <summary>
/// 更新链表长度
/// </summary>
/// <param name="pNodeHead">链表头结点</param>
/// <returns></returns>
int updateListLength(PNodeHead& pNodeHead)
{
	PNode* node = pNodeHead.firstNode;
	int length = 0;
	if (node == NULL)
	{
		return length;
	}
	else
	{
		length++;
		while (node->nextNode != NULL)
		{
			node = node->nextNode;
			length++;
		}
		return length;
	}
}

/// <summary>
/// 多项式加法，结果存储在链表1中，然后删除链表2
/// </summary>
/// <param name="pNodeHeadAdd1">链表1</param>
/// <param name="pNodeHeadAdd2">链表2</param>
void addList(PNodeHead& pNodeHeadAdd1, PNodeHead& pNodeHeadAdd2)
{
	int length = 0;
	PNode* node1 = pNodeHeadAdd1.firstNode;
	PNode* node2 = pNodeHeadAdd2.firstNode;
	PNode* nodeResult = (PNode*)&pNodeHeadAdd1;
	while (node1 != NULL && node2 != NULL)
	{
		if (node1->expn == node2->expn)
		{
			int sum = node1->coef + node2->coef;
			if (sum != 0)
			{
				node1->coef = sum;
				nodeResult->nextNode = node1;
				nodeResult = node1;
				node1 = node1->nextNode;

				PNode* tmpNode = node2;
				node2 = node2->nextNode;
				delete tmpNode;
			}
			else
			{
				//直接删除两个节点
				PNode* tmpNode = node1;
				node1 = node1->nextNode;
				delete tmpNode;

				tmpNode = node2;
				node2 = node2->nextNode;
				delete tmpNode;
			}
		}
		else if (node1->expn < node2->expn)	//只接，不删
		{
			nodeResult->nextNode = node1;
			nodeResult = node1;
			node1 = node1->nextNode;
		}
		else
		{
			nodeResult->nextNode = node2;
			nodeResult = node2;
			node2 = node2->nextNode;
		}
		nodeResult->nextNode = node1 ? node1 : node2;
	}
	pNodeHeadAdd1.length = updateListLength(pNodeHeadAdd1);
	return;
}

void mulList(PNodeHead& pNodeHeadMul1, PNodeHead& pNodeHeadMul2)
{
	/* 先将1中的每个乘到2上，赋给3 */

	/* 再将3的各个相加 */
}
int main()
{
	PNodeHead pList1, pList2;
	PNodeHead pList3;

	int length1, length2;

	cin >> length1;
	inputList(pList1, length1);
	//printList(pList1);
	cin >> length2;
	inputList(pList2, length2);
	//printList(pList2);

	int order;
	cin >> order;
	switch (order)
	{
		case 0:	//加
			addList(pList1, pList2);
			printList(pList1);
			break;
		case 1:	//乘

			break;
		default:
			break;
	}
	return 0;
}