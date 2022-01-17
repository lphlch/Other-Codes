//2021/11/7
// for Time complexity, m as string length, n as character set length
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX_SIZE = 256;

struct Node
{
	int leftChild = -1;
	int rightChild = -1;
	int parent = -1;
} tree[MAX_SIZE];

// save the huffman code of each character
string coder[MAX_SIZE];

#pragma region HUFFMAN_TREE_BUILD

/// <summary>
/// count every char in the string. Time complexity: O(m)
/// </summary>
/// <param name="str"></param>
/// <param name="count">result array</param>
void countCharacter(string& str, int count[])
{
	int i, j;
	for (i = 0; i < MAX_SIZE; i++)
	{
		count[i] = 0;
	}
	for (i = 0; i < str.length(); i++)
	{
		count[str[i]]++;
	}
}

/// <summary>
/// find two char which has the least frequency. Time complexity: O(n)
/// </summary>
/// <param name="count"> count array </param>
/// <param name="min1"></param>
/// <param name="min2"></param>
/// <returns> if there is two min char </returns>
bool findTwoMin(int count[], int& min1, int& min2)
{
	int i;
	min1 = min2 = -1;
	//find the first min
	for (i = 0; i < MAX_SIZE; i++)
	{
		if (count[i] != 0)
		{
			if (min1 == -1)
			{
				min1 = i;
			}
			else
			{
				if (count[min1] > count[i])
				{
					min1 = i;
				}
			}
		}
	}
	//find the second min
	for (i = 0; i < MAX_SIZE; i++)
	{
		if (count[i] != 0 && i != min1)
		{
			if (min2 == -1)
			{
				min2 = i;
			}
			else
			{
				if (count[min2] > count[i])
				{
					min2 = i;
				}
			}
		}
	}

	if (min1 == -1 || min2 == -1)
	{
		return false;
	}

	//make sure smallest char is in the left child
	if (min1 > min2)
		swap(min1, min2);
	return true;
}

/// <summary>
/// build huffman tree. Time complexity: O(n^2)
/// </summary>
/// <param name="count"></param>
/// <returns> position of root </returns>
int buildHuffmanTree(int count[])
{
	int i, min1, min2, newNodePos = MAX_SIZE / 2 + 1;
	while (findTwoMin(count, min1, min2))
	{
		//add new node in newNodePos
		count[newNodePos] = count[min1] + count[min2];
		//delete min1 and min2
		count[min1] = count[min2] = 0;

		//let new node leftChild as min1, rightChild as min2
		tree[newNodePos].leftChild = min1;
		tree[min1].parent = newNodePos;
		tree[newNodePos].rightChild = min2;
		tree[min2].parent = newNodePos;

		newNodePos++;
	}
	return newNodePos - 1;
}

#pragma endregion

#pragma region ENCODING

/// <summary>
/// get huffman code of one char. Time complexity: O(logn)
/// </summary>
/// <param name="c"> char </param>
/// <param name="tree"></param>
/// <param name="root"></param>
/// <param name="result"> huffmancode of the char </param>
void encodeChar(int c, Node tree[], int root, string& result)
{
	int pos = c;
	if (tree[pos].parent == -1 && pos != root)
	{
		result = "";
		return;
	}
	while (tree[pos].parent != -1)
	{
		if (tree[tree[pos].parent].leftChild == pos)
		{
			result += "0";
		}
		else
		{
			result += "1";
		}
		pos = tree[pos].parent;
	}
	reverse(result.begin(), result.end());
}

/// <summary>
/// get the huffman code of each char. Time complexity: O(m*logn)
/// </summary>
/// <param name="coder"> huffmancode array </param>
/// <param name="root"></param>
void encodeEveryChar(string coder[], int root)
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		encodeChar(i, tree, root, coder[i]);
	}
}

#pragma endregion

#pragma region PRINT
/// <summary>
/// print times of each char. Time complexity: O(n)
/// </summary>
/// <param name="count"> count array </param>
void printCount(int count[])
{
	int i;
	for (i = 0; i < MAX_SIZE; i++)
	{
		if (count[i] != 0)
		{
			cout << (char)i << ":" << count[i] << endl;
		}
	}
}

/// <summary>
/// print huffman tree. Time complexity: O(n)
/// </summary>
/// <param name="tree"></param>
/// <param name="root"></param>
void printHuffmanTreeInArray(Node tree[], int root)
{
	int i;
	for (i = 0; i < MAX_SIZE; i++)
	{
		if (tree[i].leftChild != -1)
		{
			cout << "Node " << i << ": " << tree[i].leftChild << "( " << (char)tree[i].leftChild << " ) " << tree[i].rightChild << "( " << (char)tree[i].rightChild << " ) Pa: " << tree[i].parent << endl;
		}
	}
	cout << "Root " << root << endl;
}

/// <summary>
/// print huffman code of each char. Time complexity: O(n)
/// </summary>
/// <param name="count"> code array </param>
void printHuffmanCode(string coder[])
{
	for (int i = 0; i < MAX_SIZE / 2; i++)
	{
		if (coder[i].length() != 0)
		{
			cout << i << (char)i << " :" << coder[i] << endl;
		}
	}
}
#pragma endregion

#pragma region COMPRESS_DECOMPRESS

/// <summary>
/// compress string. Time complexity: O(m)
/// </summary>
/// <param name="str"> orinal string </param>
/// <returns> compressed bitstream </returns>
string compress(string str)
{
	string result;
	for (int i = 0; i < str.length(); i++)
	{
		result = result + coder[str[i]];
	}
	return result;
}

/// <summary>
/// decompress bitstream. Time complexity: O(m)
/// </summary>
/// <param name="bitStream"> bitStream </param>
/// <param name="root"> root position of the huffman code tree </param>
/// <returns></returns>
string decompress(string bitStream, int root)
{
	string result;
	int i = 0;
	int nodePos;	//current node position
	while (i < bitStream.length())
	{
		int nodePos = root;
		while (nodePos >= MAX_SIZE / 2)	//Represents get the orginal char
		{
			if (bitStream[i] == '0')
			{
				nodePos = tree[nodePos].leftChild;
			}
			else
			{
				nodePos = tree[nodePos].rightChild;
			}
			i++;
		}
		result += (char)nodePos;
	}
	return result;
}

#pragma endregion

int main()
{
	//input a string
	cout << "Please input a string:" << endl;
	string str;
	cin >> str;

	//count the number of each character
	int count[256];
	countCharacter(str, count);
	//print the number of each character
	cout << endl << "Times of each character:" << endl;
	printCount(count);

	//build huffman tree
	int root;
	root = buildHuffmanTree(count);
	encodeEveryChar(coder, root);

	//print huffman tree
	cout << endl << "Realation of each node:" << endl;
	printHuffmanTreeInArray(tree, root);
	cout << endl << "Huffman code:" << endl;
	printHuffmanCode(coder);

	cout << endl << "Orignal string:" << endl;
	cout << str << endl;
	cout << "Size: " << str.length() * 8 << "bits" << endl;

	//compress and print
	string result;
	result = compress(str);
	cout << endl << "Compressed string:" << endl;
	cout << result << endl;
	cout << "Size: " << result.length() << "bits" << endl;
	cout << "Compression rate: " << (double)result.length() / (str.length() * 8) * 100 << '%' << endl;

	//decompress and print
	string orignalStr;
	orignalStr = decompress(result, root);
	cout << endl << "Decompressed string:" << endl;
	cout << "Check for consistency: " << boolalpha << (orignalStr == str) << endl;

	return 0;
}