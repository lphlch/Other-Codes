//@date: 2021/11/24
//@author: LPH
//@description: HW4-5 Small world

#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;
time_t start = 0;
time_t tmp = clock();
time_t singleLevel = 0;
const int MAX_LEVEL = 6;
const int INTMAX = 2147483647;

class UndirectedGraph
{
private:
	vector<vector<int>> table; //save the graph table
	int vertexNum;
	int edgeNum;

public:
	void create();
	void printTable();
	void printSmallWorld();
	int countPath(int start);
};

/// <summary>
/// create the graph
/// </summary>
void UndirectedGraph::create()
{
	cin >> vertexNum >> edgeNum;
	table.resize(vertexNum);

	int indexA, indexB;
	for (int i = 0; i < edgeNum; i++)
	{
		cin >> indexA >> indexB;
		table[indexA - 1].push_back(indexB - 1);
		table[indexB - 1].push_back(indexA - 1);
	}
}

/// <summary>
/// count the path not more than MAXLEVEL from start to every vertex, by dijkstra algorithm
/// </summary>
/// <param name="start"> vertex </param>
/// <returns> numbers of vertexs which is shorter than MAXLEVEL </returns>
int UndirectedGraph::countPath(int start)
{

	vector<bool> isFindShortestPath(vertexNum, false);
	vector<int> shortestPath(vertexNum, INTMAX);

	int tmpEdgeIndex = -1;
	shortestPath[start] = 0;

	priority_queue<pair<int, int>> pQ;	//first is the distance, second is the vertex
	pQ.push({ INTMAX, start });

	int count = 0;
	while (!pQ.empty())
	{
		if (-pQ.top().first > MAX_LEVEL)
		{
			break;
		}
		count++;
		int tmpVertex = pQ.top().second;	//get the vertex with the smallest distance
		pQ.pop();
		if (isFindShortestPath[tmpVertex])	//if the tmpVertex has been found
		{
			continue;
		}
		isFindShortestPath[tmpVertex] = true;


		for (int i = 0; i < table[tmpVertex].size(); i++)
		{
			int j = table[tmpVertex][i];
			if (!isFindShortestPath[j] && shortestPath[tmpVertex] + 1 < shortestPath[j])	//update the shortest path
			{
				shortestPath[j] = shortestPath[tmpVertex] + 1;

				pQ.push({ -shortestPath[j], j });
			}
		}
	}
	return count;
}

/// <summary>
/// calculate and print the result
/// </summary>
void UndirectedGraph::printSmallWorld()
{
	start = clock();


	for (int i = 0; i < vertexNum; i++)
	{
		int count = countPath(i);
		cout << i + 1 << ':' << ' ' << std::fixed << std::setprecision(2) << float(count * 100.0 / vertexNum + 0.004) << '%' << std::endl;
	}
	start = clock() - start;
	cerr << "time: " << start << endl;
}

#pragma endregion

int main()
{
	UndirectedGraph ug;
	ug.create();

	ug.printSmallWorld();

	return 0;
}