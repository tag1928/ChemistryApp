#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct atom
{
	string name;
	int atomic;
	double mass;
	string symbol;
	string group;
	string period;
};

vector <atom> element(0);

int main();

bool showByName()
{
	string name;
	cout << "\n====================\n" << endl;
	cout << "Type \"back\" to return to main menu\n" << endl;
	cout << "Enter the name of an element:\t";
	cin >> name;
	
	if (name == "back") return main();
	
	for (int i = 0; i < element.size(); i++)
	{
		if (element[i].name == name)
		{
			cout << "Atomic:\t" << element[i].atomic << endl;
			cout << "Mass:\t" << element[i].mass << endl;
			cout << "Symbol:\t" << element[i].symbol << endl;
			cout << "Group:\t" << element[i].group << endl;
			cout << "Period:\t" << element[i].period << endl;
			return showByName();
		}
	}
	return showByName();
}

bool showBySymbol()
{
	string symbol;
	cout << "\n====================\n" << endl;
	cout << "Type \"back\" to return to main menu\n" << endl;
	cout << "Enter the symbol of an element:\t";
	cin >> symbol;
	
	if (symbol == "back") return main();
	
	for (int i = 0; i < element.size(); i++)
	{
		if (element[i].symbol == symbol)
		{
			cout << "Name:\t" << element[i].name << endl;
			cout << "Atomic:\t" << element[i].atomic << endl;
			cout << "Mass:\t" << element[i].mass << endl;
			cout << "Group:\t" << element[i].group << endl;
			cout << "Period:\t" << element[i].period << endl;
			return showBySymbol();
		}
	}
	return showBySymbol();
}

bool showByAtomic()
{
	int atomic;
	cout << "\n====================\n" << endl;
	cout << "Type \"0\" to return to main menu\n" << endl;
	cout << "Enter the atomic number of an element:\t";
	cin >> atomic;
	
	if (atomic == 0) return main();
	
	for (int i = 0; i < element.size(); i++)
	{
		if (element[i].atomic == atomic)
		{
			cout << "Name:\t" << element[i].name << endl;
			cout << "Mass:\t" << element[i].mass << endl;
			cout << "Symbol:\t" << element[i].symbol << endl;
			cout << "Group:\t" << element[i].group << endl;
			cout << "Period:\t" << element[i].period << endl;
			return showByAtomic();
		}
	}
	return showByAtomic();
}

bool mainMenu(int choice)
{
	if (choice == 0) return true;
	if (choice == 1) return showByName();
	if (choice == 2) return showBySymbol();
	if (choice == 3) return showByAtomic();
}

void fileRead()
{
	ifstream jamal("data.txt");
	
	while (!jamal.eof())
	{
		atom a;
		jamal >> a.name;
		jamal >> a.atomic;
		jamal >> a.mass;
		jamal >> a.symbol;
		jamal >> a.group;
		jamal >> a.period;
		element.push_back(a);
	}
	
	return;
}

int main()
{
	fileRead();
	
	int input;
	
	cout << "\n====================\n" << endl;
	cout << "By:\t" << endl;
	cout << "0.Exit" << endl;
	cout << "1.Name" << endl;
	cout << "2.Symbol" << endl;
	cout << "3.Atomic number" << endl;
	cin >> input;
	
	if (mainMenu(input)) return 0;
}

