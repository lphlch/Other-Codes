//@date: 2021/11/25
//@author: LPH
//@description: PA5 Single-draw-painting

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;

vector<vector<pair<int, int>>> allPath; //first level is collections of pathes, second level is the way

class UndirectedGraph
{
private:
	vector<vector<int>> matrix; //save the graph table
	int vertexNum;
	int edgeNum;
	vector<vector<bool>> visited;   //save the visited status
	vector<pair<int, int>> path;    //save the path

public:
	void create();
	void printMatrix();
	void dfsSearch(int steps, int start);
	void printVisited();
};

/// <summary>
/// create the graph, time complexity is O(M)
/// </summary>
void UndirectedGraph::create()
{
	cout << "Please input the number of vertexs and edges:";
	cin >> vertexNum >> edgeNum;
	if(vertexNum < 1 || edgeNum < 1)
	{
		cout << "The number of vertexs and edges must be greater than 0." << endl;
		exit(0);
	}
	matrix.resize(vertexNum);
	visited.resize(vertexNum);

	for (int i = 0; i < vertexNum; i++)
	{
		matrix[i].resize(vertexNum);
		visited[i].resize(vertexNum);
	}
	int indexA, indexB;
	cout<<"Please input the edges, start to end:"<<endl;
	for (int i = 0; i < edgeNum; i++)
	{
		cin >> indexA >> indexB;
		if(indexA < 1 || indexA >vertexNum || indexB < 1 || indexB > vertexNum)
		{
			cout << "The index of vertexs must be greater than 0 and less than " << vertexNum+1 << endl;
			exit(0);
		}
		matrix[indexA - 1][indexB - 1] = 1;
		matrix[indexB - 1][indexA - 1] = 1;
	}
	cout << endl;
}

/// <summary>
/// print the matrix, time complexity is O(N^2)
/// </summary>
void UndirectedGraph::printMatrix()
{
	cout << "The original matrix is:" << endl<<"  ";
	for (int i = 0; i < vertexNum; i++)
	{
		cout << i + 1 << ' ';
	}
	cout << endl;
	for (int i = 0; i < vertexNum; i++)
	{
		cout << i + 1 << ' ';
		for (int j = 0; j < vertexNum; j++)
		{
			cout <<matrix[i][j] << ' ';
		}
		cout << endl;
	}
}

/// <summary>
/// dfs search all the pathes, time complexity of single function is O(N), time complexity of all function is O(N^M)
/// </summary>
/// <param name="steps"> current edges passed </param>
/// <param name="start"> start vertex </param>
void UndirectedGraph::dfsSearch(int steps, int start)
{
	//visited[start][0] = true;
	//path.push_back(make_pair(start, 0));

	//printVisited();
	//cout<<"steps: "<<steps<<endl;

	if (steps == edgeNum)
	{
		allPath.push_back(path);
		return;
	}
	for (int i = 0; i < vertexNum; i++)
	{
		if (matrix[start][i] == 1 && visited[start][i] == false)
		{
			visited[start][i] = true;
			visited[i][start] = true;

			path.push_back(make_pair(start, i));
			dfsSearch(steps + 1, i);

			visited[start][i] = false;
			visited[i][start] = false;
			path.pop_back();
		}
	}
	//path.pop_back();
}

/// <summary>
/// print the visited matrix,for debug
/// </summary>
void UndirectedGraph::printVisited()
{
	cout << "----------------------------" << endl;
	cout<<path[path.size()-1].first+1<<"->"<<path[path.size()-1].second+1<<endl;
	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
}

/// <summary>
/// print all path, time complexity is O(2^M)(The worst case is 2 vertexs)
/// </summary>
void printAllSingleDrawing()
{
	cout<<endl<<"All single drawing:"<<endl;
	for (int i = 0;i<allPath.size();i++)
	{
		cout << "No."<<setw(3)<<i+1<<": "<<allPath[i][0].first + 1;
		for (int j = 0; j < allPath[i].size(); j++)
		{
			cout << "->" << allPath[i][j].second + 1;
		}
		cout << endl;
	}
}

int main()
{
	UndirectedGraph ug;

	ug.create();
	ug.printMatrix();
	ug.dfsSearch(0, 0);
	printAllSingleDrawing();
	//ug.printMatrix();
	return 0;
}

/*
5 8
1 2
1 3
1 5
2 3
2 5
3 4
3 5
4 5
*/