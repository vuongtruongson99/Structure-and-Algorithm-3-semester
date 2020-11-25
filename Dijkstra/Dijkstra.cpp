#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define Y 8

int min_dist(int dist[], bool shortest_dist[]) {
	int min = INT_MAX, min_ind;
	for (int i = 0; i < Y; ++i) {
		if (shortest_dist[i] == false && dist[i] <= min) {
			min = dist[i];
			min_ind = i;
		}
	}
	return min_ind;
}

vector<int> result{ 2, 5, 1, 7};

void printPath(int parent[], int j) {
	if (parent[j] == -1) {
		return;
	}
	printPath(parent, parent[j]);
	result.push_back(j + 1);
}

void printAll(int dist[], int n, int parent[], int src) {
	cout << "Vertex\t Distance\t Path";
	for (int i = 1; i < n; ++i) {
		cout << "\n" << src + 1 << " -> " << i + 1 << "\t" << dist[i] << "\t\t" << src + 1;
		printPath(parent, i);
	}
}

void dijkstra(int adj[][Y], int start) {
	// Distance form start node to i-th node store in dist[i]
	int dist[Y];
	bool shortest_dist[Y];
	int parent[Y];

	for (int i = 0; i < Y; ++i) {
		dist[i] = INT_MAX;
		shortest_dist[i] = false;
		parent[0] = -1;
	}

	dist[start] = 0;
	
	for (int i = 0; i < Y - 1; ++i) {
		int u = min_dist(dist, shortest_dist);
		shortest_dist[u] = true;
		for (int v = 0; v < Y; ++v) {
			if (!shortest_dist[v] && adj[u][v] && dist[u] + adj[u][v] < dist[v]) {
				dist[v] = dist[u] + adj[u][v];
				parent[v] = u;
			}
		}
	}
	result.push_back(start + 1);
	printPath(parent, 6);
}

struct Node {
	int data;
	Node* left, *right;
};

Node* newNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

Node* insertLevelOrder(vector<int> arr, Node* root, int i, int n) {
	if (i < n) {
		Node* temp = newNode(arr[i]);
		root = temp;
		root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);

		root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
	}
	return root;
}

void printTree(Node *s, int level) {
	if (s) {
		printTree(s->left, level + 1);
		for (int i = 0; i < level; ++i) cout << "    ";
		cout << s->data << endl;
		printTree(s->right, level + 1);
	}
}

int main() {
	int N, M;
	cout << "Input number of vertices: ";
	cin >> N;
	cout << "Input number of edges: ";
	cin >> M;

	int adj[Y][Y];
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			adj[i][j] = 0;
		}
	}

	cout << "Input each edges of graph [start_node end_node weight]:\n";
	for (int i = 0; i < M; ++i) {
		int start, end, weight;
		cin >> start >> end >> weight;
		start--, end--;
		adj[start][end] = weight;
	}

	//dijkstra(adj, 0);
	cout << "\n";
	

	cout << "Shortest path tree at 1 to 7: " << endl;
	Node* root = NULL;
	root = insertLevelOrder(result, root, 0, result.size());
	printTree(root, 0);

	system("pause");
	return 0;
}

//1 2 23
//1 3 12
//2 3 25
//3 4 18
//2 5 22
//2 8 35
//4 6 20
//5 6 23
//5 7 14
//6 7 24
//7 8 16