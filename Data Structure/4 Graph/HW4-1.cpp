//@date: 2021/11/10
//@author: LPH
//@description: HW4-1 Structure of graph.

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#pragma region DIRECTED_GRAPH
class DirectedGraph
{
protected:
	vector<vector<int>> matrix;	//save the graph matrix
	vector<char> vertex;	//save the vertex
	int vertexNum;
	int edgeNum;

public:
	void create();
	void printMatrix();
	void printTable();
	int findVertex(char c);
};

/// <summary>
/// create the graph
/// </summary>
void DirectedGraph::create()
{
	cin >> vertexNum >> edgeNum;
	for (int i = 0; i < vertexNum; i++)
	{
		char temp;
		cin >> temp;
		vertex.push_back(temp);
	}
	matrix.resize(vertexNum);
	for (int i = 0; i < vertexNum; i++)
	{
		matrix[i].resize(vertexNum);
	}
	char a, b;
	int indexA, indexB;
	for (int i = 0; i < edgeNum; i++)
	{
		cin >> a >> b;
		indexA = findVertex(a);
		indexB = findVertex(b); //find the index of a and b
		matrix[indexA][indexB] = 1;	//set the matrix
	}
}

/// <summary>
/// print the matrix
/// </summary>
void DirectedGraph::printMatrix()
{
	for (int i = 0; i < vertexNum; i++)
	{
		cout << vertex[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
		{
			//width 4 for each element
			cout << setw(4) << matrix[i][j];
		}
		cout << endl;
	}
}

/// <summary>
/// print the table
/// </summary>
void DirectedGraph::printTable()
{
	for (int i = 0; i < vertexNum; i++)
	{
		cout << vertex[i] << "-->";
		for (int j = vertexNum - 1; j >= 0; j--)
		{
			if (matrix[i][j] != 0)
				cout << j << " ";
		}
		cout << endl;
	}
}

/// <summary>
/// find the index of a vertex
/// </summary>
/// <param name="c"> vertex name </param>
/// <returns> index </returns>
int DirectedGraph::findVertex(char c)
{
	for (int i = 0; i < vertexNum; i++)
	{
		if (vertex[i] == c)
			return i;
	}
	return -1;
}

#pragma endregion

#pragma region DIRECTED_NETWORK
//inherit from DirectedGraph
class DirectedNetwork :public DirectedGraph
{
public:
	void create();	//override the create function for adding weight
	void printTable();
};

void DirectedNetwork::create()
{
	cin >> vertexNum >> edgeNum;
	for (int i = 0; i < vertexNum; i++)
	{
		char temp;
		cin >> temp;
		vertex.push_back(temp);
	}
	matrix.resize(vertexNum);
	for (int i = 0; i < vertexNum; i++)
	{
		matrix[i].resize(vertexNum);
	}
	char a, b;
	int weight;
	int indexA, indexB;
	for (int i = 0; i < edgeNum; i++)
	{
		cin >> a >> b >> weight;
		indexA = findVertex(a);
		indexB = findVertex(b); //find the index of a and b
		matrix[indexA][indexB] = weight;	//set the matrix
	}
}

void DirectedNetwork::printTable()
{
	for (int i = 0; i < vertexNum; i++)
	{
		cout << vertex[i] << "-->";
		for (int j = vertexNum - 1; j >= 0; j--)
		{
			if (matrix[i][j] != 0)
				cout << j << ',' << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

#pragma endregion

#pragma region UNDIRECTED_GRAPH
//inherit from DirectedGraph
class UndirectedGraph :public DirectedGraph
{
public:
	void create();
};

void UndirectedGraph::create()
{
	cin >> vertexNum >> edgeNum;
	for (int i = 0; i < vertexNum; i++)
	{
		char temp;
		cin >> temp;
		vertex.push_back(temp);
	}
	matrix.resize(vertexNum);
	for (int i = 0; i < vertexNum; i++)
	{
		matrix[i].resize(vertexNum);
	}
	char a, b;
	int indexA, indexB;
	for (int i = 0; i < edgeNum; i++)
	{
		cin >> a >> b;
		indexA = findVertex(a);
		indexB = findVertex(b); //find the index of a and b
		matrix[indexA][indexB] = 1;	//set the matrix
		matrix[indexB][indexA] = 1;	//symmetric matrix
	}
}

#pragma endregion

#pragma region UNDIRECTED_NETWORK
//inherit from DirectedNetwork
class UndirectedNetwork :public DirectedNetwork
{
public:
	void create();
};

void UndirectedNetwork::create()
{
	cin >> vertexNum >> edgeNum;
	for (int i = 0; i < vertexNum; i++)
	{
		char temp;
		cin >> temp;
		vertex.push_back(temp);
	}
	matrix.resize(vertexNum);
	for (int i = 0; i < vertexNum; i++)
	{
		matrix[i].resize(vertexNum);
	}
	char a, b;
	int weight;
	int indexA, indexB;
	for (int i = 0; i < edgeNum; i++)
	{
		cin >> a >> b >> weight;
		indexA = findVertex(a);
		indexB = findVertex(b); //find the index of a and b
		matrix[indexA][indexB] = weight;	//set the matrix
		matrix[indexB][indexA] = weight;	//symmetric matrix
	}
}

#pragma endregion

int main()
{
	int type;
	cin >> type;
	switch (type)
	{
		case 1:
		{
			DirectedGraph dGraph;
			dGraph.create();
			dGraph.printMatrix();
			dGraph.printTable();
			break;
		}
		case 2:
		{
			DirectedNetwork dNetwork;
			dNetwork.create();
			dNetwork.printMatrix();
			dNetwork.printTable();
			break;
		}
		case 3:
		{
			UndirectedGraph uGraph;
			uGraph.create();
			uGraph.printMatrix();
			uGraph.printTable();
			break;
		}
		case 4:
		{
			UndirectedNetwork uNetwork;
			uNetwork.create();
			uNetwork.printMatrix();
			uNetwork.printTable();
			break;
		}
		default:
			break;
	}
	return 0;
}