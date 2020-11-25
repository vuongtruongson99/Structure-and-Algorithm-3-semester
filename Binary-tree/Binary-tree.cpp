#include<iostream>
using namespace std;

struct Node {
	int data;
	Node *left;
	Node *right;
};

Node *newNode(int data) {
	struct Node *tmp = new Node();
	tmp->data = data;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

Node *insertNode(Node *root, int data) {
	if (root == NULL)
		return newNode(data);

	/* Otherwise, recur down the tree */
	if (data < root->data)
		root->left = insertNode(root->left, data);
	else
		root->right = insertNode(root->right, data);

	/* return the (unchanged) node pointer */
	return root;
}

int height(Node *node) {
	if (node == NULL) {
		return 0;
	}
	else {
		int left, right;
		left = height(node->left);
		right = height(node->right);
		if (left > right) {
			return left + 1;
		}
		else {
			return right + 1;
		}
	}
}

int numberOfNode(Node *node) {
	int count = 1;
	if (node == NULL) {
		return 0;
	}
	else {
		count += numberOfNode(node->left);
		count += numberOfNode(node->right);
	}
	return count;
}

void printNode(Node *node) {
	if (node == NULL) {
		return;
	}
	else {
		if (height(node->left) != height(node->right) && numberOfNode(node->left) == numberOfNode(node->right)) {
			cout << node->data << " ";
		}
		else {
			printNode(node->left);
			printNode(node->right);
		}
	}
}


Node* deleteNode(Node* root, int data) {
	if (root == NULL) {
		return root;
	}
	
	if (data > root->data) {
		root->right = deleteNode(root->right, data);
		return root;
	}
	else if (data < root->data) {
		root->left = deleteNode(root->left, data);
		return root;
	}
	else {
		if (root->left == NULL) {
			Node *tmp = root->right;
			delete root;
			return tmp;
		}
		else if (root->right == NULL) {
			Node *tmp = root->left;
			delete root;
			return tmp;
		}

		Node *tmp = root->right;
		while (tmp && tmp->left != NULL) {
			tmp = tmp->left;
		}

		root->data = tmp->data;
		root->right = deleteNode(root->right, tmp->data);

		return root;
	}
}

void printTree(Node *root, int level) {
	if (root) {
		printTree(root->right, level + 1);
		for (int i = 0; i < level; ++i) cout << "    ";
		cout << root->data << endl;
		printTree(root->left, level + 1);
	}
}

int main() {
	Node *root = NULL;
	
	cout << "-------------------Menu-------------------\n";
	cout << "[1] - Insert a node.\n";
	cout << "[2] - Delete a node.\n";
	cout << "[3] - Print a tree.\n";
	cout << "[0] - Exit program!\n";
	cout << "------------------------------------------\n";

	int choice = 0;
	do
	{
		cout << "Input your choice: ";
		cin >> choice;

		cout << "\n---------------------------------------\n";
		switch (choice)
		{
		case 1:
			cout << "Enter size of tree: ";
			int n;
			cin >> n;
			cout << "Enter the data to insert into the tree: ";
			for (int i = 0; i < n; ++i) {
				int data;
				cin >> data;
				root = insertNode(root, data);
			}
			cout << "Done!";
			break;
		case 2:
			int data;
			cout << "Enter the data to delete from the tree: ";
			cin >> data;
			root = deleteNode(root, data);
			cout << data << " has been removed from the tree!";
			break;
		case 3:
			cout << "Tree: \n";
			printTree(root, 0);
			break;
		case 0:
			cout << "Thanks for using program!";
			break;
		default:
			break;
		}
		cout << "\n---------------------------------------\n";
	} while (choice != 0);

	system("pause");
	return 0;
}