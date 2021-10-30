#include <iostream>
#include <cstring>

using namespace std;
const int MAXSIZE = 100050;
struct BiTreeNode
{
	char name;
	int leftChild;
	int rightChild;
};
BiTreeNode biTreeNodes1[MAXSIZE];
BiTreeNode biTreeNodes2[MAXSIZE];
bool isChecked[MAXSIZE];	//DFS flag
int depthTemp[MAXSIZE];		//Temporary depth

/// <summary>
/// DFS get depth of the node
/// </summary>
/// <param name="nodes">Tree the node belong to</param>
/// <param name="pos">Position of the node</param>
/// <returns>Depth of the node</returns>
int getDepth(BiTreeNode nodes[], int pos)
{
	if (isChecked[pos])
	{
		return depthTemp[pos];
	}

	isChecked[pos] = true;
	int lDepth = 0, rDepth = 0;
	if (nodes[pos].leftChild != MAXSIZE)
	{
		lDepth = getDepth(nodes, nodes[pos].leftChild);
	}
	if (nodes[pos].rightChild != MAXSIZE)
	{
		rDepth = getDepth(nodes, nodes[pos].rightChild);
	}
	depthTemp[pos] = max(lDepth, rDepth) + 1;
	return depthTemp[pos];
}

/// <summary>
/// DFS get max depth of a tree
/// </summary>
/// <param name="nodes">Tree</param>
/// <param name="nodeCount">How many nodes of the tree</param>
/// <returns>Max depth</returns>
int getMaxDepth(BiTreeNode nodes[], int nodeCount)
{
	int maxDepth = 0;
	int tempDepth;
	for (int i = 0; i < nodeCount; i++)
	{
		tempDepth = getDepth(nodes, i);
		maxDepth = max(maxDepth, tempDepth);
	}
	return maxDepth;
}

/// <summary>
/// Check if two trees have the same child
/// </summary>
/// <param name="nodes1">Tree1</param>
/// <param name="nodeCount1">How many nodes of tree1</param>
/// <param name="nodes2">Tree2</param>
/// <param name="nodeCount2">How many nodes of tree2</param>
/// <returns></returns>
bool checkChild(BiTreeNode nodes1[], int nodeCount1, BiTreeNode nodes2[], int nodeCount2)
{
	for (int i = 0; i < nodeCount1; i++)
	{
		for (int j = i; j < nodeCount2; j++)
		{
			if (nodes1[i].name == nodes2[j].name)
			{
				if (nodes1[nodes1[i].leftChild].name == nodes2[nodes2[j].leftChild].name &&
					nodes1[nodes1[i].rightChild].name == nodes2[nodes2[j].rightChild].name)

				{
					;
				}
				else if (nodes1[nodes1[i].rightChild].name == nodes2[nodes2[j].leftChild].name &&
					nodes1[nodes1[i].leftChild].name == nodes2[nodes2[j].rightChild].name)
				{
					;
				}
				else
				{
					/*cerr << nodes1[i].name << ' ' << nodes1[nodes1[i].leftChild].name << ' ' << nodes1[nodes1[i].rightChild].name <<
						' ' << nodes2[j].name << ' ' << nodes2[nodes2[j].leftChild].name << ' ' << nodes2[nodes2[j].rightChild].name << endl;*/
					return false;
				}
				break;
			}
		}
	}
	return true;
}

int main()
{
	int nodeCount1 = 0;
	cin >> nodeCount1;
	for (int i = 0; i < nodeCount1; i++)
	{
		cin >> biTreeNodes1[i].name;
		//Check the input, if is #, point to MAXSIZE.
		cin >> biTreeNodes1[i].leftChild;
		if (cin.fail())
		{
			cin.clear();
			getchar();
			biTreeNodes1[i].leftChild = MAXSIZE;
		}
		cin >> biTreeNodes1[i].rightChild;
		if (cin.fail())
		{
			cin.clear();
			getchar();
			biTreeNodes1[i].rightChild = MAXSIZE;
		}
	}

	int nodeCount2 = 0;
	cin >> nodeCount2;
	for (int i = 0; i < nodeCount2; i++)
	{
		cin >> biTreeNodes2[i].name;
		//Check the input, if is #, point to MAXSIZE.
		cin >> biTreeNodes2[i].leftChild;
		if (cin.fail())
		{
			cin.clear();
			getchar();
			biTreeNodes2[i].leftChild = MAXSIZE;
		}
		cin >> biTreeNodes2[i].rightChild;
		if (cin.fail())
		{
			cin.clear();
			getchar();
			biTreeNodes2[i].rightChild = MAXSIZE;
		}
	}

	if (nodeCount1 != nodeCount2)
	{
		cout << "No" << endl;
	}
	else if (checkChild(biTreeNodes1, nodeCount1, biTreeNodes2, nodeCount2))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	cout << getMaxDepth(biTreeNodes1, nodeCount1) << endl;
	memset(isChecked, false, sizeof(isChecked));	//Reset
	memset(depthTemp, false, sizeof(depthTemp));
	cout << getMaxDepth(biTreeNodes2, nodeCount2) << endl;

	return 0;
}