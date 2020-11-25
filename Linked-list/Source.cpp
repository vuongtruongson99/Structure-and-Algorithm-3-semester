#include <iostream>
using namespace std;

template<typename T>
class NodeData {
public:
	NodeData() : _pNext(NULL) { ; }

	void set_data(T val) {
		data = val;
	}

	T get_data() { return data; }

	void set_pNext(NodeData<T>* pNext) {
		_pNext = pNext;
	}

	NodeData<T> *get_pNext() {
		return _pNext;
	}

private:
	T data;
	NodeData<T> *_pNext;
};

template<typename T>
class LinkedList {
public:
	LinkedList() : _pHead(NULL) { ; }

	void push_back(T val);
	void addElementAfterElement(T new_element, T after_element);
	void deleteElement(T dele_element);
	void findPos(T find_element);
	void print();
private:
	NodeData<T> *_pHead;
};

template<typename T>
void LinkedList<T>::push_back(T val) {
	if (_pHead == NULL) {
		NodeData<T> *tmp = new NodeData<T>();
		tmp->set_data(val);
		_pHead = tmp;
	}
	else {
		NodeData<T> *current = _pHead;
		while (current->get_pNext() != NULL) {
			current = current->get_pNext();
		}

		NodeData<T> *tmp = new NodeData<T>();
		tmp->set_data(val);
		current->set_pNext(tmp);
	}
}

template<typename T>
void LinkedList<T>::addElementAfterElement(T new_element, T after_element) {
	NodeData<T> *current = _pHead;

	while (current != NULL && current->get_data() != after_element) {
		current = current->get_pNext();
	}
	
	if (current == NULL) {
		cout << "You are input wrong number!";
	}
	else {
		NodeData<T> *tmp = new NodeData<T>();
		tmp->set_data(new_element);
		tmp->set_pNext(current->get_pNext());
		current->set_pNext(tmp);
		cout << "Done!";
	}
}

template<typename T>
void LinkedList<T>::deleteElement(T dele_element) {
	NodeData<T> *current = _pHead, *prev = NULL;
	if (current->get_data() == dele_element) {
		_pHead = current->get_pNext();
		delete current;
	}
	else {
		while (current != nullptr && current->get_data() != dele_element) {
			prev = current;
			current = current->get_pNext();
		}

		if (current == nullptr) {
			cout << "Cannot delete this element. Please try again!";
			return;
		}
		prev->set_pNext(current->get_pNext());
		delete current;

	}
}

template<typename T>
void LinkedList<T>::findPos(T find_element) {
	NodeData<T> *current = _pHead;
	int index = 1;

	while (current != nullptr && current->get_data() != find_element) {
		++index;
		current = current->get_pNext();
	}

	if (current == nullptr) {
		cout << "Cannot find this element!";
	}
	else {
		cout << "Position of this number is: " << index;
	}
}

template<typename T>
void LinkedList<T>::print() {
	NodeData<T> *current = _pHead;
	while (current != nullptr) {
		cout << current->get_data() << " ";
		current = current->get_pNext();
	}
}

int main() {
	LinkedList<int> l;
	cout << "------------------------------------------------------------------------\n";
	cout << "Input 10 element of list:\n";
	for (int i = 0; i < 10; ++i) {
		int data;
		cin >> data;
		l.push_back(data);
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "Command linked list\n";
	cout << "[1] - Output list\n";
	cout << "[2] - Add an element after given element\n";
	cout << "[3] - Delete given element first occurrence\n";
	cout << "[4] - Find position of element\n";
	cout << "[0] - End program\n";
	cout << "------------------------------------------------------------------------\n";

	int n;
	do
	{
		/* code */
		cout << "\nInput your choice: ";
		cin >> n;
		cout << "-----------------------------------------------------------\n";
		switch (n)
		{
		case 1:
			l.print();
			break;
		case 2:
			cout << "Enter the number to add: ";
			int first, second;
			cin >> first;
			cout << "Enter the number to add new element after this number: ";
			cin >> second;
			l.addElementAfterElement(first, second);
			break;
		case 3:
			int del;
			cout << "Enter the number you want to delete: ";
			cin >> del;
			l.deleteElement(del);
			cout << "Element " << del << " has been removed from list!";
			break;
		case 4:
			int ele;
			cout << "Enter the number you want to find first position occurrence: ";
			cin >> ele;
			l.findPos(ele);
		case 0:
			break;
		default:
			break;
		}
		cout << "\n-----------------------------------------------------------\n";
	} while (n != 0);



	system("pause");
	return 0;
}