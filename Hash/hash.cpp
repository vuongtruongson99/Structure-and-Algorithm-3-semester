#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

const int TABLE_SIZE = 10;

struct Reader {
	int _ind;
	int _number;
	string _name;
	string _address;
};


class Hash {
	list<Reader> *table;

public:
	Hash() {
		table = new list<Reader>[TABLE_SIZE];
	}

	int hashFunction(int x) {
		return (x % TABLE_SIZE);
	}

	void insertData() {
		int ind, number;
		string name, address;

		cout << "Input reader's number: ";
		cin >> ind;
		cout << "Input 5-digit number: ";
		cin >> number;
		cout << "Input name of reader: ";
		cin.ignore(1);
		getline(cin, name);
		cout << "Input address of reader: ";
		cin.ignore(1);
		getline(cin, address);

		int i = hashFunction(ind);
		Reader tmp;
		tmp._ind = ind;
		tmp._number = number;
		tmp._name = name;
		tmp._address = address;

		table[i].push_back(tmp);
	}

	void deleteData() {
		int readerNumber;
		cout << "Enter reader number to delete: ";
		cin >> readerNumber;

		int index = hashFunction(readerNumber);

		list<Reader>::iterator i;
		for (i = table[index].begin(); i != table[index].end(); ++i) {
			if (i->_ind == readerNumber) {
				break;
			}
		}

		if (i != table[index].end()) {
			cout << "Reader " << i->_name << " has been removed from list!\n";
			table[index].erase(i);
		}
		else {
			cout << "Reader number is not in this list!\n";
		}
	}

	void search() {
		int readerNumber;
		cout << "Enter reader number to find: ";
		cin >> readerNumber;
		int index = hashFunction(readerNumber);

		list<Reader>::iterator i;
		bool check = false;
		for (i = table[index].begin(); i != table[index].end(); ++i) {
			if (i->_ind == readerNumber) {
				check = true;
				cout << "Record found:\n";
				cout << "\tReader Number\t\t5-digit number\t\tName\t\t\tAddress\n";
				cout << "\t" << i->_ind << "\t\t\t" << i->_number << "\t\t\t" << i->_name << "\t\t" << i->_address << "\n";
			}
		}

		if (!check) {
			cout << "Cannot find this reader!\n";
		}
	}

	void displayHash() {
		cout << "Index\t\tReader Name\n";
		for (int i = 0; i < 10; ++i) {
			cout << i << ": ";
			for (auto x : table[i]) {
				cout << "  -->  " << x._name;
			}
			cout << endl;
		}
	}
};

int main() {
	Hash t = Hash();
	cout << "------------------------Menu------------------------\n";
	cout << "[1] - Insert new record\n";
	cout << "[2] - Find a reader\n";
	cout << "[3] - Delete a reader\n";
	cout << "[4] - Display hash table\n";
	cout << "[0] - Exit program\n";
	cout << "----------------------------------------------------\n";

	int choice = 0;
	do
	{
		cout << "Input your choice: ";
		cin >> choice;
		cout << "----------------------------------------------------\n";

		switch (choice)
		{
		case 1:
			int n;
			cout << "Input number of record to insert: ";
			cin >> n;
			for (int i = 0; i < n; ++i) {
				cout << "-----------------------------------------\n";
				t.insertData();
			}
			cout << "Done!\n";
			break;

		case 2:
			t.search();
			break;
		case 3:
			t.deleteData();
			break;
		case 4:
			t.displayHash();
			break;
		case 0:
			cout << "Thanks for using program!\n";
			break;
		default:
			break;
		}

		cout << "----------------------------------------------------\n";
	} while (choice != 0);


	system("pause");
	return 0;
}