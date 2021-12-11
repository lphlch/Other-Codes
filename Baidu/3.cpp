//@date: 2021/12/11
//@author: LPH
//@description:3

#include <algorithm>
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

long long factorial(int n)
{
	long long result = 1;
	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}
	return result;
}

int main()
{
	int n;
	cin>>n;
	if(n<0)
	{
		cout << 0 <<endl;
		return 0;
	}
	//cout n!
	cout<<factorial(n)<<endl;
}
