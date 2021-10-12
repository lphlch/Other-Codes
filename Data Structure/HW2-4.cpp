//2021/10/12

#include <iostream>
const int SIZE = 1000;

using namespace std;
#pragma region QUEUE

template <typename T>
struct Queue
{
	T elems[SIZE]{};
	int front = 0;	//front指向队列头元素
	int rear = 0;	//rear指向队列尾元素下一位
	int count = 0;	//标记队列中元素个数，来处理循环队列中头尾相遇无法判断的问题

	void push(T elem);
	void pop();
	T front();
	bool empty();
	bool full();
	void print();
};

/// <summary>
/// ⼊队列操作，不判断是否满队列
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
	T elem = elems[front];
	front = (front + 1) % SIZE;
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
	return elems[front];
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

template<typename T>
void Queue<T>::print()
{
	cout << '[';
	for (int i = front; count > 0; count--)
	{
		cout << elems[i] << ',';
		i = (i + 1) % SIZE;
	}
	cout << ']' << endl;
}

#pragma endregion

int main()
{

	return 0;
}