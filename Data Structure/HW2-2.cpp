//2021/10/9

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#pragma region STACK

const int SIZE = 1000;

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
	return elems[head - 1];
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
	for (int i = head - 1; i >= 0; i--)
	{
		cout << elems[i] << ' ';
	}
}

#pragma endregion

/// <summary>
/// 判断出栈序列是否合法
/// </summary>
/// <param name="out">出栈序列</param>
/// <param name="in">入栈序列</param>
/// <returns></returns>
bool isLegal(const string out, const string in)
{
	Stack<char> stack;

	for (int i = 0, j = 0; out[i] != '\0'; i++)
	{
		while (true)
		{
			if (stack.top() == out[i])	//若栈顶就是出栈元素，出栈
			{
				stack.pop();
				break;
			}
			else if (in[j] == out[i])		//若还未入栈的元素就是出栈元素，该元素直接出
			{
				j++;
				break;
			}
			else //否则入栈一个元素，循环判断
			{
				if (in[j] == '\0')
				{
					return false;	//已经全部入栈都不行，说明无法实现
				}
				stack.push(in[j]);
				j++;
			}
		}
	}

	return true;
}

int main()
{
	string in;	//入栈序列
	cin >> in;

	/*
		对于每个出栈元素：
		要么 在栈顶
		要么 还未入栈

		如果不是这两种清况，则无法实现
	*/

	while (true)
	{
		string out;
		cin >> out;
		if (cin.eof())
		{
			break;
		}

		if (isLegal(out, in))
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
	return 0;
}