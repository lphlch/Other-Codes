//2021/9/30

#include <iostream>
#include <iomanip>
#include <stack>

using namespace std;

typedef int ElemType;

typedef struct Node
{
	ElemType data;     // 节点数据
	Node* next = NULL;
}Node, * LinkList;

/// <summary>
/// 输入多项式链表，需要从小到大有序。时间复杂度o(n)
/// </summary>
/// <param name="list">头结点</param>
/// <param name="length">长度</param>
/// <returns>若输入无序，返回false</returns>
bool inputList(LinkList list, int length)
{
	if (length == 0)
	{
		list->next = NULL;
		return true;
	}
	Node* node = new(Node);
	list->next = node;

	int data = -INT_MAX;
	int nextdata;

	while (length != 0)
	{
		length--;
		cin >> nextdata;
		if (nextdata < data)
		{
			return false;
		}
		node->data = nextdata;
		data = nextdata;
		Node* nextNode = new(Node);
		node->next = nextNode;
		if (length != 0)
		{
			node = node->next;
		}
	}
	node->next = NULL;
	return true;
}

/// <summary>
/// 删除除头结点外的整个链表.时间复杂度o(n)
/// </summary>
/// <param name="list">链表头结点</param>
void clearList(LinkList list)
{
	Node* node = list->next;
	while (node)
	{
		Node* p = node;
		node = node->next;
		delete p;
	}
	list->next = NULL;
}

/// <summary>
/// 打印链表.时间复杂度o(n)
/// </summary>
/// <param name="list">头结点</param>
void printList(LinkList list)
{
	Node* node = list->next;
	int count = 1;
	if (node == NULL)
	{
		cout << "链表为空！" << endl;
		return;
	}
	cout << setw(5) << left << "序号";
	cout << setw(10) << left << "值";
	cout << setw(10) << left << "下一结点地址" << endl;

	while (node != NULL)
	{
		cout << setw(5) << left << count;
		cout << setw(10) << left << node->data;
		cout << setw(10) << left << node->next << endl;

		node = node->next;
		count++;
	}
	cout << "总长度：" << count-1 << endl;
}

/// <summary>
/// 根据值查找结点.时间复杂度o(n)
/// </summary>
/// <param name="list">链表头结点</param>
/// <param name="key">元素</param>
/// <returns>结点地址，未找到返回NULL</returns>
Node* searchNode(LinkList list, ElemType key)
{
	Node* node = list->next;
	while (node)
	{
		if (node->data == key)
		{
			return node;
		}
		node = node->next;
	}
	return NULL;
}

/// <summary>
/// 插入结点，需要有序.时间复杂度o(n)
/// </summary>
/// <param name="list">原链表头结点</param>
/// <param name="value">要插入的结点</param>
void insertNode(LinkList list, ElemType value)
{
	if (list->next == NULL)	//头结点为空，直接插入
	{
		Node* newNode = new(Node);
		list->next = newNode;
		newNode->data = value;
		newNode->next = NULL;
		return;
	}

	Node* node = list;
	while (node->next)	//在中间
	{
		if (node->next->data >= value)
		{
			Node* newNode = new(Node);
			newNode->next = node->next;
			newNode->data = value;
			node->next = newNode;
			return;
		}
		node = node->next;
	}

	Node* newNode = new(Node);	//在最后，接上
	newNode->data = value;
	newNode->next = NULL;
	node->next = newNode;
}

/// <summary>
/// 删除一个结点.时间复杂度o(n)
/// </summary>
/// <param name="list">链表头结点</param>
/// <param name="key">要删除的结点值</param>
/// <returns>若不存在返回False</returns>
bool deleteNode(LinkList list, ElemType key)
{
	Node* node = list;
	while (node->next)
	{
		if (node->next->data == key)
		{
			Node* p = node->next;
			node->next = node->next->next;
			delete p;
			return true;
		}
		node = node->next;
	}
	return false;
}

/// <summary>
/// 逆置链表.时间复杂度o(n)
/// </summary>
/// <param name="list">链表头结点</param>
void reverseList(LinkList list)
{
	stack<ElemType> tmp;
	Node* node = list->next;
	while (node)
	{
		tmp.push(node->data);
		node = node->next;
	}
	node = list->next;
	while (node)
	{
		node->data = tmp.top();
		tmp.pop();
		node = node->next;
	}
}

/// <summary>
/// 删除重复结点.时间复杂度o(n2)
/// </summary>
/// <param name="list">链表头结点</param>
void deleteRepeatNode(LinkList list)
{
	Node* node = list->next;
	while (node && node->next)
	{
		while (node->next && node->data == node->next->data)
		{
			Node* p = node->next;
			node->next = node->next->next;
			delete p;
		}
		node = node->next;
	}
}

/// <summary>
/// 合并两个有序链表.时间复杂度o(n2)
/// </summary>
/// <param name="dstList">合并目标链表</param>
/// <param name="souList">被合并的链表</param>
void combineList(LinkList dstList, LinkList souList)
{
	Node* node = souList->next;
	while (node)
	{
		Node* p = node;
		insertNode(dstList, node->data);	//对于每个2链表内数值，插入到1链表中
		node = node->next;
		delete p;
	}
}

/// <summary>
/// 清除屏幕
/// </summary>
void clear()
{
	system("cls");
}

/// <summary>
/// 等待按键
/// </summary>
void wait()
{
	cin.clear();
	cin.ignore(5000, '\n');
	cout << endl << "按任意键继续……" << endl;
	getchar();
}

/// <summary>
/// 展示菜单
/// </summary>
void showMenu()
{
	cout << "单链表的基本与进阶操作" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "1.输入链表信息" << endl;
	cout << "2.显示链表信息" << endl;
	cout << "3.查找结点" << endl;
	cout << "4.插入结点" << endl;
	cout << "5.删除结点" << endl;
	cout << "6.逆置链表" << endl;
	cout << "7.删除重复结点" << endl;
	cout << "8.合并两个有序链表" << endl;
	cout << "0.退出程序" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "请输入要操作的命令序号:" << endl;
	return;
}

bool doOrder1(LinkList list)
{
	clear();
	cout << "请输入要输入的链表长度：";
	int len = 0;
	while (len <= 0)
	{
		cin >> len;
		if (len <= 0)
		{
			cout << "长度不合法！请重新输入：";
		}
		cin.clear();
		cin.ignore(5000, '\n');
	}
	cout << "请依次输入各结点的值，需要从小到大输入" << endl;
	if (!inputList(list, len))
	{
		cout << "输入非有序，输入失败！" << endl;
		clearList(list);	//清空已输入的链表
		wait();
		return false;
	}
	cout << "输入完成！" << endl;
	wait();
	return true;
}

void doOrder2(LinkList list)
{
	clear();

	cout << "链表的各结点值如下：" << endl;
	printList(list);

	wait();
}

void doOrder3(LinkList list)
{
	clear();

	cout << "请输入要查找的元素值：";
	ElemType key;
	cin >> key;

	Node* result = searchNode(list, key);
	if (result)
	{
		cout << "Address:" << result << " Value:" << key << endl;
	}
	else
	{
		cout << "找不到该元素！" << endl;
	}

	wait();
}

void doOrder4(LinkList list)
{
	clear();

	cout << "请输入要插入的结点的值：";
	ElemType value;
	cin >> value;
	insertNode(list, value);
	cout << "插入完成！" << endl;

	wait();
}

void doOrder5(LinkList list)
{
	clear();

	cout << "请输入要删除的结点值：";
	ElemType key;
	cin >> key;
	if (cin.fail())
	{
		cout << "输入不合法！" << endl;
	}
	else if (!deleteNode(list, key))
	{
		cout << "删除失败！无该值！" << endl;
	}
	else
	{
		cout << "删除完成！" << endl;
	}

	wait();
}

void doOrder6(LinkList list)
{
	clear();

	cout << "正在逆置链表……" << endl;

	reverseList(list);

	cout << "逆置完成！" << endl;

	wait();
}

void doOrder7(LinkList list)
{
	clear();

	cout << "正在删除重复结点……" << endl;

	deleteRepeatNode(list);

	cout << "删除重复结点完成！" << endl;

	wait();
}

void doOrder8(LinkList list)
{
	clear();

	cout << "请先输入第二个有序链表……" << endl;
	wait();
	LinkList listtmp = new(Node);
	if (!doOrder1(listtmp))	//输入第二个链表
	{
		return;
	}
	else
	{
		cout << "开始合并列表……" << endl;
		combineList(list, listtmp);
		cout << "合并完成！" << endl;
	}

	wait();
}

int main()
{
	LinkList list = new(Node);
	while (true)
	{
		clear();
		showMenu();
		int order;
		cin >> order;
		switch (order)
		{
			case 1:
				doOrder1(list);
				break;
			case 2:
				doOrder2(list);
				break;
			case 3:
				doOrder3(list);
				break;
			case 4:
				doOrder4(list);
				break;
			case 5:
				doOrder5(list);
				break;
			case 6:
				doOrder6(list);
				break;
			case 7:
				doOrder7(list);
				break;
			case 8:
				doOrder8(list);
				break;
			case 0:
				exit(1);
			default:
				cout << "ERROR!错误的命令序号，请重新输入!" << endl;
				wait();
				break;
		}
	}

	return 0;
}