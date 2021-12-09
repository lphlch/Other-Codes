//@date: 2021/12/9
//@author: LPH
//@description: HW5-3 Hash Table

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> nameHashTable;	// name hash table

/// <summary>
/// get the min prime larger than n
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
int getPrime(int n)
{
	vector<bool> prime(n * 2+1, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i < n; i++)
	{
		for (int j = 2; j * i < n * 2; j++)
		{
			prime[i * j] = false;
		}
	}
	for (int i = n; i < n * 2+1; i++)
	{
		if (prime[i])
		{
			return i;
		}
	}
	return -1;
}

/// <summary>
/// quadratic probing
/// </summary>
/// <param name="key">confict index</param>
/// <param name="maxSearch">max search time, default length of hash table</param>
/// <returns>new index, if not exist ,return -1</returns>
int quadraticProbing(int key, int maxSearch)
{
	int maxOffset=maxSearch/2+1;
	int count = 0;
	if (key < 0)
	{
		return false;
	}
	for (int i = 0; i < maxOffset; i++)
	{
		if (nameHashTable[(key + i * i) % nameHashTable.size()] == "" && (++count)<=maxSearch)
		{
			return (key + i * i) % nameHashTable.size();
		}
		else if (nameHashTable[(key - (i * i) % nameHashTable.size() + nameHashTable.size()) % nameHashTable.size()] == "" && (++count)<=maxSearch)	// take care of negative index
		{
			return (key -( i * i) % nameHashTable.size()+ nameHashTable.size()) % nameHashTable.size();
		}
	}
	return -1;
}

/// <summary>
/// Hash mapping
/// </summary>
/// <param name="name">key to be mapped</param>
/// <param name="lengthOfHashTable">hash table length</param>
/// <returns>index of hash table</returns>
int transform(string name, int lengthOfHashTable)
{
	int n = name.length();
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = sum * 37 + name[i];
		sum = sum % lengthOfHashTable;
	}

	return quadraticProbing(sum, lengthOfHashTable);
}

int main()
{
	int keyNum, hashTableLength;
	cin >> keyNum >> hashTableLength;
	hashTableLength = getPrime(hashTableLength);
	nameHashTable.resize(hashTableLength);

	string name;
	for (int i = 0; i < keyNum; i++)
	{
		cin >> name;
		int index = transform(name, hashTableLength);
		if (index != -1)
		{
			nameHashTable[index] = name;
			cout << index << ' ';
		}
		else
		{
			cout << "- ";
		}
	}
	return 0;
}