//@date: 2021/12/11
//@author: LPH
//@description:4

#include <algorithm>
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	int time[10] = {1, 2, 5, 10, 12, 23, 43, 50, 120, 122};
	int n;
	cin >> n;
	int sum = 0;
	while (n > 0)
	{
		/* code */

		if (n == 1)
		{
			sum += time[0];
			break;
		}
		else if (n == 2)
		{
			sum += time[1];
			break;
		}
		else if (n == 3)
		{
			sum += time[2] + time[1] + time[0];
			break;
		}
		else
		{
			sum = (time[n - 2] + time[0] <= 2 * time[1]) ? (sum+time[n - 1] + time[n - 2] + 2 * time[0]) : (sum+time[n - 1] + time[0] + 2 * time[1]);
			n = n - 2;
		}
	}
	cout << sum;
}
