//@date: 2021/12/11
//@author: LPH
//@description:2

#include <algorithm>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int xa, xb, ya, yb;
	cin>>xa>>ya>>xb>>yb;
	cout<<fixed<<setprecision(3)<<sqrt(pow(xa-xb,2)+pow(ya-yb,2))<<endl;
}
