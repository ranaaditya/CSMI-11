
#include <bits/stdc++.h> 
using namespace std; 


struct node 
{ 
	int data; 
	struct node* left; 
	struct node* right; 
}; 


unsigned int getLeafCount(struct node* node) 
{ 
	if(node == NULL)	 
		return 0; 
	if(node->left == NULL && node->right == NULL) 
		return 1;		 
	else
		return getLeafCount(node->left)+ 
			getLeafCount(node->right); 
} 

struct node* newNode(int data) 
{ 
	struct node* node = (struct node*) 
					malloc(sizeof(struct node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 
	
return(node); 
} 

int maxElement(node* root) {
	if (root == NULL)  
    return INT_MIN;  
  
    // Return maximum of 3 values:  
    // 1) Root's data 2) Max in Left Subtree  
    // 3) Max in right subtree  
    int res = root->data;  
    int lres = maxElement(root->left);  
    int rres = maxElement(root->right);  
    if (lres > res)  
    res = lres;  
    if (rres > res)  
    res = rres;  
    return res;
}

int sumtree(node* root) 
{ 
    if (root == NULL) 
        return 0; 
    return (root->data + sumtree(root->left) + sumtree(root->right)); 
} 

int size(node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
        return(size(node->left) + 1 + size(node->right));  
} 


int height(node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        /* compute the depth of each subtree */
        int lDepth = height(node->left);  
        int rDepth = height(node->right);  
      
        /* use the larger oneght */
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
}


int main() 
{ 
	struct node *root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	
cout << "Leaf count of the tree is : " << getLeafCount(root) << endl; 
cout << "Max element in tree is :" << maxElement(root) << endl;
cout << "sum of all elements of trees is :" << sumtree(root) << endl;
cout << "size of tree is :" << size(root) << endl;
cout << "Height of tree is :" << height(root);

return 0; 

} 
