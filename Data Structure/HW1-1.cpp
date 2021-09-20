//2021/9/18

#include <iostream>
#include <string>
using namespace std;
const int MAXSIZE = 30000;

/// <summary>
/// 存储每个学生的信息
/// </summary>
struct Data
{
	string num;
	string name;
};

/// <summary>
/// 顺序表
/// </summary>
struct SeqList
{
	//data
	Data students[MAXSIZE];
	int length = 0;
	//function
	bool insert(int i, string num, string name);
	bool remove(int j);
	int checkByName(string name);
	int checkByNum(string num);
}table;

int main()
{
	int n;
	cin >> n;
	table.length = n;
	for (int i = 1; i <= n; i++)
	{
		cin >> (table.students[i].num) >> (table.students[i].name);
	}

	while (true)
	{
		string order;
		cin >> order;
		if (order == "insert")
		{
			int pos;
			string num;
			string name;
			cin >> pos >> num >> name;
			if (table.insert(pos, num, name))
			{
				cout << 0 << endl;
			}
			else
			{
				cout << -1 << endl;
			}
			continue;
		}

		if (order == "remove")
		{
			int pos;
			cin >> pos;
			if (table.remove(pos))
			{
				cout << 0 << endl;
			}
			else
			{
				cout << -1 << endl;
			}
			continue;
		}

		if (order == "check")
		{
			string subOrder;
			string key;

			int pos = 0;

			cin >> subOrder;
			cin >> key;
			if (subOrder == "name")
			{
				pos = table.checkByName(key);
			}
			if (subOrder == "no")
			{
				pos = table.checkByNum(key);
			}

			if (pos)
			{
				cout << pos << ' ' << table.students[pos].num << ' ' << table.students[pos].name << endl;
			}
			else
			{
				cout << -1 << endl;
			}
			continue;
		}

		if (order == "print")
		{
			/* for debug */
			for (int i = 1; i <= table.length; i++)
			{
				cout << (table.students[i].num) << ' ' << (table.students[i].name) << endl;
			}
			cout << table.length << endl;
			continue;
		}

		if (order == "end")
		{
			cout << table.length << endl;
			break;
		}
	}

	return 0;
}

/// <summary>
/// 插入学生信息
/// </summary>
/// <param name="i">位置</param>
/// <param name="num">学号</param>
/// <param name="name">姓名</param>
/// <returns>插入是否成功</returns>
bool SeqList::insert(int i, string num, string name)
{
	if (i < 1 || this->length < i - 1 || this->length >= 20000)
	{
		return false;
	}
	this->length++;

	/* 移动 */
	for (int j = this->length; j > i; j--)
	{
		this->students[j] = this->students[j - 1];
	}
	/* 插入 */
	this->students[i].name = name;
	this->students[i].num = num;

	return true;
}

/// <summary>
/// 删除元素
/// </summary>
/// <param name="j">要删除的位置</param>
/// <returns>删除是否成功</returns>
bool SeqList::remove(int j)
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
			this->students[i] = this->students[i + 1];
		}
	}

	this->length--;
	return true;
}

/// <summary>
/// 查找姓名在顺序表中是否存在
/// </summary>
/// <param name="name">姓名</param>
/// <returns>该姓名的位置，未找到返回0</returns>
int SeqList::checkByName(string name)
{
	for (int i = 1; i <= this->length; i++)
	{
		if (this->students[i].name == name)
		{
			return i;
		}
	}
	return 0;
}

/// <summary>
/// 查找学号在顺序表中是否存在
/// </summary>
/// <param name="num">学号</param>
/// <returns>该学号的位置，未找到返回0</returns>
int SeqList::checkByNum(string num)
{
	for (int i = 1; i <= this->length; i++)
	{
		if (this->students[i].num == num)
		{
			return i;
		}
	}
	return 0;
}