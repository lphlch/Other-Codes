//@date: 2021/11/18
//@author: LPH
//@description: HW4-4 The shortest path

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <queue>

const int INTMAX = 2147483647;
using namespace std;

struct Edge
{
	int vertexId;
	int weight;
};

int findEdge(vector<vector<Edge>>& table, int start, int end)
{
	for (int i = 0; i < table[start].size(); i++)
	{
		if (table[start][i].vertexId == end)
		{
			return i;
		}
	}
	return -1;
}

time_t searchMinTime = 0;
time_t updateTime = 0;
time_t createTime = 0;
time_t tmpTime;

class UndirectedNetwork
{
public:
	vector<vector<Edge>> table;
	int vertexNum;
	int edgeNum;
	int startVertex;
	void create();
	void allShortestPath(vector<int>& path, vector<int>& shortestPath);
};

/// <summary>
/// create undirected network, and store in table
/// </summary>
void UndirectedNetwork::create()
{
	cin >> vertexNum >> edgeNum >> startVertex;
	table.resize(vertexNum);
	int a, b;
	int weight;
	int tmpEdgeIndexA;
	int tmpEdgeIndexB;
	for (int i = 0; i < edgeNum; i++)
	{
		cin >> a >> b >> weight;
		int indexA = a - 1;
		int indexB = b - 1;
		tmpEdgeIndexA = findEdge(table, indexA, indexB);
		if (tmpEdgeIndexA == -1)
		{
			table[indexA].push_back({ indexB, weight });
			table[indexB].push_back({ indexA, weight });
		}
		else if (table[indexA][tmpEdgeIndexA].weight > weight)
		{
			table[indexA][tmpEdgeIndexA].weight = weight;
			tmpEdgeIndexB = findEdge(table, indexB, indexA);
			table[indexB][tmpEdgeIndexB].weight = weight;
		}
	}
}

/// <summary>
/// Get all shortest path by Dijkstra algorithm, priority queue boosted
/// </summary>
/// <param name="path"> path of shortest way </param>
/// <param name="shortestPath"> distance of path </param>
void UndirectedNetwork::allShortestPath(vector<int>& path, vector<int>& shortestPath)
{
	int start = startVertex - 1;
	vector<bool> isFindShortestPath(vertexNum, false);
	shortestPath.resize(vertexNum, INTMAX);
	path.clear();
	path.resize(vertexNum);
	int tmpEdgeIndex = -1;
	for (int i = 0; i < vertexNum; i++)
	{
		tmpEdgeIndex = findEdge(table, start, i);

		if (shortestPath[i] != INTMAX) //if the start vertex is connected to the i vertex
		{
			path[i] = start; //set the path of start vertex to i vertex
		}
		else
		{
			path[i] = -1; //if the start vertex is not connected to the i vertex
		}
	}
	shortestPath[start] = 0;

	priority_queue<pair<int, int>> pQ;
	pQ.push({INTMAX, start });
	tmpTime = clock();
	while (!pQ.empty())
	{
		int tmpVertex = pQ.top().second;	//get the vertex with the smallest distance
		pQ.pop();
		if (isFindShortestPath[tmpVertex])	//if the tmpVertex has been found
		{
			continue;
		}
		isFindShortestPath[tmpVertex] = true;


		for (int i = 0; i < table[tmpVertex].size(); i++)
		{
			int j = table[tmpVertex][i].vertexId;
			if (!isFindShortestPath[j] && shortestPath[tmpVertex] + table[tmpVertex][i].weight < shortestPath[j])	//update the shortest path
			{
				shortestPath[j] = shortestPath[tmpVertex] + table[tmpVertex][i].weight;
				path[j] = tmpVertex; //update the path
				pQ.push({ -shortestPath[j], j });
			}
		}
	}
	updateTime += clock() - tmpTime;
	//cerr << "Search time: " << searchMinTime << "ms" << endl;
	cerr << "Update time: " << updateTime << "ms" << endl;
}

int main()
{
	vector<int> path;		  //save the previous vertex of the way that to the start vertex
	vector<int> shortestPath; //save the shortest path from the start vertex to the other vertex
	UndirectedNetwork un;
	createTime = clock();
	un.create();
	cerr << "Create time: " << clock() - createTime << "ms" << endl;
	un.allShortestPath(path, shortestPath);
	for (int i = 0; i < path.size(); i++)
	{
		if (un.startVertex - 1 != i && path[i] == -1)
		{
			cout << INTMAX << " ";
		}
		else
		{
			cout << shortestPath[i] << " ";
		}
	}
	if (0)
	{
		cout << endl;
		for (int i = 0; i < path.size(); i++)
		{
			cout << path[i] + 1 << ' ';
		}
	}
	return 0;
}