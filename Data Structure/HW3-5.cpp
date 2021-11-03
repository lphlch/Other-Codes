#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <map>

using namespace std;

time_t start = clock();
time_t now = start;
time_t createTime = start;
time_t searchTime = start;
time_t checkTime = start;

#pragma region BiTreeNode
template <typename T>
class BiTreeNode
{
public:
	void create(BiTreeNode<T>** root, int n);
	void checkRelation(BiTreeNode<T>* root, T mem1, T mem2, string relation);
	void printPreOrder(BiTreeNode<T>* node, int level);
	T getData();

private:
	T data;
	BiTreeNode* leftChild = NULL;
	BiTreeNode* rightChild = NULL;
	BiTreeNode* parent = NULL; //save the parent node
	int level;				   //save the level of the node
};

//use map to save node pointer
map<string, BiTreeNode<string>*> nodeMap;

/// <summary>
/// create a binary tree in the form of a complete binary tree
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root">the root of the binary tree</param>
/// <param name="n">the number of nodes in the binary tree</param>
template <typename T>
void BiTreeNode<T>::create(BiTreeNode<T>** root, int n)
{
	*root = new (BiTreeNode<T>);

	int preLevel = 0; //save the former blanks
	int level = 0;	  //save now blanks

	BiTreeNode<T>* preNode = *root;
	n--;

	string str;
	cin >> str;
	cin.get();
	(*root)->data = str;
	nodeMap.insert(pair<T, BiTreeNode<T>*>(str, (*root)));
	(*root)->level = level;
	BiTreeNode<T>* node;

	while (n > 0)
	{
		node = new (BiTreeNode<T>);
		getline(cin, str);

		//get the whole line, count blank before level the node.
		level = str.find_first_not_of(' ', 0);
		//str.erase(0, level);
		node->data = str.substr(level, str.length() - level);
		nodeMap.insert(pair<T, BiTreeNode<T>*>(node->data, node));
		if (level > preLevel)
		{
			//the people is a child of pre people, making it as left child
			preNode->leftChild = node;
			node->parent = preNode;
		}
		else if (level == preLevel)
		{
			//sibling, as right child
			preNode->rightChild = node;
			node->parent = preNode->parent;
		}
		else
		{
			//other ancestor, as its parent's sibling get the level equal to it and making it as right child
			while (preNode->parent != NULL && preNode->parent->level != level)
			{
				preNode = preNode->parent;
			}
			preNode->parent->rightChild = node;
			node->parent = preNode->parent->parent;
		}

		//let the node be the preNode, and the level be the preLevel
		node->level = level;
		preNode = node;
		preLevel = level;
		n--;
	}
}

/// <summary>
/// check if realtion between two members is true
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root">the root of the binary tree</param>
/// <param name="mem1">first member</param>
/// <param name="mem2">second member</param>
/// <param name="relation">relation between two members</param>
template <typename T>
void BiTreeNode<T>::checkRelation(BiTreeNode<T>* root, T mem1, T mem2, string relation)
{
	//search the key in the binary tree first
	BiTreeNode<T>* node1 = NULL;
	BiTreeNode<T>* node2 = NULL;
	now = clock();
	//find the mem1 in nodeMap and get the second
	if (nodeMap.find(mem1) != nodeMap.end())
	{
		node1 = nodeMap.find(mem1)->second;
	}
	else
	{
		cout << "The member " << mem1 << " is not in the tree." << endl;
		return;
	}
	//find the mem2 in nodeMap and get the second
	if (nodeMap.find(mem2) != nodeMap.end())
	{
		node2 = nodeMap.find(mem2)->second;
	}
	else
	{
		cout << "The member " << mem2 << " is not in the tree." << endl;
		return;
	}

	searchTime += clock() - now;
	now = clock();
	if (node1 == NULL || node2 == NULL)
	{
		cerr << "No such member" << endl;
		return;
	}

	if (relation == "parent")
	{
		if (node2->parent == node1)
		{
			cout << "True" << endl;
		}
		else
		{
			cout << "False" << endl;
		}
	}
	else if (relation == "sibling")
	{
		//if is sibling, the parent must be the same
		if (node1->parent == node2->parent)
		{
			cout << "True" << endl;
		}
		else
		{
			cout << "False" << endl;
		}
	}
	else if (relation == "child")
	{
		//if is child, the mem2 must be the parent of mem1
		if (node1->parent == node2)
		{
			cout << "True" << endl;
		}
		else
		{
			cout << "False" << endl;
		}
	}
	else if (relation == "ancestor")
	{
		//if it is ancestor, the mem1 must be the parent of mem2
		if (node2 == node1)
		{
			cout << "True" << endl;
			return;
		}
		if (node2->parent == NULL)
		{
			cout << "False" << endl;
		}
		else
		{
			while (node2->parent != node1)
			{
				node2 = node2->parent;
				if (node2 == NULL)
				{
					cout << "False" << endl;
					return;
				}
			}
			cout << "True" << endl;
		}
	}
	else if (relation == "descendant")
	{
		//if it is descendant, the mem2 must be the parent of mem1
		if (node2 == node1)
		{
			cout << "True" << endl;
			return;
		}
		if (node1->parent == NULL)
		{
			cout << "False" << endl;
		}
		else
		{
			while (node1->parent != node2)
			{
				node1 = node1->parent;
				if (node1 == NULL)
				{
					cout << "False" << endl;
					return;
				}
			}
			cout << "True" << endl;
		}
	}
	else
	{
		cerr << "No such relation" << endl;
	}
}

/// <summary>
/// print the binary tree in preorder
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="node"></param>
/// <param name="level"> blanks before the node</param>
template <typename T>
void BiTreeNode<T>::printPreOrder(BiTreeNode<T>* node, int level)
{
	if (node == NULL)
	{
		return;
	}
	for (int i = 0; i < level; i++)
	{
		cout << " ";
	}
	cout << node->getData() << "     parent: " << (node->parent ? node->parent->data : "NULL") << endl;
	printPreOrder(node->leftChild, level + 1);
	printPreOrder(node->rightChild, level);
}

template <typename T>
T BiTreeNode<T>::getData()
{
	return data;
}

#pragma endregion

/// <summary>
/// split the string into a array of string
/// </summary>
/// <param name="result">vector of the string split</param>
/// <param name="str">string which will be split</param>
/// <param name="delim">delimiter</param>
void splitString(vector<string>& result, string str, char delim)
{
	result.clear();
	for (int i = 0; i < str.length(); i++)
	{
		int pos = (int)str.find(delim, i);
		if (pos != -1)
		{
			string subStr = str.substr(i, pos - i);
			if (subStr != "")
			{
				result.push_back(subStr);
			}
			i = pos;
		}
		else
		{
			string subStr = str.substr(i, str.length() - 1);
			if (subStr[0] != delim)
			{
				result.push_back(subStr);
			}
			break;
		}
	}
}

BiTreeNode<string>* tree = new (BiTreeNode<string>);

int main()
{
	int n;
	int m;
	cin >> n >> m;
	string key;

	while (n != 0)
	{
		now = clock();

		tree->create(&tree, n);
		createTime += clock() - now;
		//tree->printPreOrder(tree, 0);
		vector<string> keySplit(6, "");
		//cerr the time cost

		while (m != 0)
		{
			keySplit.clear();
			getline(cin, key);
			splitString(keySplit, key, ' '); //split the string into a array of string
											 //the keySplit[0] is the first member
											 //the keySplit[3] is the relation
											 //the keySplit[5] is the second member
			tree->checkRelation(tree, keySplit[0], keySplit[5].substr(0, 9), keySplit[3]);
			checkTime += clock() - now;
			m--;
		}
		cout << endl;
		nodeMap.clear();
		cin >> n >> m; //reinput
	}
	cerr << "Time cost in create: " << (createTime - start) / (double)CLOCKS_PER_SEC << "s" << endl;
	cerr << "Time cost in search: " << (searchTime - start) / (double)CLOCKS_PER_SEC << "s" << endl;
	cerr << "Time cost in check: " << (checkTime - start) / (double)CLOCKS_PER_SEC << "s" << endl;
}