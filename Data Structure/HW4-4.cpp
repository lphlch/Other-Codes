//@date: 2021/11/18
//@author: LPH
//@description: HW4-4 The shortest path

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#pragma region DIRECTED_GRAPH
class DirectedGraph
{
protected:
	vector< vector< int > > matrix; //save the graph matrix
	int vertexNum;
	int edgeNum;

public:
	void create();
};

/// <summary>
/// create the graph
/// </summary>
void DirectedGraph::create()
{
	cin >> vertexNum >> edgeNum;
	matrix.resize(vertexNum);
	for (int i = 0; i < vertexNum; i++)
	{
		matrix[i].resize(vertexNum);
	}
	int a, b;
	for (int i = 0; i < edgeNum; i++)
	{
		cin >> a >> b;
		matrix[a][b] = 1; //set the matrix
	}
}

#pragma endregion

#pragma region UNDIRECTED_NETWORK
//inherit from DirectedGraph
class UndirectedNetwork : public DirectedGraph
{
public:
	void create();
	void allShortestPath(vector <int> & path, vector <int> & shortestPath);
	int startVertex;
};

void UndirectedNetwork::create()
{
	cin >> vertexNum >> edgeNum >> startVertex;
	startVertex--;
	matrix.resize(vertexNum);
	for (int i = 0; i < vertexNum; i++)
	{
		matrix[i].resize(vertexNum);
	}
	int a, b;
	int weight;
	for (int i = 0; i < edgeNum; i++)
	{
		cin >> a >> b >> weight;
		matrix[a - 1][b - 1] = weight; //set the matrix
		matrix[b - 1][a - 1] = weight; //symmetric matrix
	}
}

/// <summary>
/// Get all shortest path by Dijkstra algorithm
/// </summary>
/// <param name="path"></param>
/// <param name="shortestPath"></param>
void UndirectedNetwork::allShortestPath(vector <int> & path, vector <int> & shortestPath)
{
	int start = startVertex;
	vector<bool> isFindShortestPath(vertexNum, false);
	shortestPath.resize(vertexNum, 0);
	path.clear();
	path.resize(vertexNum);
	for (int i = 0; i < vertexNum; i++)
	{
		shortestPath[i] = matrix[start][i]; //initialize the shortestPath of start
		if (shortestPath[i] != 0)			//if the start vertex is connected to the i vertex
		{
			path[i] = start; //set the path of start vertex to i vertex
		}
		else
		{
			path[i] = -1; //if the start vertex is not connected to the i vertex
		}
	}
	isFindShortestPath[start] = true;

	for (int i = 1; i < vertexNum; i++)
	{
		int minPath = INT_MAX;
		for (int j = 0; j < vertexNum; j++) //get the minPath, record the vertex
		{
			if (!isFindShortestPath[j] && shortestPath[j] < minPath)
			{
				minPath = shortestPath[j];
				start = j;
			}
		}
		isFindShortestPath[start] = true;

		for (int j = 0; j < vertexNum; j++) //update the shortest path
		{
			//if there is no connection between the last added vertex, making it reachable
			//if there is a shorter path to a vertex which alrea_dy have way, make it as the shortest
			if (!isFindShortestPath[j] && matrix[start][j] != 0 && shortestPath[start] + matrix[start][j] < shortestPath[j])
			{
				shortestPath[j] = shortestPath[start] + matrix[start][j];
				path[j] = start;	//update the path
			}
		}
	}
}
#pragma endregion

int main()
{
	vector<int> path;	//save the previous vertex of the way that to the start vertex
	vector<int> shortestPath;	//save the shortest path from the start vertex to the other vertex
	UndirectedNetwork un;
	un.create();
	un.allShortestPath(path, shortestPath);

	for (int i = 0; i < path.size(); i++)
	{
		if (un.startVertex != i && path[i] == -1)
		{
			cout << INT_MAX << " ";
		}
		else
		{
			cout << shortestPath[i] << " ";
		}
	}

	return 0;
}