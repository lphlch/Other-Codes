//@date: 2021/12/14
//@author: LPH
//@description: HW5-5 Inverse Pair

#include <iostream>
#include <cstring>
using namespace std;
int num[20000];
int temp[20000];

// Time limit exceeded
// int count(int n)
//{
//	int count = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i; j < n; j++)
//		{
//			if (num[i] > num[j])
//			{
//				count++;
//			}
//		}
//	}
//	return count;
//}

void print(int n, int k)
{
	cout << "num:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << num[i] << " ";
	}
	cout << endl;
	cout << "temp:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << temp[i] << " ";
	}
	cout << endl;
	cout << "k: " << k << endl;
}

/// <summary>
/// merge two sections. Left section: [leftBound..midBound-1]. Right section: [midBound..rightBound-1]
/// </summary>
/// <param name="leftBound"></param>
/// <param name="midBound"></param>
/// <param name="rightBound"></param>
/// <param name="src">source array</param>
/// <param name="dst">destination array</param>
/// <returns>number of inverse pair</returns>
int merge(const int leftBound, const int midBound, const int rightBound, int src[], int dst[])
{
	int inversePair = 0;
	int leftIndex = leftBound; // left bound, left start
	int mid = midBound;		   // mid bound, right start
	int rightIndex = midBound;
	int count = 0; // count the number of elements in the section
	while (leftIndex < mid && rightIndex <= rightBound)
	{
		if (src[leftIndex] <= src[rightIndex])
		{
			dst[leftBound + count] = src[leftIndex];
			leftIndex++;
		}
		else
		{
			dst[leftBound + count] = src[rightIndex];
			rightIndex++;
			inversePair += mid - leftIndex; // count the inverse pair
		}
		count++;
	}

	// merge left section
	while (leftIndex < mid)
	{
		dst[leftBound + count] = src[leftIndex];
		count++;
		leftIndex++;
	}
	while (rightIndex <= rightBound)
	{
		dst[leftBound + count] = src[rightIndex];
		count++;
		rightIndex++;
		inversePair += mid - leftIndex;
	}
	return inversePair;
}

/// <summary>
/// sort & merge sections for length of n
/// </summary>
/// <param name="length">length of each section</param>
/// <param name="n">length of numbers</param>
/// <param name="src">source array</param>
/// <param name="dst">destination array</param>
/// <returns>number of inverse pair</returns>
int mergeSection(const int length, const int n, int src[], int dst[])
{
	int inversePair = 0;
	int i = 0;
	for (; i < n - length + 1; i = i + length)
	{
		inversePair = inversePair + merge(i, i + length / 2, i + length - 1, src, dst);
	}

	// merge the last section
	if (i < n - length / 2)
	{
		inversePair = inversePair + merge(i, i + length / 2, n - 1, src, dst);  //if can be divided into 2 sections, one has enough length
	}
	else    //if can not be divided
	{
		for (int j = i; j < n; j++)
		{
			dst[j] = src[j];
		}
	}
	return inversePair;
}

/// <summary>
/// count inverse pair by merge sort
/// </summary>
/// <param name="n">length of numbers</param>
/// <returns>number of inverse pair</returns>
int mergeSortCount(const int n)
{
	int k = 1; // size of each section
	int inversePair = 0;
	while (k < n) // if there is n/2, the remaining sequences that cannot be divisible are not sorted
	{
		k *= 2; // double the size of each section
		// sort each section
		inversePair = inversePair + mergeSection(k, n, num, temp);
		//print(n, k);

		k *= 2;
		inversePair = inversePair + mergeSection(k, n, temp, num);
		//print(n, k);
	}
	return inversePair;
}

int main()
{
	int n;
	cin >> n;
	while (n != 0)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> num[i];
		}
		cout << mergeSortCount(n) << endl;
		memset(num, 0, sizeof(num));
		memset(temp, 0, sizeof(temp));
		cin >> n;
	}
	return 0;
}