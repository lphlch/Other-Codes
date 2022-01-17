//2021/10/30

#include <iostream>
using namespace std;

int n;	//Save number of nodes.

#pragma region BiTreeNode
template<typename T>
class BiTreeNode
{
public:
	void create(BiTreeNode<T>** root);
	void postOrderTraverse(BiTreeNode<T>* root, void(*fun)(BiTreeNode<T>*));
	T getData();
private:
	T data;
	BiTreeNode* leftChild;
	BiTreeNode* rightChild;
};

/// <summary>
/// Create a binary tree.In fact it is preorder.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="root">Pointer to pointer to root</param>
template<typename T>
void BiTreeNode<T>::create(BiTreeNode<T>** node)
{
	string order;
	char nodeName;
	if (n <= 0)
	{
		*node = NULL;
		return;
	}

	cin >> order;
	if (order == "push")
	{
		cin >> nodeName;
		*node = new(BiTreeNode<char>);
		(*node)->data = nodeName;	//Traverse to create new node.
		n--;
		//cout <<"now"<< n;
		(*node)->create(&((*node)->leftChild));
		(*node)->create(&((*node)->rightChild));
	}
	else if (order == "pop")
	{
		*node = NULL;
		return;
	}
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
	cin >> n;
	tree->create(&tree);
	tree->postOrderTraverse(tree, functionForBiTreeNode);
	return 0;
}