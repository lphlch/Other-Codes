//2021/10/19

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#pragma region STACK
const int SIZE = 100000;

template <typename T>
struct Stack
{
	T elems[SIZE]{};
	int head = 0;
	int customSize = 0;
	void push(T elem);	//入栈
	void pop();			//出栈
	T top();			//返回栈顶
	bool empty() const;	//判断空
	bool full() const;	//判断满
	size_t size() const;//返回占用
	void print();
};

/// <summary>
/// 入栈，不判断是否满栈，时间复杂度o(1)
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
/// 出栈，栈顶在小于0时，仍旧为0，不会报错，时间复杂度o(1)
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
/// 返回栈顶元素，时间复杂度o(1)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>栈顶元素</returns>
template<typename T>
T Stack<T>::top()
{
	return elems[head - 1];
}

/// <summary>
/// 判断是否为空，时间复杂度o(1)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template<typename T>
bool Stack<T>::empty() const
{
	return !head;
}

/// <summary>
/// 判断是否为满，时间复杂度o(1)
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
/// 返回目前栈内使用的容量，时间复杂度o(1)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>容量</returns>
template<typename T>
size_t Stack<T>::size() const
{
	return size_t(head);
}

/// <summary>
/// 输出栈内元素，时间复杂度o(n)
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
/// 高精度乘法，时间复杂度o(n2)
/// </summary>
/// <param name="mut1">乘数1</param>
/// <param name="mut2">乘数2</param>
/// <returns>积</returns>
string highPrecisionMutil(string mut1, string mut2)
{
	string result;

	/* 反向存储 */
	int len1 = mut1.length();
	vector<int> num1(len1);
	for (int i = 0; i < len1; i++)
	{
		num1[i] = mut1[len1 - i - 1] - '0';
	}
	int len2 = mut2.length();
	vector<int> num2(len2);
	for (int i = 0; i < len2; i++)
	{
		num2[i] = mut2[len2 - i - 1] - '0';
	}

	int carry = 0;	//进位
	vector<int> product(len1 + len2 + 1);
	for (int i = 0; i < len1; i++)
	{
		int carry = 0;
		for (int j = 0; j < len2; j++)
		{
			product[i + j] = product[i + j] + num1[i] * num2[j] + carry;
			carry = product[i + j] / 10;
			product[i + j] = product[i + j] % 10;
		}
		product[i + len2] = carry;         //进位
	}
	for (int i = 0; i < len1 + len2 + 1; i++)
	{
		result = result + (char)(product[i] + '0');
	}

	/* 删除最高位的0 */
	while (result.length() != 1 && result[result.length() - 1] == '0')
	{
		result.pop_back();
	}

	reverse(result.begin(), result.end());	//反转字符串
	return result;
}

struct Data
{
	int n; //函数的输入参数
	string(*function)(string, string);	//调用时的表达式函数指针
};

Stack<Data> myStack;

/// <summary>
/// 模拟阶乘，时间复杂度o(n3)(因为递归n次，每次递归的高精度乘法复杂度n2)
/// </summary>
/// <typeparam name="int"></typeparam>
/// <returns></returns>
string factorial(int n)
{
	Data fun;
	fun.n = n;
	string result = "0";
	while (n != 1)
	{
		fun.n = n;
		fun.function = highPrecisionMutil;
		myStack.push(fun);	//模拟入栈
		cout << "push n: " << fun.n << " 栈容量已使用: " << myStack.size() << endl;
		n--;
	}
	result = "1";	//n=1时return1
	cout << "n=1,无需push，现在result=1" << endl;
	cout << "\n递归完成，现在开始回溯...\n" << endl;
	while (!myStack.empty())
	{
		int argn = myStack.top().n;		//模拟调用f(n-1)
		string(*argf)(string, string) = myStack.top().function;

		myStack.pop();//模拟递归
		result = argf(result, to_string(argn));	//模拟计算n*f(n-1)

		cout << "pop n: " << argn << " 弹出后临时结果: " << result << " 栈容量已使用: " << myStack.size() << endl;
	}
	return result;
}

int main()
{
	int n;
	while (true)
	{
		cout << "请输入一个非零整数：";
		cin >> n;
		if (cin.fail() || n <= 0)
		{
			cout << "输入非法，请重新输入非零整数！" << endl;
			cin.clear();
			cin.ignore(5000, '\n');
		}
		else if (n > 1000)
		{
			cout << "该数过大，耗时可能会很久，输出量可能非常大:(\n按N重新输入，按Y继续执行";
			char c;
			cin >> c;
			if (c == 'n' || c == 'N')
			{
				cin.clear();
				cin.ignore(5000, '\n');
				continue;
			}
			break;
		}
		else
		{
			break;
		}
	}
	cout << "阶乘结果为： " << factorial(n) << endl;

	return 0;
}