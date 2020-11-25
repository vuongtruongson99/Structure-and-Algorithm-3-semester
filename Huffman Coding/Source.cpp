#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Huffman tree node
struct MinHeapNode
{
	char data;
	int freq;
	struct MinHeapNode *left, *right;
};

// Huffman tree: collection of node
struct MinHeap
{
	int size;
	int capacity;
	struct MinHeapNode** array;
};

// Create new node
struct MinHeapNode* newNode(char data, int freq) {
	struct MinHeapNode* tmp = new MinHeapNode[1];
	tmp->data = data;
	tmp->freq = freq;
	tmp->left = NULL;
	tmp->right = NULL;

	return tmp;
}

// Create min heap of given capacity
struct MinHeap* createMinHeap(int capacity) {
	struct MinHeap* tmp = new MinHeap[1];
	tmp->size = 0;
	tmp->capacity = capacity;
	tmp->array = new MinHeapNode*[capacity];

	return tmp;
}

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
	struct MinHeapNode *tmp = *a;
	*a = *b;
	*b = tmp;
}

// Heapify function
void minHeapify(struct MinHeap* minHeap, int ind) {
	int smallest = ind;
	int left = 2 * ind + 1;
	int right = 2 * ind + 2;

	if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq) {
		smallest = left;
	}

	if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq) {
		smallest = right;
	}

	if (smallest != ind) {
		swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[ind]);
		minHeapify(minHeap, smallest);
	}
}

int isSizeOne(struct MinHeap* minHeap) {
	return (minHeap->size == 1);
}

// Get minimum value from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
	struct MinHeapNode* tmp = minHeap->array[0];
	minHeap->array[0] = minHeap->array[minHeap->size - 1];
	minHeap->size -= 1;
	minHeapify(minHeap, 0);

	return tmp;
}

// Insert node to min heap
void insertNode(struct MinHeap* minHeap, struct MinHeapNode* node) {
	minHeap->size += 1;
	int i = minHeap->size - 1;

	while (i && node->freq < minHeap->array[(i - 1) / 2]->freq) {
		minHeap->array[i] = minHeap->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	minHeap->array[i] = node;
}

void buildMinHeap(struct MinHeap* minHeap) {
	int n = minHeap->size - 1;
	int i;

	for (i = (n - 1) / 2; i >= 0; --i)
		minHeapify(minHeap, i);
}

int isLeaf(struct MinHeapNode* node) {
	return !node->left && !node->right;
}

struct MinHeap* createAndBuildMinHeap(vector<char> data, vector<int> freq, int size) {
	struct MinHeap* minHeap = createMinHeap(size);

	for (int i = 0; i < size; ++i)
		minHeap->array[i] = newNode(data[i], freq[i]);

	minHeap->size = size;
	buildMinHeap(minHeap);

	return minHeap;
}

struct MinHeapNode* buildHuffmanTree(vector<char> data, vector<int> freq, int size) {
	struct MinHeapNode *left, *right, *top;
	struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

	while (!isSizeOne(minHeap)) {
		left = extractMin(minHeap);
		right = extractMin(minHeap);

		top = newNode('$', left->freq + right->freq);

		top->left = left;
		top->right = right;

		insertNode(minHeap, top);
	}

	return extractMin(minHeap);
}

vector<pair<char, string>> result;

void printArr(int arr[], int n, char x) {
	int i;
	string s;
	for (i = 0; i < n; ++i) {
		cout << arr[i];
		s += to_string(arr[i]);
	}
	result.push_back(make_pair(x, s));
	cout << "\n";
}

void printCodes(struct MinHeapNode* root, int arr[], int top) {
	if (root->left) {
		arr[top] = 0;
		printCodes(root->left, arr, top + 1);
	}

	if (root->right) {
		arr[top] = 1;
		printCodes(root->right, arr, top + 1);
	}

	if (isLeaf(root)) {
		cout << root->data << "\t\t";
		printArr(arr, top, root->data);
	}
}

void HuffmanCodes(vector<char> data, vector<int> freq, int size) {

	struct MinHeapNode* root
		= buildHuffmanTree(data, freq, size);

	int arr[100], top = 0;

	printCodes(root, arr, top);
}

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
	return (a.second > b.second);
}

void printTabFreq(vector<char> arr, vector<int> freq) {
	vector<pair<char, int>> tab_freq;
	for (int i = 0; i < arr.size(); ++i) {
		tab_freq.push_back(make_pair(arr[i], freq[i]));
	}

	sort(tab_freq.begin(), tab_freq.end(), sortbysec);

	for (auto x : tab_freq) {
		cout << x.first << "\t\t" << x.second << endl;
	}
}

int main() {
	string name;
	cout << "Input your name: ";
	getline(cin, name);

	int tempFreq[128];
	for (int i = 0; i < 128; ++i) {
		tempFreq[i] = 0;
	}

	for (int i = 0; i < name.length(); ++i) {
		tempFreq[name[i] - 0]++;
	}

	vector<char> arr;
	vector<int> freq;

	for (int i = 0; i < name.length(); ++i) {
		if (tempFreq[name[i] - 0] != 0) {
			arr.push_back(name[i]);
			freq.push_back(tempFreq[name[i] - 0]);

			tempFreq[name[i] - 0] = 0;
		}

	}
	int size = arr.size();

	cout << "-----------------------Menu-----------------------\n";
	cout << "[1] - Print frequency table\n";
	cout << "[2] - Print character codes\n";
	cout << "[3] - Print string after encoded with Huffman coding\n";
	cout << "[0] - Exit program\n";
	cout << "--------------------------------------------------\n";

	int choice = 0;
	do
	{
		cout << "\n";
		cout << "Input your choice: ";
		cin >> choice;

		cout << "--------------------------------------------------\n";
		switch (choice)
		{
		case 1:
			cout << "Frequency table: \n";
			cout << "Character\tFrequency\n";
			printTabFreq(arr, freq);
			break;
		case 2:
			cout << "Character codes: \n";
			cout << "Character\tCode\n";
			HuffmanCodes(arr, freq, size);
			break;
		case 3:
			cout << "Encoded with Huffman coding: ";
			for (int i = 0; i < name.length(); ++i) {
				for (auto x : result) {
					if (name[i] == x.first) {
						cout << x.second;
						break;
					}
				}
			}
			cout << endl;
			break;
		case 0:
			cout << "Thanks for using!\n";
			break;
		default:
			break;
		}
		cout << "--------------------------------------------------\n";

	} while (choice != 0);


	system("pause");
	return 0;
}