//@date: 2021/12/11
//@author: LPH
//@description:1

#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string a;
	cin >> a;
	reverse(a.begin(), a.end());
	cout << a;
	return 0;
}
