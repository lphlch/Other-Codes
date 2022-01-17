//2021/9/23

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/// <summary>
/// 高精度加法
/// </summary>
/// <param name="add1">加数1</param>
/// <param name="add2">加数2</param>
/// <returns>string和</returns>
string highPrecisionAdd(string add1, string add2)
{
	/*字符串预处理*/
	if (add1.length() > add2.length())	//交换两数,使小的在前
	{
		swap(add1, add2);
	}
	int deltaLen = (int)(add2.length() - add1.length());
	for (int i = 0; i < deltaLen; i++)	//补0
	{
		add1 = "0" + add1;
	}
	/*进行加法运算*/
	string result;
	bool carry = false;	//进位
	for (int i = (int)max(add1.length(), add2.length()) - 1; i >= 0; i--)
	{
		int a = add1[i] - '0';	//字符转为数字
		int b = add2[i] - '0';
		int sum = a + b + carry;

		if (sum >= 10)
		{
			carry = true;
			sum -= 10;
		}
		else
		{
			carry = false;
		}

		result += (sum + '0');
	}
	if (carry == true)	//最高位的进位
	{
		result += "1";
	}
	reverse(result.begin(), result.end());	//反转字符串
	return result;
}

/// <summary>
/// 高精度乘法
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

int main()
{
	int n;
	string a;
	while (cin >> n >> a)
	{
		string result = "0";
		for (int i = 1; i <= n; i++)
		{
			string powerResult = "1";
			for (int j = 0; j < i; j++)
			{
				powerResult = highPrecisionMutil(powerResult, a);
			}
			powerResult = highPrecisionMutil(powerResult, to_string(i));
			result = highPrecisionAdd(result, powerResult);
		}
		cout << result << endl;
	}
	return 0;
}