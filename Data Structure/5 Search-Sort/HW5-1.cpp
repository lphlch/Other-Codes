//@date: 2021/12/8
//@author: LPH
//@description: HW5-1 Binary Search

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/// <summary>
/// Binary Search Plus
/// </summary>
/// <param name="nums"> numbers array</param>
/// <param name="key"> key </param>
/// <param name="isLower"> if true, return the min index of key, else return the max index of key</param>
/// <returns>index of key, min or max</returns>
int binarySearch(vector<int> &nums, int key, bool isLower)
{
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (isLower)
		{
			if (nums[mid] < key)    //difference between isLower and isHigher is that the '='
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
			if (nums[left] == key && left == right + 1) //condition of found
			{
				return left;
			}
		}
		else
		{
			if (nums[mid] <= key)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
			if (nums[right] == key && left == right + 1)
			{
				return right;
			}
		}
	}
	return -1;
}

int main()
{
	vector<int> datas;
	int n;
	cin >> n;
	datas.reserve(n);

	int data;
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		datas.push_back(data);
	}

	string order;
	cin >> order;
	int key;
	while (order != "done")
	{
		cin >> key;
		if (order == "lower")
		{
			cout << binarySearch(datas, key, true) << endl;
		}
		else
		{
			cout << binarySearch(datas, key, false) << endl;
		}
		cin >> order;
	}

	return 0;
}
