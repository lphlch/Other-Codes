//@date: 2021/11/18
//@author: LPH
//@description: HW4-4 The shortest path

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
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

void UndirectedNetwork::create()
{
	cin >> vertexNum >> edgeNum >> startVertex;
	table.resize(vertexNum);
	int a, b;
	int weight;
	int tmpEdgeIndex;
	for (int i = 0; i < edgeNum; i++)
	{
		cin >> a >> b >> weight;
		int indexA = a - 1;
		int indexB = b - 1;
		tmpEdgeIndex = findEdge(table, indexA, indexB);
		if (tmpEdgeIndex == -1)
		{
			table[indexA].push_back({ indexB, weight });
			//table[indexB].push_back({ indexA, weight });
		}
		else if (table[indexA][tmpEdgeIndex].weight > weight)
		{
			table[indexA][tmpEdgeIndex].weight = weight;
		}
	}
}

/// <summary>
/// Get all shortest path by Dijkstra algorithm
/// </summary>
/// <param name="path"></param>
/// <param name="shortestPath"></param>
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
		if (tmpEdgeIndex == -1) //initialize the shortestPath of start
		{
			shortestPath[i] = INTMAX;
		}
		else
		{
			shortestPath[i] = table[start][tmpEdgeIndex].weight;
		}

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
	isFindShortestPath[start] = true;

	for (int i = 1; i < vertexNum; i++)
	{
		tmpTime = clock();
		int minPath = INTMAX;
		for (int j = 0; j < vertexNum; j++) //get the minPath, record the vertex
		{
			if (!isFindShortestPath[j] && shortestPath[j] < minPath)
			{
				minPath = shortestPath[j];
				start = j;
			}
		}
		isFindShortestPath[start] = true;
		searchMinTime += clock() - tmpTime;

		tmpTime = clock();
		//for (int j = 0; j < vertexNum; j++) //update the shortest path
		//{
		//	//if there is no connection between the last added vertex, making it reachable
		//	//if there is a shorter path to a vertex which alrea_dy have way, make it as the shortest
		//	//if (!isFindShortestPath[j] && table[start].find(j) != table[start].end() && shortestPath[start] + table[start].find(j)->second < shortestPath[j])
		//	//{
		//	//	shortestPath[j] = shortestPath[start] + table[start].find(j)->second;
		//	//	path[j] = start; //update the path
		//	//}
		//
		//}
		for (int k = 0; k < table[start].size(); k++)
		{
			int j = table[start][k].vertexId;
			if (!isFindShortestPath[j] && shortestPath[start] + table[start][k].weight < shortestPath[j])
			{
				shortestPath[j] = shortestPath[start] + table[start][k].weight;
				path[j] = start; //update the path
			}
		}

		updateTime += clock() - tmpTime;
	}
	cerr << "Search time: " << searchMinTime << "ms" << endl;
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