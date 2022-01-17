//2021/9/19

#include <iostream>
using namespace std;
const int MAXSIZE = 20005;
int la[MAXSIZE] = { 0 };
int main()
{
	int count = -1;
	/* 一次性输入la和lb */
	do
	{
		count++;
		cin >> la[count];
	} while (la[count] != 0);
	count--;
	do
	{
		count++;
		cin >> la[count];
	} while (la[count] != 0);
	count--;

	/* 一起进行冒泡排序 */
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count - i; j++)
		{
			if (la[j] > la[j + 1])
			{
				int tmp; //临时变量
				tmp = la[j]; //交换
				la[j] = la[j + 1];
				la[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < count + 1; i++)
	{
		cout << la[i] << ' ';
	}
	cout << endl;

	return 0;
}