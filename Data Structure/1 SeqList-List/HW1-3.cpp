//2021/9/19
#include <iostream>
#include <string>
#include <cstring>
const int MAXSIZE = 2005;

using namespace std;
struct Poker
{
	string type;
	int num;
};

/* 以小的为顶，大的为底 */
/// <summary>
/// 顺序表
/// </summary>
struct SeqList
{
	//data
	Poker pokers[MAXSIZE];
	int length = 0;
	//function
	bool insert(int i, string type, int num);
	bool remove(int j);
	int checkByName(string name);
	void revert();
	void extract(string type);
	void print();	//for debug
}heap;

int numStrToNum(string numStr)
{
	if (numStr == "A")
	{
		return 1;
	}
	if (numStr == "J")
	{
		return 11;
	}
	if (numStr == "Q")
	{
		return 12;
	}
	if (numStr == "K")
	{
		return 13;
	}
	return atoi(numStr.c_str());
}

string numToNumStr(int num)
{
	switch (num)
	{
		case 1:
			return "A";
		case 11:
			return "J";
		case 12:
			return "Q";
		case 13:
			return "K";
		default:
			break;
	}
	return to_string(num);
}

/// <summary>
/// 插入元素
/// </summary>
/// <param name="i">插入位置</param>
/// <param name="type">花色</param>
/// <param name="num">编号</param>
/// <returns>插入是否成功</returns>
bool SeqList::insert(int i, string type, int num)
{
	if (i < 1 || this->length < i - 1 || this->length >= MAXSIZE)
	{
		return false;
	}
	this->length++;

	/* 移动 */
	for (int j = this->length; j > i; j--)
	{
		this->pokers[j] = this->pokers[j - 1];
	}
	/* 插入 */
	this->pokers[i].type = type;
	this->pokers[i].num = num;

	return true;
}

/// <summary>
/// 删除元素
/// </summary>
/// <param name="j">要删除的位置</param>
/// <returns>删除是否成功</returns>
bool SeqList::remove(int j)
{
	if (j<1 || j>this->length)
	{
		return false;
	}

	if (j != this->length)
	{
		/* 移动 */
		for (int i = j; i < this->length; i++)
		{
			this->pokers[i] = this->pokers[i + 1];
		}
	}

	this->length--;
	return true;
}

/// <summary>
/// 查找元素在顺序表中是否存在
/// </summary>
/// <param type="type">花色</param>
/// <returns>该元素的位置，未找到返回0</returns>
int SeqList::checkByName(string type)
{
	for (int i = 1; i <= this->length; i++)
	{
		if (this->pokers[i].type == type)
		{
			return i;
		}
	}
	return 0;
}

/// <summary>
/// 反转顺序表
/// </summary>
void SeqList::revert()
{
	for (int i = 1; i <= this->length / 2; i++)
	{
		swap(this->pokers[i], this->pokers[this->length - i + 1]);
	}
}

/// <summary>
/// 抽取，并按顺序放入牌堆顶
/// </summary>
/// <param name="type">要抽取的花色</param>
void SeqList::extract(string type)
{
	int numCount[14] = { 0 };
	while (true)
	{
		int pos = this->checkByName(type);
		if (pos != 0)
		{
			int num = this->pokers[pos].num;
			numCount[num]++;	//计数排序
			this->remove(pos);	//移除这张牌
		}
		else
		{
			break;
		}
	}
	for (int i = 13; i > 0; i--)	//先放入大的，再放入小的，这样小的在顶上
	{
		while (numCount[i] != 0)
		{
			this->insert(1, type, i);
			numCount[i]--;
		}
	}
}

void SeqList::print()
{
	if (this->length == 0)
	{
		//cout << "NULL" << endl;
		return;
	}

	for (int i = 1; i <= this->length; i++)
	{
		cout << this->pokers[i].type << ' ' << numToNumStr(this->pokers[i].num) << endl;
	}
}

int main()
{
	int orderCount;
	cin >> orderCount;

	while (orderCount != 0)
	{
		orderCount--;
		string order;
		cin >> order;
		if (order == "Append")
		{
			Poker poker;
			cin >> poker.type;
			string numStr;
			cin >> numStr;
			poker.num = numStrToNum(numStr);

			heap.insert(heap.length + 1, poker.type, poker.num);
		}

		if (order == "Extract")
		{
			string type;
			cin >> type;
			heap.extract(type);
		}

		if (order == "Revert")
		{
			heap.revert();
		}

		if (order == "Pop")
		{
			if (heap.length != 0)
			{
				cout << heap.pokers[1].type << ' ' << numToNumStr(heap.pokers[1].num) << endl;
				heap.remove(1);
			}
			else
			{
				cout << "NULL" << endl;
			}
		}

		if (order == "print" || order == "Print")
		{
			heap.print();
		}

	}
	heap.print();

	return 0;
}