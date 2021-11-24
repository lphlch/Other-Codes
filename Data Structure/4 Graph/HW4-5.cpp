//@date: 2021/11/24
//@author: LPH
//@description: HW4-5 Small world

#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

const int MAX_LEVEL = 6;
#pragma region DIRECTED_GRAPH
class UndirectedGraph
{
protected:
	vector<vector<int>> matrix; //save the graph matrix
	vector<char> vertex;		//save the vertex
	int vertexNum;
	int edgeNum;

public:
	void create();
	void printMatrix();
	void printTable();
	void printSmallWorld();
	int bfs(int start);
};

/// <summary>
/// create the graph
/// </summary>
void UndirectedGraph::create()
{
	cin >> vertexNum >> edgeNum;
	matrix.resize(vertexNum);
	for (int i = 0; i < vertexNum; i++)
	{
		matrix[i].resize(vertexNum);
	}
	int indexA, indexB;
	for (int i = 0; i < edgeNum; i++)
	{
		cin >> indexA >> indexB;
		matrix[indexA - 1][indexB - 1] = 1; //set the matrix
		matrix[indexB - 1][indexA - 1] = 1;
	}
}

/// <summary>
/// print the matrix
/// </summary>
void UndirectedGraph::printMatrix()
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
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

/// <summary>
/// print the table
/// </summary>
void UndirectedGraph::printTable()
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

int UndirectedGraph::bfs(int start)
{
	vector<bool> visited(vertexNum, false);
	queue<pair<int, int>> q; // first is the vertex, second is the level
	q.push({start, 0});
	visited[start] = true;
	int count = 0;
	int level = 0;
	while (!q.empty())
	{
		int temp = q.front().first;
		level = q.front().second;
		if (level > MAX_LEVEL)
		{
			break;
		}
		q.pop();
		for (int i = 0; i < vertexNum; i++)
		{
			if (matrix[temp][i] != 0 && !visited[i])
			{
				q.push({i, level + 1});
				visited[i] = true;
			}
		}
		count++;
	}
	return count;
}

void UndirectedGraph::printSmallWorld()
{
	time_t start = 0;
	time_t tmp = clock();
	for (int i = 0; i < vertexNum; i++)
	{
		printf("%d: %.2f%%\n", i + 1, (float)bfs(i) / (float)vertexNum * (float)100);
		if (i % 10 == 0)
		{
			start = clock() - start;
			cerr << "timeEvery10: " << start << endl;
		}
	}
}

#pragma endregion

int main()
{
	UndirectedGraph ug;
	ug.create();
	ug.printSmallWorld();

	return 0;
}