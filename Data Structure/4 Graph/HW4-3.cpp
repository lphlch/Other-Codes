//@date: 2021/11/21
//@author: LPH
//@description: HW4-3 Critical path

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct Edge
{
	int vertexId; // vertex index, start from 0, id need +1
	int weight;
};

struct Vertex
{
	vector<Edge> edges; // adjacent edges
	int indegree;   // indegree of vertex
};

int findEdge(vector<Vertex> &table, int start, int end)
{
	for (int i = 0; i < table[start].edges.size(); i++)
	{
		if (table[start].edges[i].vertexId == end)
		{
			return i;
		}
	}
	return -1;
}

class DirectedNetwork
{
public:
	vector<Vertex> table;
	int vertexNum;
	int edgeNum;
	void create();
	void print();
	void topologicalSort();
	void printTopologicalSort();
	void criticalPath();
	void printCriticalPath();
private:
	vector<int> topologicalQueue; // store the topological order, start from 0
	vector<pair<int,int>> criticalPathQueue; // store the critical path, start from 0
	int shortestTime=0; // the shortest time
};

/// <summary>
/// create undirected network, and store in table
/// </summary>
void DirectedNetwork::create()
{
	cin >> vertexNum >> edgeNum;
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
			table[indexA].edges.push_back({indexB, weight});
			table[indexB].indegree++; // add indegree
		}
		else if (table[indexA].edges[tmpEdgeIndexA].weight < weight)
		{
			table[indexA].edges[tmpEdgeIndexA].weight = weight; // update weight
		}
	}
}

void DirectedNetwork::print()
{
	for (int i = 0; i < table.size(); i++)
	{
		cout << i + 1 << "->";
		for (int j = 0; j < table[i].edges.size(); j++)
		{
			cout << table[i].edges[j].vertexId + 1 << "(" << table[i].edges[j].weight << ")"
				 << "->";
		}
		cout << endl;
	}
}

/// <summary>
/// topological sort, store the topological order in topologicalQueue
/// </summary>
void DirectedNetwork::topologicalSort()
{
	stack<int> s;
	for (int i = 0; i < table.size(); i++)
	{
		if (table[i].indegree == 0)
		{
			s.push(i);
		}
	}
	int tmp;
	while (!s.empty())
	{
		tmp = s.top();
		s.pop();
		topologicalQueue.push_back(tmp);
		for (int i = 0; i < table[tmp].edges.size(); i++)
		{
			int index = table[tmp].edges[i].vertexId;
			table[index].indegree--;
			if (table[index].indegree == 0)
			{
				s.push(index);
			}
		}
	}
}

void DirectedNetwork::printTopologicalSort()
{
	for (int i = 0; i < topologicalQueue.size(); i++)
	{
		cout << topologicalQueue[i] + 1 << "->";
	}
	cout << endl;
}

/// <summary>
/// find the critical path, and store in criticalPathQueue
/// </summary>
void DirectedNetwork::criticalPath()
{
	vector<int> earliestTime(vertexNum, 0);			  // store the earliest time of each vertex
	for (int i = 0; i < topologicalQueue.size(); i++) // find the earliest time of each vertex
	{
		int index = topologicalQueue[i];
		for (int j = 0; j < table[index].edges.size(); j++) //for each edge of this vertex, get all destination vertex, update maximum time
		{
			int tmpIndex = table[index].edges[j].vertexId;
			if (earliestTime[tmpIndex] < earliestTime[index] + table[index].edges[j].weight)
			{
				earliestTime[tmpIndex] = earliestTime[index] + table[index].edges[j].weight;
			}
		}
	}

	int lastEventEarliestTime;
	for (int i = 0; i < earliestTime.size(); i++)
	{
		lastEventEarliestTime=max(lastEventEarliestTime,earliestTime[i]);
	}
	
	vector<int> latestTime(vertexNum, lastEventEarliestTime); // store the latest time of each vertex, init with the last element of earliestTime
	for (int i = topologicalQueue.size() - 1; i >= 0; i--)	// find the latest time of each vertex
	{
		int index = topologicalQueue[i];
		for (int j = 0; j < table[index].edges.size(); j++) //for each edge of this vertex, get all destination vertex, update minimum time
		{
			int dstIndex = table[index].edges[j].vertexId;
			if (latestTime[index] > latestTime[dstIndex] - table[index].edges[j].weight)
			{
				latestTime[index] = latestTime[dstIndex] - table[index].edges[j].weight;
			}
		}
	}

	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0;j<table[i].edges.size();j++)
		{
			int dstIndex = table[i].edges[j].vertexId;
			if (earliestTime[i] + table[i].edges[j].weight == latestTime[dstIndex])
			{
				criticalPathQueue.push_back({i, dstIndex});
				shortestTime += table[i].edges[j].weight;
			}
		}
	}

	//for (int i = 0; i < earliestTime.size(); i++)
	//{
	//	cout<<earliestTime[i]<<" ";
	//}
	//cout<<endl;
	//for (int i = 0; i < latestTime.size(); i++)
	//{
	//	cout<<latestTime[i]<<" ";
	//}
}

/// <summary>
/// print the critical path
/// </summary>
void DirectedNetwork::printCriticalPath()
{
	if(topologicalQueue.size()!=vertexNum)
	{
		cout << 0<< endl;
		return;
	}
	cout<<shortestTime<<endl;
	for (int i = 0; i < criticalPathQueue.size(); i++)
	{
		cout << criticalPathQueue[i].first + 1 << "->" << criticalPathQueue[i].second + 1 << endl;
	}
}

int main()
{
	DirectedNetwork network;
	network.create();
	//network.print();
	network.topologicalSort();
	//network.printTopologicalSort();
	network.criticalPath();
	network.printCriticalPath();
	return 0;
}
