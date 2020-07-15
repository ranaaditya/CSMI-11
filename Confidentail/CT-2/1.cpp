/**
 * @author ranaaditya aka Aditya Rana 
 */
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

Node* newNode(int key)
{
	Node* node = new Node;
	node->data = key;
	node->left = node->right = nullptr;

	return node;
}

void inorder(Node *root)
{
	if (root == nullptr)
		return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

// Helper function to find minimum value node in subtree rooted at curr
Node* minimumKey(Node* curr)
{
	while (curr->left != nullptr) {
		curr = curr->left;
	}
	return curr;
}

// Recursive function to insert a key into BST
Node* insert(Node* root, int key)
{

	if (root == nullptr)
		return newNode(key);

	if (key < root->data)
		root->left = insert(root->left, key);

	else
		root->right = insert(root->right, key);

	return root;
}

// Iterative function to search in subtree rooted at curr & set its parent
// Note that curr & parent are passed by reference
void searchKey(Node* &curr, int key, Node* &parent)
{
	while (curr != nullptr && curr->data != key)
	{
		parent = curr;

		if (key < curr->data)
			curr = curr->left;
		else
			curr = curr->right;
	}
}

// Function to delete node from a BST
void deleteNode(Node*& root, int key)
{
	Node* parent = nullptr;

	Node* curr = root;

	searchKey(curr, key, parent);

	if (curr == nullptr)
		return;

	if (curr->left == nullptr && curr->right == nullptr)
	{
		if (curr != root)
		{
			if (parent->left == curr)
				parent->left = nullptr;
			else
				parent->right = nullptr;
		}
		else
			root = nullptr;


		free(curr);	 
	}


	else if (curr->left && curr->right)
	{
		Node* successor  = minimumKey(curr->right);

		int val = successor->data;

		deleteNode(root, successor->data);

		curr->data = val;
	}

	else
	{
		Node* child = (curr->left)? curr->left: curr->right;

		if (curr != root)
		{
			if (curr == parent->left)
				parent->left = child;
			else
				parent->right = child;
		}

		else
			root = child;

		free(curr);
	}
}


bool ifNodeExists(struct Node* node, int key) 
{ 
    if (node == NULL) 
        return false; 
  
    if (node->data == key) 
        return true; 
  
    /* then recur on left sutree */
    bool res1 = ifNodeExists(node->left, key); 
  
    if(res1) return true; // node found, no need to look further 
  
    /* node is not found in left, so recur on right subtree */
    bool res2 = ifNodeExists(node->right, key); 
  
    return res2; 
} 

int main()
{
	Node* root = nullptr;
	int keys[] = { 7, 8, 2, 5, 11, 19, 4, 10, 6, 13, 9, 12, 14, 3 };

	for (int key : keys)
		root = insert(root, key);

    inorder(root);
    cout << "\n";

    // part 1. insert -> 15.
    insert(root,15);

    // part 2. search -> 13.
    cout << ifNodeExists(root,13) << endl; 

    // part 3. delete -> 9.
    deleteNode(root,9);

    inorder(root);
    cout << "\n";

    // print the BST.
    inorder(root);
    cout << "\n";

    // part 4. delete -> 2.
    deleteNode(root,2);

    // print the  BST.
	inorder(root);
    cout << "\n";

	return 0;
}
