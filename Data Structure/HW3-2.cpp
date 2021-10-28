#include <iostream>
#include <queue>

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
bool isChecked[MAXSIZE];
int depthTemp[MAXSIZE];

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
	//DFS
	//queue<int> q;
	//int levelNow = 0;
	//depthTemp[i] = 1;
	//q.push(i);
	//while (!q.empty())
	//{
	//	levelNow = depthTemp[q.front()];
	//	if (nodes[q.front()].leftChild != MAXSIZE)
	//	{
	//		if (isChecked[nodes[q.front()].leftChild])
	//		{
	//			// End of this branch.
	//			// The depth of the branch equal to this level + depth of the node.
	//			if (levelNow + depthTemp[nodes[q.front()].leftChild] > depthMax)
	//			{
	//				depthMax = levelNow + depthTemp[nodes[q.front()].leftChild];
	//			}
	//		}
	//		else
	//		{
	//			q.push(nodes[q.front()].leftChild);
	//			depthTemp[nodes[q.front()].leftChild] = levelNow + 1;
	//			if (depthMax < levelNow + 1)
	//			{
	//				depthMax = levelNow + 1;
	//			}
	//		}
	//	}

	//	if (nodes[q.front()].rightChild != MAXSIZE)
	//	{
	//		if (isChecked[nodes[q.front()].rightChild])
	//		{
	//			if (levelNow + depthTemp[nodes[q.front()].rightChild] > depthMax)
	//			{
	//				depthMax = levelNow + depthTemp[nodes[q.front()].rightChild];
	//			}
	//		}
	//		else
	//		{
	//			q.push(nodes[q.front()].rightChild);
	//			depthTemp[nodes[q.front()].rightChild] = levelNow + 1;
	//		}
	//	}

	//	isChecked[q.front()] = true;
	//	q.pop();
	//}
	//depthTemp[i] = depthMax;	//Assign depth to the root.
}

bool checkChild(BiTreeNode nodes1[], int nodeCount1, BiTreeNode nodes2[], int nodeCount2)
{
	for (int i = 0; i < nodeCount1; i++)
	{
		for (int j = 0; j < nodeCount2; j++)
		{
			if (nodes1[i].name == nodes2[j].name)
			{
				if (nodes1[nodes1[i].leftChild].name != nodes2[nodes2[j].leftChild].name &&
					nodes1[nodes1[i].rightChild].name != nodes2[nodes2[j].leftChild].name
					)
				{
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
	while (true)
	{
		cin >> biTreeNodes1[nodeCount1].name;
		//Check the input, if is #, point to MAXSIZE.
		cin >> biTreeNodes1[nodeCount1].leftChild;
		if (cin.fail())
		{
			cin.clear();
			getchar();
			biTreeNodes1[nodeCount1].leftChild = MAXSIZE;
		}
		cin >> biTreeNodes1[nodeCount1].rightChild;
		if (cin.fail())
		{
			cin.clear();
			getchar();
			biTreeNodes1[nodeCount1].rightChild = MAXSIZE;
		}
	}

	int nodeCount2 = 0;
	cin >> nodeCount2;
	while (true)
	{
		cin >> biTreeNodes2[nodeCount2].name;
		//Check the input, if is #, point to MAXSIZE.
		cin >> biTreeNodes2[nodeCount2].leftChild;
		if (cin.fail())
		{
			cin.clear();
			getchar();
			biTreeNodes2[nodeCount2].leftChild = MAXSIZE;
		}
		cin >> biTreeNodes2[nodeCount2].rightChild;
		if (cin.fail())
		{
			cin.clear();
			getchar();
			biTreeNodes2[nodeCount2].rightChild = MAXSIZE;
		}
	}

	if (nodeCount1 != nodeCount2 || !checkChild(biTreeNodes1, nodeCount1, biTreeNodes2, nodeCount2))
	{
		cout << "No" << endl;
	}
	else
	{
		cout << "Yes" << endl;
	}

	return 0;
}