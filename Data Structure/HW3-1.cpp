//2021/10/26
#include <iostream>
#include <queue>
using namespace std;
#pragma region BiTreeNode
template<typename T>
class BiTreeNode
{
public:
	void create(BiTreeNode<T>** root);
	void print(BiTreeNode<T>* root, int level = 0);
	void preOrderTraverse(BiTreeNode<T>* root, void(*fun)(BiTreeNode<T>*));
	void inOrderTraverse(BiTreeNode<T>* root, void(*fun)(BiTreeNode<T>*));
	void postOrderTraverse(BiTreeNode<T>* root, void(*fun)(BiTreeNode<T>*));
	void levelOrderTraverse(BiTreeNode<T>* root, void(*fun)(BiTreeNode<T>*));
	T getData();
private:
	T data;
	BiTreeNode* leftChild;
	BiTreeNode* rightChild;
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

/// <summary>
/// Print tree in level. Rotate 90°CCW.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root">Pointer to root</param>
/// <param name="level">Level of the node, use default value</param>
template<typename T>
void BiTreeNode<T>::print(BiTreeNode<T>* node, int level)
{
	if (node->rightChild != NULL)
	{
		node->rightChild->print(node->rightChild, level + 1);	//Print right child first.
	}
	for (int i = 0; i < level; i++)
	{
		cout << "     ";
	}
	cout << node->data << endl;
	if (node->leftChild != NULL)
	{
		node->leftChild->print(node->leftChild, level + 1);
	}
}

/// <summary>
/// Traversing binary tree in preorder.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root">Pointer to root</param>
/// <param name="fun">what to do</param>
template<typename T>
void BiTreeNode<T>::preOrderTraverse(BiTreeNode<T>* node, void(*fun)(BiTreeNode<T>*))
{
	if (node == NULL)
	{
		return;
	}
	fun(node);	//Do something
	preOrderTraverse(node->leftChild, fun);
	preOrderTraverse(node->rightChild, fun);
}

/// <summary>
/// Traversing binary tree in order.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="node">Pointer to root</param>
/// <param name="fun">what to do</param>
template<typename T>
void BiTreeNode<T>::inOrderTraverse(BiTreeNode<T>* node, void(*fun)(BiTreeNode<T>*))
{
	if (node == NULL)
	{
		return;
	}
	inOrderTraverse(node->leftChild, fun);
	fun(node);	//Do something
	inOrderTraverse(node->rightChild, fun);
}

/// <summary>
/// Traversing binary tree in postorder.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="node">Pointer to root</param>
/// <param name="fun">what to do</param>
template<typename T>
void BiTreeNode<T>::postOrderTraverse(BiTreeNode<T>* node, void(*fun)(BiTreeNode<T>*))
{
	if (node == NULL)
	{
		return;
	}
	postOrderTraverse(node->leftChild, fun);
	postOrderTraverse(node->rightChild, fun);
	fun(node);	//Do something
}

/// <summary>
/// Traversing binary tree in level order.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root">Pointer to root</param>
/// <param name="fun">what to do</param>
template<typename T>
void BiTreeNode<T>::levelOrderTraverse(BiTreeNode<T>* root, void(*fun)(BiTreeNode<T>*))
{
	queue<BiTreeNode*> q;
	/* Use queue to save nodes which to be search. The same as BFS. */
	if (root != NULL)
	{
		q.push(root);
	}
	while (!q.empty())
	{
		fun(q.front());	//Traverse front node.
		if (q.front()->leftChild != NULL)
		{
			q.push(q.front()->leftChild);
		}
		if (q.front()->rightChild != NULL)
		{
			q.push(q.front()->rightChild);
		}
		q.pop();
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

/// <summary>
/// Do something to the node.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="node"></param>
template<typename T>
void functionForBiTreeNode(BiTreeNode<T>* node)
{
	cout << node->getData();
}

int main()
{
	int n;
	tree->create(&tree);

	tree->preOrderTraverse(tree, functionForBiTreeNode<char>);
	cout << endl;

	tree->inOrderTraverse(tree, functionForBiTreeNode<char>);
	cout << endl;

	tree->postOrderTraverse(tree, functionForBiTreeNode<char>);
	cout << endl;

	tree->levelOrderTraverse(tree, functionForBiTreeNode<char>);
	cout << endl;

	tree->print(tree);
	return 0;
}