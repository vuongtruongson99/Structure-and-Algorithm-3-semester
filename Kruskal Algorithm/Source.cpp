#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int NAX = 100000;

struct Edge {
	int u, v, weight;
	int id;

	void read() {
		cin >> u >> v >> weight;
	}

	bool operator < (Edge const& other) {
		return weight < other.weight;
	}
};

int num_edges, num_vertices;
int cost = 0;
Edge es[NAX];
vector<Edge> result;
int tree_id[NAX];

void kruskal() {
	for (int i = 1; i <= num_vertices; ++i) {
		tree_id[i] = i;
	}

	sort(es, es + num_edges);

	for (Edge e : es) {
		if (tree_id[e.u] != tree_id[e.v]) {
			cost += e.weight;
			result.push_back(e);

			int old_id = tree_id[e.u], new_id = tree_id[e.v];
			for (int i = 0; i < num_vertices; ++i) {
				if (tree_id[i] == old_id) {
					tree_id[i] = new_id;
				}
			}
		}
	}
}

int main() {
	cout << "Input number of vertices: ";
	cin >> num_vertices;
	cout << "Input number of edges: ";
	cin >> num_edges;

	cout << "Input a graph [start_node end_node weight]: " << endl;
	for (int i = 0; i < num_edges; ++i) {
		es[i].read(); 
	}
	
	kruskal();

	cout << "Minimum spanning tree: " << endl;
	for (Edge e : result) {
		cout << e.u << " -> " << e.v << endl;
	}
	system("pause");
	return 0;
}
