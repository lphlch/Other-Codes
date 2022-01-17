//2021/10/9

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int SIZE = 12000;

template <typename T>
struct Stack
{
	T elems[SIZE]{};
	int head = 0;
	int customSize = 0;
	void push(T elem);
	void pop();
	T top();
	bool empty() const;
	bool full() const;
	size_t size() const;
	void print();
};

Stack<int> stack;

int main()
{
	int size;
	cin >> size;
	stack.customSize = size;

	string order;
	while (true)
	{
		cin >> order;
		if (order == "pop")
		{
			if (stack.empty())
			{
				cout << "Stack is Empty" << endl;
			}
			else
			{
				stack.pop();
				cout << stack.top()<<endl;
			}
		}
		if (order == "push")
		{
			int a;
			cin >> a;
			if (stack.full())
			{
				cout << "Stack is Full" << endl;
			}
			else
			{
				stack.push(a);
			}
		}
		if (order == "quit")
		{
			stack.print();
			break;
		}
	}
	return 0;
}

/// <summary>
/// 入栈，不判断是否满栈
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="elem">入栈元素</param>
template<typename T>
void Stack<T>::push(T elem)
{
	/* ⼊栈操作 */
	elems[head++] = elem;
}

/// <summary>
/// 出栈，栈顶在小于0时，仍旧为0，不会报错
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
void Stack<T>::pop()
{
	/* 出栈操作 */
	head--;
	if (head <= 0)
	{
		head = 0;
	}
}

/// <summary>
/// 返回栈顶元素
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>栈顶元素</returns>
template<typename T>
T Stack<T>::top()
{
	return elems[head-1];
}

/// <summary>
/// 判断是否为空
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template<typename T>
bool Stack<T>::empty() const
{
	return !head;
}

/// <summary>
/// 判断是否为满
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template<typename T>
bool Stack<T>::full() const
{
	if (head >= SIZE || head >= customSize)
	{
		return true;
	}
	return false;
}

/// <summary>
/// 返回目前栈内使用的容量
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>容量</returns>
template<typename T>
size_t Stack<T>::size() const
{
	return size_t(head);
}

/// <summary>
/// 输出栈内元素
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
void Stack<T>::print()
{
	for (int i = head-1; i >= 0; i--)
	{
		cout << elems[i] << ' ';
	}
}