//@date: 2021/12/14
//@author: LPH
//@description: PA7 Three body

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <iomanip>
using namespace std;

const int BLANK_DATAS = 10; // blanks between data
const int BLANK_NAME = 30;	// blanks between name

class Dataset
{
private:
	map<string, double> datas; // name, value

public:
	bool insert(string, double); // insert a new data
	double countSum();			 // count the sum of all data, weighted
	void print();				 // print all data
};

class TireTree
{
private:
	char letter;				  // the letter of the node
	bool isEnd;					  // flag of whether the node is the end of the word
	Dataset datas;				  // datas of the node
	vector<TireTree> nextLetters; // children of the node
public:
	Dataset& getDatas();
	void insertWord(string word);											  // insert a word into the tire tree
	bool inputWordData(string word, string dataName, double dataValue);		  // input a word's data
	TireTree* search(string word);											  // find the node of the word
	void traverse(string word, priority_queue<pair<double, string>>& scores); // traverse the tire tree and find the words with the highest scores
	bool checkComplete();
};

class Fleet
{
private:
	TireTree tireTreeRoot;
	vector<string> datasName;
	priority_queue<pair<double, string>> fleetScore; // score, name. Only available when print.
public:
	void insertTable(string tableName, double weight); // insert a table
	void print();									   // print scores
	void printScore(string name);					   // print the score of a name, called in print()
	void createFleet(string fleetName);				   // create a fleet
};

int main()
{
	Fleet fleets;
	cout << "Please input warships name, 'end' to print score table: " << endl;
	while (true)
	{
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
		cout << "\nPlease enter the data name and weight, 'end' as an end:" << endl;
		string tableName;
		double weight;
		cin >> tableName;
		if (tableName == "end")
		{
			break;
		}
		cin >> weight;
		fleets.insertTable(tableName, weight);
	}

	fleets.print();
	return 0;
}

Dataset& TireTree::getDatas()
{
	return datas;
}

/// <summary>
/// Insert a word into the tire tree
/// </summary>
/// <param name="word"></param>
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

/// <summary>
/// Input a word's data
/// </summary>
/// <param name="word"></param>
/// <param name="dataName"></param>
/// <param name="dataValue"></param>
/// <returns>true if warship exist</returns>
bool TireTree::inputWordData(string word, string dataName, double dataValue)
{
	auto tireNode = search(word);
	if (tireNode == NULL)
	{
		return false;
	}
	return tireNode->datas.insert(dataName, dataValue);
}

/// <summary>
/// Find the node of the word
/// </summary>
/// <param name="word"></param>
/// <returns>pointer to tire tree node</returns>
TireTree* TireTree::search(string word)
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

/// <summary>
/// Traverse the tire tree and find the words with the highest scores
/// </summary>
/// <param name="word">current warship name</param>
/// <param name="scores">priority queue. Store scores of all warships</param>
void TireTree::traverse(string word, priority_queue<pair<double, string>>& scores)
{
	if (isEnd)
	{
		double sum = datas.countSum();
		scores.push(make_pair(sum, word)); // count the sum of the datas, adding to the priority queue
	}

	for (int i = 0; i < nextLetters.size(); i++)
	{
		nextLetters[i].traverse(word + nextLetters[i].letter, scores); // find next letter
	}
}

/// <summary>
/// insert a data into data set
/// </summary>
/// <param name="name">data name</param>
/// <param name="data">data value</param>
/// <returns></returns>
bool Dataset::insert(string name, double data)
{
	datas[name] = data;

	return true;
}

/// <summary>
/// count the sum of all data, weighted
/// </summary>
/// <returns>score</returns>
double Dataset::countSum()
{
	double sum = 0;
	for (auto it = datas.begin(); it != datas.end(); it++) // traverse all datas
	{
		sum += (it->second);
	}
	return sum;
}

/// <summary>
/// print the data of a warship
/// </summary>
void Dataset::print()
{
	for (auto it = datas.begin(); it != datas.end(); it++)
	{
		cout << setw(BLANK_DATAS) << it->second;
	}
}

/// <summary>
/// insert a table, and input warship data
/// </summary>
/// <param name="tableName">name of table</param>
/// <param name="weight">weight of this kind of data</param>
void Fleet::insertTable(string tableName, double weight)
{
	if (find(datasName.begin(), datasName.end(), tableName) != datasName.end()) // if already exist
	{
		cout << "The table has already existed." << endl;
		return;
	}

	datasName.push_back(tableName); // add table name
	cout << "\nNow please enter warship name and its data, 'end' as an end, :" << endl;
	while (true) // input each warship data
	{
		string warshipName;
		double data;
		cin >> warshipName;
		if (warshipName == "end")
		{
			break;
		}
		cin >> data;
		if (!tireTreeRoot.inputWordData(warshipName, tableName, data * weight)) // insert data*weight into tire tree
		{
			cout << "Error: " << warshipName << " is not in the fleet." << endl;
		}
	}
}

/// <summary>
/// print the data of all warships
/// </summary>
void Fleet::print()
{
	cout << "-------------------------------------------------------------------" << endl;
	tireTreeRoot.traverse("", fleetScore); // sort

	cout << left << setw(BLANK_NAME) << "Name"; // title
	for (auto name : datasName)
	{
		cout << setw(BLANK_DATAS) << name;
	}
	cout << setw(BLANK_DATAS) << "Score" << endl;

	while (!fleetScore.empty()) // print
	{
		auto& top = fleetScore.top();
		cout << left << setw(BLANK_NAME) << top.second << " ";
		printScore(top.second);
		cout << setw(BLANK_DATAS) << top.first << endl;
		fleetScore.pop();
	}
	return;
}

/// <summary>
/// print the data of a warship
/// </summary>
/// <param name="name"></param>
void Fleet::printScore(string name)
{
	this->tireTreeRoot.search(name)->getDatas().print();
}

/// <summary>
/// create a fleet, add it to tire tree
/// </summary>
/// <param name="fleetName">warship name</param>
void Fleet::createFleet(string fleetName)
{
	tireTreeRoot.insertWord(fleetName);
}

/*
Example:

NaturalSelection
BlueSpace
Enterprise
DeepSpace
UltimateLaw
Quantum
Gravitation
Pacific
Einstein
CannonFodderI
StarRing
end

Fire 10
Einstein 4.484
NaturalSelection 15.422
BlueSpace 20.1
Enterprise 14.2
DeepSpace 33.54
Pacific 12.5
UltimateLaw 44
Quantum 34.5
Gravitation 52.4
CannonFodderI 1.6
CannonFodderII 1.44
StarRing 0.11
end

Speed 5
NaturalSelection 4.4
BlueSpace 6.42
Enterprise 4.55
Einstein 7.555
DeepSpace 8
UltimateLaw 5
Quantum 4.54
Pacific 4.44
Gravitation 5.6
CannonFodderI 1.62
CannonFodderII 0.785
StarRing 300
end
end
*/