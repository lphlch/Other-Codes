//2021/10/30

#include <iostream>
#include <vector>
#include <string>

#define LINK  0	//child
#define THRE  1	//node
using namespace std;

string result;//save the result of the sequence

struct Relate
{
	int succTag;
	int prevTag;
	bool isKey;
};

vector < Relate >  relates;

template<typename T>
class BiTreeNode
{
public:
	void create(BiTreeNode<T>** root);
	void thre(BiTreeNode<T>* root);
	void search(BiTreeNode<T>* root, char& name, vector < Relate >& relates);
	T getData();
private:
	T data;
	BiTreeNode* leftChild = NULL;
	BiTreeNode* rightChild = NULL;
	int leftTag = LINK;
	int rightTag = LINK;
};


/// <summary>
/// Create a binary tree in preorder.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root">Pointer to pointer to root</param>
template<typename T>
void BiTreeNode<T>::create(BiTreeNode<T>** node)
{
	/*
	Use pointer to pointer.
	Because the change of pointer to root will simply change the pointer to another address
	instead of to root,	not to change the data of root.
	*/
	T c;
	cin >> c;
	if (c == '#')
	{
		*node = NULL;
		return;
	}
	else
	{
		*node = new(BiTreeNode<char>);
		(*node)->data = c;	//Traverse to create new node.
		(*node)->create(&((*node)->leftChild));
		(*node)->create(&((*node)->rightChild));
	}
}

BiTreeNode<char>* preNode = new(BiTreeNode<char>);

/// <summary>
/// threing
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="node">Pointer to root</param>
template<typename T>
void BiTreeNode<T>::thre(BiTreeNode<T>* node)
{
	if (node == NULL)
	{
		return;
	}
	thre(node->leftChild);

	if (node->leftChild == NULL)
	{
		node->leftTag = THRE;
		node->leftChild = preNode;
	}
	else
	{
		node->leftTag = LINK;
	}

	if (/*preNode != NULL && */preNode->rightChild == NULL)
	{
		preNode->rightTag = THRE;
		preNode->rightChild = node;
	}
	else
	{
		preNode->rightTag = LINK;
	}
	preNode = node;

	thre(node->rightChild);
}


/// <summary>
/// InOrder traverse and save the predecessor and successor
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root"></param>
/// <param name="name">name of the key node</param>
/// <param name="relates">Save the tag of nodes</param>
template<typename T>
void BiTreeNode<T>::search(BiTreeNode<T>* root, char& name, vector < Relate >& relates)
{
	BiTreeNode<T>* nextNode = root;
	Relate relate;

	while (nextNode != NULL)
	{
		while (nextNode->leftTag == LINK)	//Reach the left bottom
		{
			nextNode = nextNode->leftChild;
		}

		result = result + nextNode->getData();
		if (!nextNode->rightChild)		//Only tag be saved. Beacuse the predecessor or successor is not equal to the child point at
		{
			relate.succTag = THRE;
		}
		else
		{
			relate.succTag = nextNode->rightTag;
		}
		if (!nextNode->leftChild)
		{
			relate.prevTag = THRE;
		}
		else
		{
			relate.prevTag = nextNode->leftTag;
		}
		relate.isKey = (nextNode->data == name ? true : false);
		relates.push_back(relate);

		while (nextNode->rightTag == THRE && nextNode->rightChild != NULL)	//If right child is not child, move to the thre
		{
			nextNode = nextNode->rightChild;	//Enter right thre

			result = result + nextNode->getData();
			if (!nextNode->rightChild)		//Only tag be saved. Beacuse the predecessor or successor is not equal to the child point at
			{
				relate.succTag = THRE;
			}
			else
			{
				relate.succTag = nextNode->rightTag;
			}
			if (!nextNode->leftChild)
			{
				relate.prevTag = THRE;
			}
			else
			{
				relate.prevTag = nextNode->leftTag;
			}
			relate.isKey = (nextNode->data == name ? true : false);
			relates.push_back(relate);
		}

		nextNode = nextNode->rightChild;	//Enter right child
	}
}

/// <summary>
/// Return data
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template<typename T>
T BiTreeNode<T>::getData()
{
	return this->data;
}

BiTreeNode<char>* tree = new(BiTreeNode<char>);

int main()
{
	tree->create(&tree);
	tree->thre(tree);
	char key;
	cin >> key;
	tree->search(tree, key, relates);
	long long c = 0;
	cout << result << endl;

	for (long long i=0;i<relates.size();i++)
	{
		if (relates[i].isKey == true)
		{
			c++;
			if (i + 1 >= result.size() /*|| relates[i+1].succTag == END*/)
			{
				cout << "succ is NULL" << endl;
			}
			else
			{
				cout << "succ is " << result[i+1] << relates[i+1].succTag << endl;
			}
			if (i - 1 < 0/* ||relates[i-1].prevTag == END*/)
			{
				cout << "prev is NULL" << endl;
			}
			else
			{
				cout << "prev is " << result[i - 1] << relates[i - 1].prevTag << endl;
			}
		}
	}
	if (c == 0)
	{
		cout << "Not found" << endl;
	}
}
