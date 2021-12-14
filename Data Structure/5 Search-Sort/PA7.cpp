//@date: 2021/12/14
//@author: LPH
//@description: PA7 Three body

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Dataset
{
private:
	map<string, double> datas; // name, value

public:
	bool insert(string, double);
};

class TireTree
{
private:
	char letter;				  // the letter of the node
	bool isEnd;					  // flag of whether the node is the end of the word
	Dataset *datas;				  // datas of the node
	vector<TireTree> nextLetters; // children of the node
public:
	void insertWord(string word);
	bool inputWordData(string word, string dataName, double dataValue);
	TireTree *search(string word);
	bool checkComplete();
};

/* class FleetTable
{
private:
	TireTree& tireTreeRoot;
	double weight;
public:
	FleetTable(TireTree& tireTreeRoot):tireTreeRoot(tireTreeRoot){};
	void insert(string word, double data);
	double search(string word);
}; */

class Fleet
{

private:
	TireTree tireTreeRoot;
	//vector<pair<string, double>> fleetScore;
	priority_queue<string, double,less<double>> fleetScore;	// name, score. Only available when print.
public:
	void insertTable(string tableName, double weight);
	void print();
	void createFleet(string fleetName);
};

int main()
{
	// FleetOverall fleetOverall;
	// Dataset dataset;
	/* 	//tireTree.insert("hello", 1);
		tireTree.insert("hell", 2);
		tireTree.insert("he", 3);
		tireTree.insert("h", 4);
		//tireTree.insert("hel", 5);
		//tireTree.insert("helo", 6);

		cout << tireTree.search("hello") << endl;
		cout << tireTree.search("hell") << endl;
		cout << tireTree.search("he") << endl;
		cout << tireTree.search("h") << endl;
		cout << tireTree.search("hel") << endl;
		cout << tireTree.search("helo") << endl;
		cout << tireTree.search("heee") << endl;
		cout<<sizeof(tireTree)<<endl; */

	Fleet fleets;

	while (true)
	{
		cout << "Please input warships name, 'end' as an end: " << endl;
		string warshipName;
		cin >> warshipName;
		if (warshipName == "end")
		{
			break;
		}
		fleets.createFleet(warshipName);
	}

	while (true)
	{
		cout << "Please enter the data name and weight:" << endl;
		string tableName;
		double weight;
		cin >> tableName >> weight;
		fleets.insertTable(tableName, weight);
	}

	return 0;
}

void TireTree::insertWord(string word)
{
	if (word.length() == 0) // if no more letter
	{
		isEnd = true;
		return;
	}
	char letter = word[0];
	for (int i = 0; i < nextLetters.size(); i++) // find the next letter
	{
		if (nextLetters[i].letter == letter)
		{
			nextLetters[i].insertWord(word.substr(1));
			return;
		}
	}

	TireTree newNode; // if not found, create a new node
	newNode.letter = letter;
	newNode.insertWord(word.substr(1));
	nextLetters.push_back(newNode);
}

bool TireTree::inputWordData(string word, string dataName, double dataValue)
{
	return search(word)->datas->insert(dataName, dataValue);
}

TireTree *TireTree::search(string word)
{
	if (word.length() == 0) // if no more letter
	{
		if (isEnd)
		{
			return this;
		}
		else
		{
			return NULL;
		}
	}

	char letter = word[0]; // if not reach end, find the next letter
	for (int i = 0; i < nextLetters.size(); i++)
	{
		if (nextLetters[i].letter == letter)
		{
			return nextLetters[i].search(word.substr(1));
		}
	}
	return NULL;
}

/* Fleet overall



















*/


bool Dataset::insert(string name, double data)
{
	//	cout << "Please enter the name of the data, followed by a space and the value of the data.\nenter 'end' to quit: " << endl;
	datas[name] = data;

	return true;
}

void Fleet::insertTable(string tableName, double weight)
{
	cout << "Now please enter warship name and its data, 'end' as an end:" << endl;
	while (true)
	{
		string warshipName;
		double data;
		cin >> warshipName;
		if (warshipName == "end")
		{
			break;
		}
		cin >> data;
		if(!tireTreeRoot.inputWordData(warshipName, tableName, data))
		{
			cout << "Error: " << warshipName << " is not in the fleet." << endl;
		}
	}
}

void Fleet::createFleet(string fleetName)
{
	tireTreeRoot.insertWord(fleetName);
}
