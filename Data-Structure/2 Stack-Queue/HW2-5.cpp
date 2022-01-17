//2021/10/15
#include <iostream>
using namespace std;

const int SIZE = 11000;

#pragma region QUEUE
template <typename T>
struct Queue
{
	T elems[SIZE]{};
	int head = 0;	//head指向队列头元素
	int rear = 0;	//rear指向队列尾元素下一位
	int count = 0;	//标记队列中元素个数，来处理循环队列中头尾相遇无法判断的问题

	void push(T elem);
	void pop();
	T front();
	bool empty();
	bool full();
	size_t size() const;
};

/// <summary>
/// 入队列操作，不判断是否满队列
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="elem">入队列元素</param>
template<typename T>
void Queue<T>::push(T elem)
{
	elems[rear] = elem;
	rear = (rear + 1) % SIZE;
	count++;
}

/// <summary>
/// 出队列操作，不判断是否空队列
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
void Queue<T>::pop()
{
	T elem = elems[head];
	head = (head + 1) % SIZE;
	count--;
}

/// <summary>
/// 返回队列头元素
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>头元素</returns>
template<typename T>
T Queue<T>::front()
{
	return elems[head];
}

/// <summary>
/// 判断队列是否为空
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template<typename T>
bool Queue<T>::empty()
{
	if (count <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/// <summary>
/// 判断队列是否已满
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template<typename T>
bool Queue<T>::full()
{
	if (count >= SIZE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/// <summary>
/// 返回使用的容量
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template<typename T>
size_t Queue<T>::size() const
{
	return size_t(count);
}
#pragma endregion

#pragma region DEQUE
template <typename T>
struct Deque
{
	T elems[SIZE]{};
	int head = 0;	//head指向队列头元素
	int rear = 0;	//rear指向队列尾元素下一位
	int count = 0;	//标记队列中元素个数，来处理循环队列中头尾相遇无法判断的问题

	void push_front(T elem);
	void pop_front();
	void push_back(T elem);
	void pop_back();
	T front() const;
	T back() const;
	bool empty();
	bool full();
	void print();
};

/// <summary>
/// 头端入队列操作，不判断是否满队列
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="elem">入队列元素</param>
template<typename T>
void Deque<T>::push_front(T elem)
{
	head = (head + SIZE - 1) % SIZE;
	elems[head] = elem;
	count++;
}

/// <summary>
/// 头端出队列操作，不判断是否空队列
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
void Deque<T>::pop_front()
{
	T elem = elems[head];
	head = (head + 1) % SIZE;
	count--;
}

/// <summary>
/// 尾端入队列操作，不判断是否满队列
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="elem">入队列元素</param>
template<typename T>
void Deque<T>::push_back(T elem)
{
	elems[rear] = elem;
	rear = (rear + 1) % SIZE;
	count++;
}

/// <summary>
/// 尾端出队列操作，不判断是否空队列
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
void Deque<T>::pop_back()
{
	rear = (rear + SIZE - 1) % SIZE;
	T elem = elems[rear];
	count--;
}

/// <summary>
/// 返回队列头元素
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>头元素</returns>
template<typename T>
T Deque<T>::front() const
{
	return elems[head];
}

/// <summary>
/// 返回队列尾元素
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>尾元素</returns>
template<typename T>
T Deque<T>::back() const
{
	return elems[(rear + SIZE - 1) % SIZE];
}

/// <summary>
/// 判断队列是否为空
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template<typename T>
bool Deque<T>::empty()
{
	if (count <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/// <summary>
/// 判断队列是否已满
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template<typename T>
bool Deque<T>::full()
{
	if (count >= SIZE)
	{
		return true;
	}
	else
	{
		return false;
	}
}
#pragma endregion

Queue<int> numQ;
Deque<int> maxQ;

int main()
{
	int length;
	cin >> length;
	string order;
	while (true)
	{
		cin >> order;
		if (order == "dequeue")
		{
			if (numQ.empty())
			{
				cout << "Queue is Empty" << endl;
			}
			else
			{
				int dequeueNum = numQ.front();
				cout << dequeueNum << endl;
				numQ.pop();
				if (dequeueNum == maxQ.front())
				{
					maxQ.pop_front();
				}
			}
		}
		if (order == "enqueue")
		{
			int m;
			cin >> m;
			if (numQ.size() >= length)
			{
				cout << "Queue is Full" << endl;
			}
			else
			{
				numQ.push(m);
				while (!maxQ.empty() && maxQ.back() <= m)
				{
					maxQ.pop_back();
				}
				maxQ.push_back(m);
			}
		}
		if (order == "max")
		{
			if (numQ.empty())
			{
				cout << "Queue is Empty" << endl;
			}
			else
			{
				cout << maxQ.front() << endl;
			}
		}
		if (order == "quit")
		{
			while (!numQ.empty())
			{
				cout << numQ.front() << ' ';
				numQ.pop();
			}
			break;
		}
	}
}