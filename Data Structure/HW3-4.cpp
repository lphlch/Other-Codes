//2021/10/30

#include <iostream>
#include <vector>
#include <string>

#define LINK  1	//child
#define THRE  0	//node
#define END  9
using namespace std;

string result;//save the result of the sequence

#pragma region BiTreeNode
struct Relate
{
	int succTag;
	int prevTag;
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
		if (nextNode->data == name)
		{
			if (!nextNode->rightChild)		//Only tag be saved. Beacuse the predecessor or successor is not equal to the child point at
			{
				relate.succTag = END;
			}
			else
			{
				relate.succTag = nextNode->rightTag;
			}
			if (!nextNode->leftChild)
			{
				relate.prevTag = END;
			}
			else
			{
				relate.prevTag = nextNode->leftTag;
			}
			relates.push_back(relate);
		}

		while (nextNode->rightTag == THRE && nextNode->rightChild != NULL)	//If right child is not child, move to the thre
		{
			nextNode = nextNode->rightChild;	//Enter right thre

			result = result + nextNode->getData();
			if (nextNode->data == name)
			{
				if (!nextNode->rightChild)
				{
					relate.succTag = END;
				}
				else
				{
					relate.succTag = nextNode->rightTag;
				}
				if (!nextNode->leftChild)
				{
					relate.prevTag = END;
				}
				else
				{
					relate.prevTag = nextNode->leftTag;
				}
				relates.push_back(relate);
			}
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
#pragma endregion

BiTreeNode<char>* tree = new(BiTreeNode<char>);

int main()
{
	vector < Relate > relates;
	tree->create(&tree);
	tree->thre(tree);
	char key;
	cin >> key;
	tree->search(tree, key, relates);
	long long pos = 0;
	cout << result << endl;
	if (relates.size() == 0)
	{
		cout << "Not found" << endl;
	}
	for (Relate relate : relates)
	{
		for (long long i = pos; i < result.length(); i++)
		{
			if (result[i] == key)
			{
				pos = i + 1;
				break;
			}
		}
		if (relate.succTag == END || pos > result.length())
		{
			cout << "succ is NULL" << endl;
		}
		else
		{
			cout << "succ is " << result[pos] << relate.succTag << endl;
		}
		if (relate.prevTag == END || pos - 2 < 0)
		{
			cout << "prev is NULL" << endl;
		}
		else
		{
			cout << "prev is " << result[pos - 2] << relate.prevTag << endl;
		}
	}
}
