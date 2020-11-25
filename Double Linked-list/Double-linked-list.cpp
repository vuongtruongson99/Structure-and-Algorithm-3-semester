#include <iostream>
using namespace std;

template<typename T>
class NodeData {
public:
	NodeData() : _pNext(NULL), _pPrev(NULL) { ; }

	void set_data(T val) {
		_data = val;
	}

	T get_data() {
		return _data;
	}

	void set_pNext(NodeData<T>* pNext) {
		_pNext = pNext;
	}

	NodeData<T> *get_pNext() const {
		return _pNext;
	}

	void set_pPrev(NodeData<T>* pPrev) {
		_pPrev = pPrev;
	}

	NodeData<T> *get_pPrev() const {
		return _pPrev;
	}
private:
	T _data;
	NodeData<T> *_pNext;
	NodeData<T> *_pPrev;
};

template<typename T>
class DoubleList {
public:
	DoubleList() : _pHead(NULL) { ; }

	void push_back(T val);
	void push_front(T val);
	void push_mid(T new_ele, T after_ele);
	void pop_back();
	void pop_front();
	void pop(T val);
	void printLeftToRight();
	void printRightToLeft();
	void find(T val);
	T get_first();
	T get_last();

private:
	NodeData<T> *_pHead;
};

template<typename T>
void DoubleList<T>::push_back(T val) {
	NodeData<T> *current = _pHead;
	if (current == NULL) {
		NodeData<T> *tmp = new NodeData<T>();
		tmp->set_data(val);
		_pHead = tmp;
	}
	else {
		while (current->get_pNext() != NULL) {
			current = current->get_pNext();
		}
		NodeData<T> *tmp = new NodeData<T>();
		tmp->set_data(val);
		tmp->set_pNext(NULL);
		tmp->set_pPrev(current);
		current->set_pNext(tmp);
	}
}

template<typename T>
void DoubleList<T>::push_front(T val) {
	NodeData<T> *tmp = new NodeData<T>();
	tmp->set_data(val);
	tmp->set_pNext(_pHead);
	tmp->set_pPrev(NULL);

	if (_pHead != NULL) {
		_pHead->set_pPrev(tmp);
	}
	_pHead = tmp;
}

template<typename T>
void DoubleList<T>::push_mid(T new_ele, T after_ele) {
	NodeData<T> *current = _pHead;

	while (current != NULL && current->get_data() != after_ele) {
		current = current->get_pNext();
	}
	
	if (current == NULL) {
		cout << "You are input wrong number!";
	}
	else {
		NodeData<T> *tmp = new NodeData<T>();
		tmp->set_data(new_ele);
		tmp->set_pNext(current->get_pNext());
		tmp->set_pPrev(current);
		current->get_pNext()->set_pPrev(tmp);
		current->set_pNext(tmp);
	}
}

template<typename T>
void DoubleList<T>::pop_back() {
	if (_pHead != NULL) {
		NodeData<T> *current = _pHead;

		while (current->get_pNext() != NULL) {
			current = current->get_pNext();
		}
		current->get_pPrev()->set_pNext(NULL);
		delete current;
	}
}

template<typename T>
void DoubleList<T>::pop_front() {
	if (_pHead != NULL) {
		NodeData<T> *current = _pHead;
		current->get_pNext()->set_pPrev(NULL);
		_pHead = current->get_pNext();
		delete current;
	}
}

template<typename T>
void DoubleList<T>::pop(T val) {
	NodeData<T> *current = _pHead;

	while (current != NULL && current->get_data() != val) {
		current = current->get_pNext();
	}

	if (current == NULL) {
		cout << "This element is not in the list!";
	}
	else {
		current->get_pPrev()->set_pNext(current->get_pNext());
		current->get_pNext()->set_pPrev(current->get_pPrev());
		delete current;
	}
}

template<typename T>
void DoubleList<T>::printLeftToRight() {
	NodeData<T> *current = _pHead;

	while (current != NULL) {
		cout << current->get_data() << " ";
		current = current->get_pNext();
	}
}

template<typename T>
void DoubleList<T>::printRightToLeft() {
	NodeData<T> *current = _pHead;

	while (current->get_pNext() != NULL) {
		current = current->get_pNext();
	}

	while (current != NULL) {
		cout << current->get_data() << " ";
		current = current->get_pPrev();
	}
}

template<typename T>
T DoubleList<T>::get_first() {
	return _pHead->get_data();
}

template<typename T>
T DoubleList<T>::get_last() {
	NodeData<T> *current = _pHead;

	while (current->get_pNext() != NULL) {
		current = current->get_pNext();
	}
	return current->get_data();
}

template<typename T>
void DoubleList<T>::find(T val) {
	NodeData<T> *current = _pHead;
	int index = 1;

	while (current != NULL && current->get_data() != val) {
		++index;
		current = current->get_pNext();
	}
	if (current == NULL) {
		cout << "This element is not in the list!";
	}
	else {
		cout << "This element is at the " << index << " position in the list";
	}
}

int main() {
	DoubleList<int> dlist;
	cout << "------------------------------------------------------------------------\n";
	cout << "Input 10 element of list:\n";
	for (int i = 0; i < 10; ++i) {
		int data;
		cin >> data;
		dlist.push_back(data);
	}

	cout << "------------------------------------------------------------------------\n";
	cout << "Command linked list\n";
	cout << "[1] - Add an element in front of list\n";
	cout << "[2] - Add an element after the list\n";
	cout << "[3] - Add an element after given element\n";
	cout << "[4] - Delete an element in front of list\n";
	cout << "[5] - Delete an element after the list\n";
	cout << "[6] - Delete given element first occurrence\n";
	cout << "[7] - Print the list from left to right\n";
	cout << "[8] - Print the list from right to left\n";
	cout << "[9] - Find position of element\n";
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
			cout << "Enter the number to add in front of list: ";
			int data1;
			cin >> data1;
			dlist.push_front(data1);
			break;
		case 2:
			cout << "Enter the number to add after the list: ";
			int data2;
			cin >> data2;
			dlist.push_back(data2);
			break;
		case 3:
			cout << "Enter the number to add: ";
			int first, second;
			cin >> first;
			cout << "Enter the number to add new element after this number: ";
			cin >> second;
			dlist.push_mid(first, second);
			break;
		case 4:
			cout << "Element " << dlist.get_first() << " has been removed from list!";
			dlist.pop_front();
			break;
		case 5:
			cout << "Element " << dlist.get_last() << " has been removed from list!";
			dlist.pop_back();
			break;
		case 6:
			int del;
			cout << "Enter the number you want to delete: ";
			cin >> del;
			dlist.pop(del);
			cout << "Element " << del << " has been removed from list!";
			break;
		case 7:
			cout << "Print list fromt left to right: ";
			dlist.printLeftToRight();
			break;
		case 8:
			cout << "Print list from right to left: ";
			dlist.printRightToLeft();
			break;
		case 9:
			int ele;
			cout << "Enter the number you want to find first position occurrence: ";
			cin >> ele;
			dlist.find(ele);
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