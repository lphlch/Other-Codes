//@date: 2021/12/7
//@author: LPH
//@description: HW5-2 Binary Sort Tree

#include <iostream>
#include <vector>
using namespace std;
#define INT_MAX 2147483647
template <typename T>
class BST
{
public:
	void insert(BST<T> **root, T data);
	void searchAndDelete(BST<T> **root, T key);
	bool search(BST<T> *root, T key);
	void deleteNode(BST<T> **root, T key);
	BST<T> *getMin(BST<T> *root);
	int countNumber(BST<T> *root, T key);
	T getPreData(BST<T> *root, T key, T preKey);
	void print(BST<T> *root, int level = 0);
	void inOrderTraverse(BST<T> *root, T key);
	void inOrderTraverse(BST<T> *root);
	T getData();

private:
	T data;
	int count;
	BST *leftChild = NULL;
	BST *rightChild = NULL;
};

template <typename T>
void BST<T>::insert(BST<T> **root, T data)
{

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

template<typename T>
bool BST<T>::search(BST<T>* root, T key)
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
				BST<T> *min = getMin((*root)->rightChild);
				(*root)->data = min->data; // replace the (*root) with the min node
				(*root)->count = min->count;
				deleteNode(&min, min->data); // delete the min node
			}
		}
	}
}

template <typename T>
BST<T> *BST<T>::getMin(BST<T> *root)
{
	if (root->leftChild == NULL)
	{
		return root;
	}
	else
	{
		return getMin(root->leftChild);
	}
}

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

template <typename T>
T BST<T>::getPreData(BST<T> *root, T key, T preKey)
{
	if (root == NULL)
	{
		return INT_MAX;
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
		if (preKey == INT_MAX) // if found the key but no preKey
		{
			if (root->leftChild == NULL) // no pre node
			{
				return INT_MAX;
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

template <typename T>
void BST<T>::print(BST<T> *root, int level)
{
	// print BST in preorder
	if (root == NULL)
	{
		return;
	}
	for (int i = 0; i < level; i++)
	{
		cout << "    ";
	}
	cout << root->data << "(" << root->count << ")" << endl;
	print(root->leftChild, level + 1);
	print(root->rightChild, level + 1);
}

vector<int> dataOrder;
template <typename T>
void BST<T>::inOrderTraverse(BST<T> *root, T key)
{
	if (root == NULL)
	{
		return;
	}

	inOrderTraverse(root->leftChild, key);
	if (root->data > key)
	{
		return;
	}
	dataOrder.push_back(root->data);
	inOrderTraverse(root->rightChild, key);
}

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
			cout << (root->getMin(root))->getData() << endl;
			break;
		case 5:
		{
			cin >> data;
			int preData = root->getPreData(root, data, INT_MAX);
			if (preData == INT_MAX)
			{
				cout << "None" << endl;
			}
			else
			{
				cout << preData << endl;
			}

			/* 	dataOrder.clear();
				root->inOrderTraverse(root, data);
				for (int i = 0; i < dataOrder.size(); i++)
				{
					if (dataOrder[i] >= data)
					{
						if (i == 0)
						{
							cout << "None";
						}
						else
						{
							cout << dataOrder[i - 1] << endl;
						}
						break;
					}
				}
				if(data>dataOrder[dataOrder.size()-1])
				{
					cout << dataOrder[dataOrder.size()-1]<< endl;
				}*/
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
