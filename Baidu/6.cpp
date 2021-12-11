//@date: 2021/12/11
//@author: LPH
//@description:6

#include <algorithm>
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << 1;
		return 0;
	}

	long long result;
	//divide n to 3 2
	int a = n / 3;
	int b = n % 3;
	if (b == 0)
	{
		result = (long long)(pow(3, a));
		cout << result;
		return 0;
	}
	if (b == 1)
	{
		result = (long long)(pow(3, a - 1)) * 2 * 2;
		cout << result;
		return 0;
	}
	if (b == 2)
	{
		result =(long long)(pow(3, a)) * 2;
		cout << result;
		return 0;
	}

}