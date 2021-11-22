#define _CRT_SECURE_NO_WARNINGS
//2021/9/28

#include <iostream>
#include <iomanip>
using namespace std;

const int MAXSIZE = 10000;

typedef struct {
	char no[8];   //8 位学号
	char name[20]; // 姓名
	double score;     // 成绩
}Student;

typedef Student ElemType;

struct SqList
{
	//data
	ElemType* elem;     // 指向数据元素的基地址
	int  length = 0;       // 线性表的当前长度
	int  listsize;      //线性表的最大容量
	//function
	bool init(int len);
	bool clear();
	bool insert(int i, ElemType& stu);
	bool remove(int j);
	int checkByName(char name[]);
	int checkByNum(char num[]);
	int checkByPos(int pos);
};

/// <summary>
/// 展示菜单
/// </summary>
void showMenu()
{
	cout << "学生信息管理系统" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "1.输入学生信息" << endl;
	cout << "2.显示学生信息" << endl;
	cout << "3.根据姓名查找学生信息" << endl;
	cout << "4.根据指定的位置查找学生信息" << endl;
	cout << "5.插入学生信息" << endl;
	cout << "6.删除指定位置的学生信息" << endl;
	cout << "7.统计学生个数" << endl;
	cout << "8.删除某学生的所有记录" << endl;
	cout << "9.删除重复记录" << endl;
	cout << "0.退出程序" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "请输入要操作的命令序号:" << endl;
	return;
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

void doOrder1(SqList& table)
{
	clear();
	cout << "请输入学生总人数：" << endl;
	int len = 0;
	table.clear();

	while (true)
	{
		cin >> len;
		if (len<1 || len>MAXSIZE)
		{
			cout << "人数非法，请重新输入！" << endl;
			cin.clear();
			cin.ignore(5000, '\n');
		}
		else
		{
			if (table.init(len))
			{
				cout << "请输入学号，姓名，成绩：" << endl;
				break;
			}
			else
			{
				cout << "初始化失败！" << endl;
			}
		}
	}

	table.length = len;
	for (int i = 1; i <= len; i++)
	{
		cin >> (table.elem[i].no) >> (table.elem[i].name) >> (table.elem[i].score);
	}
	wait();
}

void doOrder2(SqList& table)
{
	clear();
	int len = table.length;
	if (len == 0)
	{
		cout << "无任何信息！" << endl;
	}
	else
	{
		cout << setw(10) << left << "学号";
		cout << setw(20) << left << "姓名";
		cout << "成绩" << endl;
		for (int i = 1; i <= len; i++)
		{
			cout << setw(10) << left << (table.elem[i].no);
			cout << setw(20) << left << (table.elem[i].name);
			cout << (table.elem[i].score) << endl;
		}
	}

	wait();
}

void doOrder3(SqList& table)
{
	clear();
	cout << "请输入要查找的学生姓名：";
	char name[20];
	cin >> name;
	int pos = table.checkByName(name);
	if (pos)
	{
		cout << "学号 " << (table.elem[pos].no) << " 姓名 " << (table.elem[pos].name) << " 成绩 " << (table.elem[pos].score) << endl;
	}
	else
	{
		cout << "该学生不存在！" << endl;
	}
	wait();
}

void doOrder4(SqList& table)
{
	clear();
	cout << "请输入要查找的位置：";
	int pos = 0;
	cin >> pos;
	if (table.checkByPos(pos))
	{
		cout << "学号 " << (table.elem[pos].no) << " 姓名 " << (table.elem[pos].name) << " 成绩 " << (table.elem[pos].score) << endl;
	}
	else
	{
		cout << "无法查找到该位置的学生！" << endl;
	}
	wait();
}

void doOrder5(SqList& table)
{
	clear();
	ElemType stu;
	cout << "请输入要插入的学生学号，姓名，成绩：" << endl;
	cin >> (stu.no) >> (stu.name) >> (stu.score);
	cout << "请输入要插入的位置" << endl;
	int pos = 0;
	cin >> pos;
	if (!table.insert(pos, stu))
	{
		cout << "插入失败！" << endl;
	}
	wait();
}

void doOrder6(SqList& table)
{
	clear();
	cout << "请输入要删除的位置" << endl;
	int pos = 0;
	cin >> pos;
	if (!table.remove(pos))
	{
		cout << "删除失败！" << endl;
	}
	wait();
}

void doOrder7(SqList& table)
{
	clear();
	cout << "共有学生" << table.length << "人" << endl;
	wait();
}

void doOrder8(SqList& table)
{
	clear();
	cout << "请输入要删除的学生姓名" << endl;
	char name[20];
	cin >> name;
	int pos = 0;
	pos = table.checkByName(name);
	while (pos)
	{
		if (!table.remove(pos))
		{
			cout << "删除失败！" << endl;
		}
		pos = table.checkByName(name);
	}
	wait();
}

void doOrder9(SqList& table)
{
	clear();
	cout << "正在删除重复记录……" << endl;
	for (int i = 1; i <= table.length; i++)
	{
		int pos = table.checkByNum(table.elem[i].no);
		if (pos != i)
		{
			if (!table.remove(pos))
			{
				cout << "删除失败！" << endl;
			}
			i--;
		}
	}
	cout << "删除完成！" << endl;
	wait();
}

int main()
{
	SqList table;
	while (true)
	{
		clear();
		showMenu();
		int order;
		cin >> order;
		switch (order)
		{
			case 1:
				doOrder1(table);
				break;
			case 2:
				doOrder2(table);
				break;
			case 3:
				doOrder3(table);
				break;
			case 4:
				doOrder4(table);
				break;
			case 5:
				doOrder5(table);
				break;
			case 6:
				doOrder6(table);
				break;
			case 7:
				doOrder7(table);
				break;
			case 8:
				doOrder8(table);
				break;
			case 9:
				doOrder9(table);
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

/// <summary>
/// 初始化，时间复杂度o(1)
/// </summary>
/// <param name="len">长度</param>
/// <returns>是否成功</returns>
bool SqList::init(int len)
{
	this->elem = new(ElemType[MAXSIZE]);
	if (elem)
	{
		return true;
	}
	return false;
}

/// <summary>
/// 清空表，时间复杂度o(1)
/// </summary>
/// <returns></returns>
bool SqList::clear()
{
	if (length != 0)
	{
		delete[]elem;
	}
	this->length = 0;
	return true;
}

/// <summary>
/// 插入学生信息，时间复杂度o(n)
/// </summary>
/// <param name="i">位置</param>
/// <param name="num">学号</param>
/// <param name="name">姓名</param>
/// <returns>插入是否成功</returns>
bool SqList::insert(int i, ElemType& stu)
{
	if (i < 1 || this->length < i - 1 || this->length >= MAXSIZE)
	{
		return false;
	}
	this->length++;

	/* 移动 */
	for (int j = this->length; j > i; j--)
	{
		this->elem[j] = this->elem[j - 1];
	}
	/* 插入 */
	strcpy(this->elem[i].name, stu.name);
	strcpy(this->elem[i].no, stu.no);
	this->elem[i].score = stu.score;

	return true;
}

/// <summary>
/// 删除元素，时间复杂度o(n)
/// </summary>
/// <param name="j">要删除的位置</param>
/// <returns>删除是否成功</returns>
bool SqList::remove(int j)
{
	if (j<1 || j>this->length || j > 20000)
	{
		return false;
	}

	if (j != this->length)
	{
		/* 移动 */
		for (int i = j; i < this->length; i++)
		{
			this->elem[i] = this->elem[i + 1];
		}
	}

	this->length--;
	return true;
}

/// <summary>
/// 查找姓名在顺序表中是否存在,时间复杂度o(n)
/// </summary>
/// <param name="name">姓名</param>
/// <returns>该姓名的位置，未找到返回0</returns>
int SqList::checkByName(char name[])
{
	for (int i = 1; i <= this->length; i++)
	{
		if (strcmp(this->elem[i].name, name) == 0)
		{
			return i;
		}
	}
	return 0;
}

/// <summary>
/// 查找学号在顺序表中是否存在,时间复杂度o(n)
/// </summary>
/// <param name="num">学号</param>
/// <returns>该学号的位置，未找到返回0</returns>
int SqList::checkByNum(char num[])
{
	for (int i = 1; i <= this->length; i++)
	{
		if (strcmp(this->elem[i].no, num) == 0)
		{
			return i;
		}
	}
	return 0;
}

/// <summary>
/// 根据位置返回位置，主要是用来检测合法性,时间复杂度o(1)
/// </summary>
/// <param name="pos">位置</param>
/// <returns>不合法返回0</returns>
int SqList::checkByPos(int pos)
{
	if (pos<1 || pos > this->length)
	{
		return 0;
	}
	return pos;
}