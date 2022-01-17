//2021/10/12

#include <iostream>
#include <vector>
#include <queue>

const int SIZE = 100;
const int MAXSIZE = 1000;
using namespace std;

struct cellPoint
{
	int x;
	int y;
};
//#pragma region QUEUE
//template <typename T>
//struct Queue
//{
//	T elems[SIZE]{};
//	int head = 0;	//head指向队列头元素
//	int rear = 0;	//rear指向队列尾元素下一位
//	int count = 0;	//标记队列中元素个数，来处理循环队列中头尾相遇无法判断的问题
//
//	void push(T elem);
//	void pop();
//	T front();
//	bool empty();
//	bool full();
//	void print();
//};
//
///// <summary>
///// 入队列操作，不判断是否满队列
///// </summary>
///// <typeparam name="T"></typeparam>
///// <param name="elem">入队列元素</param>
//template<typename T>
//void Queue<T>::push(T elem)
//{
//	elems[rear] = elem;
//	rear = (rear + 1) % SIZE;
//	count++;
//}
//
///// <summary>
///// 出队列操作，不判断是否空队列
///// </summary>
///// <typeparam name="T"></typeparam>
//template<typename T>
//void Queue<T>::pop()
//{
//	T elem = elems[head];
//	head = (head + 1) % SIZE;
//	count--;
//}
//
///// <summary>
///// 返回队列头元素
///// </summary>
///// <typeparam name="T"></typeparam>
///// <returns>头元素</returns>
//template<typename T>
//T Queue<T>::front()
//{
//	return elems[head];
//}
//
///// <summary>
///// 判断队列是否为空
///// </summary>
///// <typeparam name="T"></typeparam>
///// <returns></returns>
//template<typename T>
//bool Queue<T>::empty()
//{
//	if (count <= 0)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
///// <summary>
///// 判断队列是否已满
///// </summary>
///// <typeparam name="T"></typeparam>
///// <returns></returns>
//template<typename T>
//bool Queue<T>::full()
//{
//	if (count >= SIZE)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//#pragma endregion

queue<cellPoint> waitQueue;
bool cells[MAXSIZE][MAXSIZE] = { 0 };	//0不启用
bool isChecked[MAXSIZE][MAXSIZE] = { 0 };	//0不启用

int main()
{
	int count = 0;

	int lines, columns;	//行，列
	cin >> lines >> columns;
	for (int k = 1; k <= lines; k++)
	{
		for (int p = 1; p <= columns; p++)
		{
			cin >> cells[k][p];
		}
	}

	for (int i = 2; i < lines; i++)
	{
		for (int j = 2; j < columns; j++)
		{
			if (cells[i][j] == true && isChecked[i][j] == false)	//若T且没检测过
			{
				isChecked[i][j] = true;
				cellPoint cell, enQueueCell;
				cell.x = i;
				cell.y = j;
				waitQueue.push(cell);	//放入等待检测队列
				while (!waitQueue.empty())
				{
					cell = waitQueue.front();
					waitQueue.pop();
					if (cells[cell.x - 1][cell.y] == true && !isChecked[cell.x - 1][cell.y])	//左
					{
						isChecked[cell.x - 1][cell.y] = true;
						enQueueCell.x = cell.x - 1;
						enQueueCell.y = cell.y;
						waitQueue.push(enQueueCell);
					}
					if (cells[cell.x + 1][cell.y] == true && !isChecked[cell.x + 1][cell.y])	//右
					{
						isChecked[cell.x + 1][cell.y] = true;
						enQueueCell.x = cell.x + 1;
						enQueueCell.y = cell.y;
						waitQueue.push(enQueueCell);
					}
					if (cells[cell.x][cell.y - 1] == true && !isChecked[cell.x][cell.y - 1])	//上
					{
						isChecked[cell.x][cell.y - 1] = true;
						enQueueCell.x = cell.x;
						enQueueCell.y = cell.y - 1;
						waitQueue.push(enQueueCell);
					}
					if (cells[cell.x][cell.y + 1] == true && !isChecked[cell.x][cell.y + 1])	//下
					{
						isChecked[cell.x][cell.y + 1] = true;
						enQueueCell.x = cell.x;
						enQueueCell.y = cell.y + 1;
						waitQueue.push(enQueueCell);
					}
				}
				count++;
			}
		}
	}

	cout << count << endl;
	return 0;
}