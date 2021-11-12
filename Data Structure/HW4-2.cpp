//@date: 2021/11/12
//@author: LPH
//@description: HW4-2 Traversing graph in BFS and DFS

#include <iostream>
#include <vector>
#include <iomanip>
#include <stack>
#include <queue>
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
	void dfsPrint();
	void bfsPrint();
};

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

/// <summary>
/// print the graph by dfs
/// </summary>
void DirectedGraph::dfsPrint()
{
	stack<int> s;
	vector<int> result;
	vector<bool> visited(vertexNum, false);
	for (int i = 0; i < vertexNum; i++)
	{
		if (!visited[i])
		{
			s.push(i);
			while (!s.empty())
			{
				int v = s.top();
				s.pop();
				if (!visited[v])
				{
					visited[v] = true;
					result.push_back(v);
					for (int j = vertexNum - 1; j >= 0; j--)
					{
						if (matrix[v][j] != 0 && !visited[j])
							s.push(j);
					}
				}
			}
			cout << '{';
			for (int i = 0; i < result.size() - 1; i++)
			{
				cout << result[i] << " ";
			}
			cout << result[result.size() - 1] << '}';
			result.clear();
		}
	}
	cout << endl;
}

/// <summary>
/// print the graph by bfs
/// </summary>
void DirectedGraph::bfsPrint()
{
	queue<int> q;
	vector<int> result;
	vector<bool> visited(vertexNum, false);
	for (int i = 0; i < vertexNum; i++)
	{
		if (!visited[i])
		{
			q.push(i);
			while (!q.empty())
			{
				int v = q.front();
				q.pop();
				if (!visited[v])
				{
					visited[v] = true;
					result.push_back(v);
					for (int j = 0; j < vertexNum; j++)
					{
						if (matrix[v][j] != 0 && !visited[j])
							q.push(j);
					}
				}
			}
			cout << '{';
			for (int i = 0; i < result.size() - 1; i++)
			{
				cout << result[i] << " ";
			}
			cout << result[result.size() - 1] << '}';
			result.clear();
		}
	}
	cout << endl;
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
	vertex.resize(vertexNum);
	matrix.resize(vertexNum);
	for (int i = 0; i < vertexNum; i++)
	{
		matrix[i].resize(vertexNum);
	}
	int indexA, indexB;
	for (int i = 0; i < edgeNum; i++)
	{
		cin >> indexA >> indexB;
		matrix[indexA][indexB] = 1;	//set the matrix
		matrix[indexB][indexA] = 1;	//symmetric matrix
	}
}

#pragma endregion

int main()
{
	UndirectedGraph ug;
	ug.create();
	//ug.printMatrix();
	ug.dfsPrint();
	ug.bfsPrint();
	return 0;
}