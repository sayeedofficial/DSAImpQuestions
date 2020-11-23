#include <iostream>
using namespace std;


template<typename T>

class Node {
public:
	T data;
	Node *left, *right;


	Node(T data) {
		this->data = data;
		left = right = NULL;
	}
	

	Node *insert(Node *root, T key) {
		if (root == NULL)
			return new Node(key);
		else if (key > root->data)
			root->right = insert(root->right, key);
		else if (key < root->data)
			root->left = insert(root->left, key);

		return root;
	}

	void inorder(Node *root) {
		if (root == NULL)
			return ;

		cout << root->data << " ";
		inorder(root->left);
		inorder(root->right);
	}

	bool search(Node *root, T key) {
		if (root == NULL)
			return false;
		if (root->data == key)
			return true;
		if (key < root->data)
			return search(root->left, key);
		if (key > root->data)
			return search(root->right, key);
	}

	// Node *delete(Node *root, T key) {
	// 	if (root == NULL)
	// 		return root;
	// 	if (key > root->data)
	// 		root->right = delete(root->right, key);
	// 	else if (key < root->data)
	// 		root->left = delete(root->left, key);
	// 	else {
	// 		if (root->left == NULL && root->right == NULL) {
	// 			delete node;
	// 			return NULL;
	// 		}
	// 		else if (root->right == NULL) {
	// 			Node *temp = root->left;
	// 			root->left = NULL;
	// 			delete root;
	// 			return temp;
	// 		}
	// 		else if (root->left == NULL) {
	// 			Node *temp = root - right;
	// 			root->right = NULL;
	// 			delete root;
	// 			return temp;
	// 		}
	// 		else {

	// 		}
	// 	}

	// }

	int height(Node *start) {

		if (start == NULL) return 0;

		return 1 + max(height(start->left), height(start->right));

	}

	int size(Node *root) {
		if (root == NULL)
			return 0;
		return 1 + size(root->left) + size(root->right);
	}

	bool checkCSP(Node *root) {
		if (root == NULL) return true;

		if (root->left == NULL && root->right == NULL)
			return true;

		int sum  = 0;
		if (root->left != NULL)
			sum += root->left->data;
		if (root->right != NULL)
			sum += root->right->data;

		return (root->data == sum && checkCSP(root->left) && checkCSP(root->right));

	}




};







int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Node<int> *tree1 = new Node<int>(20);
	tree1 = tree1->insert(tree1, 8);
	tree1 = tree1->insert(tree1,12);
	tree1 = tree1->insert(tree1, 3);
	tree1 = tree1->insert(tree1, 9);

	// cout << "\nHeight is " << (tree1->height(tree1));
	// cout << "\nSize is " << (tree1->size(tree1));

	tree1->checkCSP(tree1) ? cout<<"\nYES IT IS" : cout<<"\nNOT!";
	




	return 0;


}