#include <iostream>

using namespace std;

template<typename T>
class NodeData {
public:
	NodeData() : _pNext(NULL) { ; };

	void set_data(T val) {
		_data = val;
	}

	T get_data() { return _data; }

	void set_pNext(NodeData<T> *pNext) {
		_pNext = pNext;
	}

	NodeData<T>* get_pNext() {
		return _pNext;
	}

private:
	T _data;
	NodeData<T> *_pNext;
};

template<typename T>
class Queue {
public:
	Queue() : _pHead(NULL) { ; }

	void push(T val);
	void pop();
	void print();
	T get_first();

	NodeData<T> *head() { return _pHead; }

private:
	NodeData<T> *_pHead;
};

template<typename T>
void Queue<T>::push(T val) {
	if (_pHead == NULL) {
		NodeData<T>* tmp = new NodeData<T>();
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
void Queue<T>::pop() {
	if (_pHead != NULL) {
		NodeData<T>* tmp = _pHead;
		_pHead = _pHead->get_pNext();
		delete tmp;
	}
}

template<typename T>
void Queue<T>::print() {
	NodeData<T> *current = _pHead;
	while (current != NULL) {
		cout << current->get_data() << " ";
		current = current->get_pNext();
	}
}

template<typename T>
T Queue<T>::get_first() {
	return _pHead->get_data();
}

int main() {
	Queue<int> q;

	cout << "Input element of queue: ";
	for (int i = 0; i < 10; ++i) {
		int element;
		cin >> element;
		q.push(element);
	}

	cout << "1 - Add an element to queue\n";
	cout << "2 - Delete an element from queue\n";
	cout << "3 - Print stack\n";
	cout << "0 - Exit\n";

	int n = -1;
	do
	{
		cout << "--------------------------------------\n" << "Input your choice: ";
		cin >> n;
		cout << "\n";
		switch (n)
		{
		case 1:
			cout << "Input an element: ";
			int element;
			cin >> element;
			q.push(element);
			cout << "Element " << element << " has been added to queue!" << endl;
			break;

		case 2:
			cout << "Elelemt " << q.get_first() << " has been removed from stack!" << endl;
			q.pop();
			break;

		case 3:
			cout << "Element of queue: ";
			q.print();
			cout << endl;
			break;
		default:
			break;
		}
	} while (n != 0);


	system("pause");
	return 0;
}


