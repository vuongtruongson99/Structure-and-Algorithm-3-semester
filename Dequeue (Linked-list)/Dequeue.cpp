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
class Dequeue {
public:
	Dequeue() : _pHead(NULL) { ; }

	void push_front(T val);
	void push_back(T val);
	void pop_front();
	void pop_back();
	void print();
	T get_first();
	T get_last();

private:
	NodeData<T> *_pHead;
};

template<typename T>
void Dequeue<T>::push_front(T val) {
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
void Dequeue<T>::push_back(T val) {
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
void Dequeue<T>::pop_front() {
	if (_pHead != NULL) {
		NodeData<T> *tmp = _pHead;
		_pHead = _pHead->get_pNext();
		delete tmp;
	}
}

template<typename T>
void Dequeue<T>::pop_back() {
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
void Dequeue<T>::print() {
	NodeData<T> *tmp = _pHead;
	while (tmp != NULL) {
		cout << tmp->get_data() << " ";
		tmp = tmp->get_pNext();
	}
}


template<typename T>
T Dequeue<T>::get_first() {
	return _pHead->get_data();
}

template<typename T>
T Dequeue<T>::get_last() {
	NodeData<T> *current = _pHead;

	while (current->get_pNext() != NULL) {
		current = current->get_pNext();
	}

	return current->get_data();
}

int main() {
	Dequeue<int> dq;

	cout << "Input element of dequeue: ";
	for (int i = 0; i < 10; ++i) {
		int element;
		cin >> element;
		dq.push_back(element);
	}

	cout << "1 - Add an element in front of dequeue\n";
	cout << "2 - Add an element after the dequeue\n";
	cout << "3 - Delete an element in front of dequeue\n";
	cout << "4 - Delete the last element of dequeue\n";
	cout << "5 - Print dequeue\n";
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
			dq.push_front(element);
			cout << "Element " << element << " has been added in front of dequeue!" << endl;
			break;

		case 2:
			cout << "Input an element: ";
			cin >> element;
			dq.push_back(element);
			cout << "Element " << element << " has been added after the dequeue!" << endl;
			break;

		case 3:
			cout << "First element " << dq.get_first() << " of dequeue has been removed!" << endl;
			dq.pop_front();
			break;

		case 4:
			cout << "Last element " << dq.get_last() << " of dequeue has been removed!" << endl;
			dq.pop_back();
			break;

		case 5:
			cout << "Element of dequeue: ";
			dq.print();
			cout << endl;
			break;
		default:
			break;
		}
	} while (n != 0);


	system("pause");
	return 0;
}