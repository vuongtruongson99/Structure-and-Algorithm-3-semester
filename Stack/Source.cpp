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
class Stack {
public:
	Stack() : _pHead(NULL) { ; }

	void push(T val);
	void pop();
	void reverse();
	void print();
	bool isEmpty();
	T get_first();

	NodeData<T> *head() { return _pHead; }

private:
	NodeData<T> *_pHead;
};

template<typename T>
void Stack<T>::push(T val) {
	if (_pHead == NULL) {
		NodeData<T>* tmp = new NodeData<T>();
		tmp->set_data(val);
		_pHead = tmp;
	}
	else {
		NodeData<T>* tmp = new NodeData<T>();
		tmp->set_data(val);
		tmp->set_pNext(_pHead);
		_pHead = tmp;
	}
}

template<typename T>
void Stack<T>::pop() {
	if (_pHead != NULL) {
		NodeData<T>* tmp = _pHead;
		_pHead = _pHead->get_pNext();
		delete tmp;
	}
}

template<typename T>
void Stack<T>::reverse() {
	Stack<T> tmp_stack;
	
	NodeData<T> *current = _pHead;
	while (current != NULL) {
		tmp_stack.push(current->get_data());
		current = current->get_pNext();
	}

	_pHead = tmp_stack.head();
}

template<typename T>
void Stack<T>::print() {
	NodeData<T> *current = _pHead;
	while (current != NULL) {
		cout << current->get_data() << " ";
		current = current->get_pNext();
	}
}

template<typename T>
bool Stack<T>::isEmpty() {
	return (_pHead == NULL);
}

template<typename T>
T Stack<T>::get_first() {
	return _pHead->get_data();
}

int main() {
	Stack<int> s;
	
	cout << "Input element of stack: ";
	for (int i = 0; i < 10; ++i) {
		int element;
		cin >> element;
		s.push(element);
	}

	cout << "1 - Add an element to stack\n";
	cout << "2 - Delete an element from stack\n";
	cout << "3 - Reverse stack\n";
	cout << "4 - Print stack\n";
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
			s.push(element);
			cout << "Element " << element << " has been added to stack!" << endl;
			break;

		case 2:
			cout << "Elelemt " << s.get_first() << " has been removed from stack!" << endl;
			s.pop();
			break;

		case 3:
			s.reverse();
			cout << "Stack has been reversed!" << endl;
			break;

		case 4:
			cout << "Element of stack: ";
			s.print();
			cout << endl;
			break;
		default:
			break;
		}
	} while (n != 0);


	system("pause");
	return 0;
}