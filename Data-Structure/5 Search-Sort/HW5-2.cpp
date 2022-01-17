//@date: 2021/12/7
//@author: LPH
//@description: HW5-2 Binary Sort Tree

#include <iostream>
#include <vector>
using namespace std;
#define INTMAX 2147483647

/// <summary>
/// Binary Sort Tree
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T>
class BST
{
public:
	void insert(BST<T> **root, T data);	// insert data into BST
	void searchAndDelete(BST<T> **root, T key);	// search and delete data from BST
	bool search(BST<T> *root, T key);	// judge whether the data is in BST
	void deleteNode(BST<T> **root, T key);	// delete a node from BST
	BST<T> *&getMin(BST<T> **root);	// get the minimum node of BST
	int countNumber(BST<T> *root, T key);	// count the number of data in BST
	T getPreData(BST<T> *root, T key, T preKey);	// get the predecessor data of data
	void inOrderTraverse(BST<T> *root);	// in-order traverse BST, for debug
	T getData();

private:
	T data;
	int count;
	BST *leftChild = NULL;
	BST *rightChild = NULL;
};

/// <summary>
/// insert data into BST
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root">address of pointer to root</param>
/// <param name="data">data to be inserted</param>
template <typename T>
void BST<T>::insert(BST<T> **root, T data)
{
	//use pointer to pointer to change the address of root
	if (*root == NULL)
	{
		*root = new (BST<T>);
		(*root)->data = data; // Traverse to create new node.
		(*root)->leftChild = NULL;
		(*root)->rightChild = NULL;
		(*root)->count = 1;
	}
	else
	{
		if (data < (*root)->data)
		{
			insert(&((*root)->leftChild), data);
		}
		else if (data > (*root)->data)
		{
			insert(&((*root)->rightChild), data);
		}
		else
		{
			(*root)->count++;
		}
	}
}

/// <summary>
/// find and delete data from BST
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root">address of pointer to root</param>
/// <param name="key">data to be deleted</param>
template <typename T>
void BST<T>::searchAndDelete(BST<T> **root, T key)
{
	if (*root == NULL)
	{
		cout << "None" << endl;
		return;
	}
	else
	{
		if (key < (*root)->data)
		{
			searchAndDelete(&(*root)->leftChild, key);
		}
		else if (key > (*root)->data)
		{
			searchAndDelete(&(*root)->rightChild, key);
		}
		else
		{
			deleteNode(&(*root), key);
		}
	}
}

/// <summary>
/// find data that whether in BST or not
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root">pointer to root</param>
/// <param name="key">data to be found</param>
/// <returns>true if in tree</returns>
template <typename T>
bool BST<T>::search(BST<T> *root, T key)
{
	if (root == NULL)
	{
		return false;
	}
	else
	{
		if (key < root->data)
		{
			search(root->leftChild, key);
		}
		else if (key > root->data)
		{
			search(root->rightChild, key);
		}
		else
		{
			return true;
		}
	}
}

/// <summary>
/// delete a node from BST
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root">address of pointer to node which needs to be deleted</param>
/// <param name="key">data to be deleted</param>
template <typename T>
void BST<T>::deleteNode(BST<T> **root, T key)
{
	if (*root == NULL)
	{
		cout << "None" << endl;
		return;
	}
	else
	{
		if ((*root)->count > 1) // if found, delete one
		{
			(*root)->count--;
		}
		else // if only one
		{
			if ((*root)->leftChild == NULL && (*root)->rightChild == NULL) // if is leaf
			{
				(*root) = NULL;
			}
			else if ((*root)->leftChild == NULL) // if only have left child, let the subtree taking the position
			{
				BST<T> *temp = *root;
				(*root) = temp->rightChild;
				delete temp;
			}
			else if ((*root)->rightChild == NULL)
			{
				BST<T> *temp = *root;
				(*root) = temp->leftChild;
				delete temp;
			}
			else
			{
				// find the min node in right subtree
				BST<T> *&min = (getMin(&(*root)->rightChild));
				(*root)->data = (min)->data; // replace the (*root) with the min node
				(*root)->count = (min)->count;
				deleteNode(&(min), (min)->data); // delete the min node
			}
		}
	}
}

/// <summary>
/// get the min node in BST
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root">address of pointer to subtree root</param>
/// <returns>reference to pointer to min node of BST</returns>
template <typename T>
BST<T> *&BST<T>::getMin(BST<T> **root)
{
	if ((*root)->leftChild == NULL)
	{
		return (*root);
	}
	else
	{
		return getMin(&(*root)->leftChild);
	}
}

/// <summary>
/// count the number of data in BST
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root">pointer to root</param>
/// <param name="key">data to be counted</param>
/// <returns>count</returns>
template <typename T>
int BST<T>::countNumber(BST<T> *root, T key)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		if (key < root->data)
		{
			return countNumber(root->leftChild, key);
		}
		else if (key > root->data)
		{
			return countNumber(root->rightChild, key);
		}
		else
		{
			return root->count;
		}
	}
}

/// <summary>
/// get direct predecessor of a data
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root">pointer to root</param>
/// <param name="key">data to be found a predecessor</param>
/// <param name="preKey">temp predecessor used in recursion</param>
/// <returns>predecessor value of the data</returns>
template <typename T>
T BST<T>::getPreData(BST<T> *root, T key, T preKey)
{
	if (root == NULL)
	{
		return INTMAX;
	}
	if (root->data > key)
	{
		if (root->leftChild == NULL) // if no left child, return the preKey
		{
			return preKey;
		}
		else
		{
			return getPreData(root->leftChild, key, preKey);
		}
	}
	else if (root->data < key)
	{
		if (root->rightChild == NULL) // if can not find bigger one, this is the pre
		{
			return root->data;
		}
		preKey = root->data; // save the preKey
		return getPreData(root->rightChild, key, preKey);
	}
	else
	{
		if (preKey == INTMAX) // if found the key but no preKey
		{
			if (root->leftChild == NULL) // no pre node
			{
				return INTMAX;
			}
			else // have pre node, get the smallest data
			{
				BST<T> *preNode = root->leftChild;
				while (preNode->rightChild != NULL)
				{
					preNode = preNode->rightChild;
				}
				return preNode->data;
			}
		}
		else if (root->leftChild != NULL) // if found the key and have preKey, but have left child that obviously smaller than preKey
		{
			BST<T> *preNode = root->leftChild;
			while (preNode->rightChild != NULL)
			{
				preNode = preNode->rightChild;
			}
			return preNode->data;
		}
		else
		{
			return preKey;
		}
	}
}

/// <summary>
/// print inorder sequence of BST. For debug
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root">pointer to root</param>
template <typename T>
void BST<T>::inOrderTraverse(BST<T> *root)
{
	if (root == NULL)
	{
		return;
	}

	inOrderTraverse(root->leftChild);
	cout << root->data << '(' << root->count << ") ";
	inOrderTraverse(root->rightChild);
}

/// <summary>
/// return a data of BST node
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns>node data</returns>
template <typename T>
T BST<T>::getData()
{
	return data;
}

int main()
{
	BST<int> *root = NULL;
	int orderNum;
	int order;
	cin >> orderNum;
	while (orderNum > 0)
	{
		orderNum--;
		int data;
		cin >> order;

		switch (order)
		{
		case 1:
			cin >> data;
			root->insert(&root, data);
			break;
		case 2:
			cin >> data;
			root->searchAndDelete(&root, data);
			break;
		case 3:
			cin >> data;
			cout << root->countNumber(root, data) << endl;
			break;
		case 4:
			cout << (root->getMin(&root))->getData() << endl;
			break;
		case 5:
		{
			cin >> data;
			int preData = root->getPreData(root, data, INTMAX);
			if (preData == INTMAX)
			{
				cout << "None" << endl;
			}
			else
			{
				cout << preData << endl;
			}
		}
		break;
		case 6:
			root->inOrderTraverse(root);
			break;
		default:
			break;
		}
	}
	// root->print(root, 0);
	return 0;
}
