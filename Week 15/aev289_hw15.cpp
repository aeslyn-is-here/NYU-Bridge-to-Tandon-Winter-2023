#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Node;
class LinkedList;

class Node
{
private:
	double data;
	string name;

public:
	Node(){};
	Node(double d, string n) : data(d), name(n){};
	Node *next;
	Node *prev;
	friend class LinkedList;
};

class LinkedList
{
private:
	Node *head;
	Node *tail;
	double portion;

public:
	LinkedList() : head(nullptr), tail(nullptr){};
	~LinkedList()
	{
		Node *temp = head;
		while (temp != nullptr)
		{
			Node *tempNext = temp->next;
			delete temp;
			temp = tempNext;
		}
	}

	Node *getHead()
	{
		return head;
	}
	Node *getTail()
	{
		return tail;
	}
	double getPortion() { return portion; };
	void setPortion(double p) { portion = p; };

	void addNode(double n, string name);
	void display();
	void calculatePortion();
	void displayExactPaid();
	void displayOwed();
	void displayEnd();
	void output()
	{
		calculatePortion();
		displayExactPaid();
		displayOwed();
		displayEnd();
	}
	void displayRecursive(Node *temp)
	{
		if (temp != nullptr)
		{
			cout << head->data << endl;
			displayRecursive(temp->next);
		}
	}
};
void openInputFile(ifstream &inFile);
int main()
{
	ifstream inFile;
	openInputFile(inFile);
	LinkedList people;
	double data;
	string s;
	while (inFile >> data)
	{
		inFile.ignore(9999, '\t');
		getline(inFile, s);
		people.addNode(data, s);
	}
	people.output();
	// vector<Node> people;
	// Node temp;
	// while (inFile >> temp.data)
	// {
	//     getline(inFile, temp.name);
	//     people.push_back(temp);
	// }
	// for (Node n : people)
	// {
	//     cout << n.data << " " << n.name << endl;
	// }
	if (inFile)
	{
		inFile.close();
	}
	return 0;
}
void openInputFile(ifstream &inFile)
{
	string filename;
	cout << "Enter the filename: ";
	cin >> filename;
	inFile.open(filename);
	while (!inFile)
	{
		cout << "Error opening file" << endl;
		cout << "Enter the filename:  ";
		cin >> filename;
		inFile.clear();
		inFile.open(filename);
	}
}
void LinkedList::addNode(double d, string n)
{
	Node *temp = new Node(d, n);
	temp->next = nullptr;

	if (head == nullptr)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = tail->next;
	}
}
void LinkedList::display()
{
	Node *temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << " " << temp->name << endl;
		temp = temp->next;
	}
}
void LinkedList::calculatePortion()
{
	double sum = 0;
	double portion;
	int numNodes = 0;
	Node *temp = head;
	while (temp != nullptr)
	{
		sum += temp->data;
		temp = temp->next;
		numNodes += 1;
	}
	portion = sum / numNodes;
	setPortion(portion);
}
void LinkedList::displayExactPaid()
{
	Node *temp = head;
	while (temp != nullptr)
	{
		if (temp->data == portion)
		{
			cout << temp->name << ", you don't need to do anything" << endl;
		}
		temp = temp->next;
	}
}
void LinkedList::displayOwed()
{
	Node *oweMoney = head;
	Node *owedMoney = head;
	while (oweMoney && owedMoney)
	{
		while (oweMoney && oweMoney->data >= portion)
			oweMoney = oweMoney->next;
		while (owedMoney && owedMoney->data <= portion)
			owedMoney = owedMoney->next;
		if (!oweMoney || !owedMoney)
			break;
		double canOwe = portion - oweMoney->data;
		double owedAmt = owedMoney->data - portion;
		if (canOwe >= owedAmt)
		{
			oweMoney->data += owedAmt;
			owedMoney->data -= owedAmt;
			cout << oweMoney->name << ", you give " << owedMoney->name << " $" << owedAmt << endl;
		}
		else
		{
			oweMoney->data += canOwe;
			owedMoney->data -= canOwe;
			cout << oweMoney->name << ", you give " << owedMoney->name << " $" << canOwe << endl;
		}
	}
}
void LinkedList::displayEnd()
{
	cout << "In the end, you should have all spent around $" << portion << endl;
}