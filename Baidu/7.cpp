//@date: 2021/12/11
//@author: LPH
//@description:7

#include <algorithm>
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
long long a[10000], b[10000];
bool fa[10000], fb[10000];
/* int comb(int n, int m)
{
	if (m == 0 || m == n)
		return 1;
	if (m == 1)
		return n;
	return comb(n - 1, m - 1) + comb(n - 1, m);
} */

int main()
{
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	sort(a, a + n);
	sort(b, b + n);
	int ans = 0;

	while (next_permutation(a, a + n))
	{
		//while (next_permutation(b, b + n))
		//{
			/*memset(fa, 0, sizeof(fa));
			memset(fb, 0, sizeof(fb));
			int count = 0;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < i; j++)
				{
					if (fa[i] || fb[i])
					{
						continue;
					}
					if (a[i] > b[j])
					{
						count++;
						fa[i] = true;
						fb[j] = true;
					}
				}
			}*/
			int count = 0;
			for (int i = 0; i < n; i++)
			{
				if (a[i] > b[i])
				{
					count++;
				}
			}
			if (count == k)
			{
				ans++;
			}
		//}
	}
	cout << ans;
	return 0;
}

/*
4 3
1 6 3 8
7 4 2 5
*/