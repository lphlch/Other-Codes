//2021/10/26

#include <iostream>
using namespace std;

#pragma region BiTreeNode
template<typename T>
class BiTreeNode
{
public:
	void create(BiTreeNode<T>** root);
	void clear(BiTreeNode<T>* root);
	void preOrderTraverse(BiTreeNode<T>* root, void(*fun)(BiTreeNode<T>*));
	void inOrderTraverse(BiTreeNode<T>* root, void(*fun)(BiTreeNode<T>*));
	void postOrderTraverse(BiTreeNode<T>* root, void(*fun)(BiTreeNode<T>*));
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
	preOrderTraverse(node->leftChild, fun);
	fun(node);	//Do something
	preOrderTraverse(node->rightChild, fun);
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
	preOrderTraverse(node->leftChild, fun);
	preOrderTraverse(node->rightChild, fun);
	fun(node);	//Do something
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
/// Do something in the node.
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

	return 0;
}