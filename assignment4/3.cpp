#include <bits/stdc++.h> 
  
using namespace std; 
  
struct Node { 
    char data; 
    Node *left, *right; 
}; 
  
Node* newNode(char data); 
  
int search(char arr[], int strt, int end, char value); 

Node* buildUtil(char in[], char post[], int inStrt, 
                int inEnd, int* pIndex) 
{ 
    if (inStrt > inEnd) 
        return NULL; 
  
    Node* node = newNode(post[*pIndex]); 
    (*pIndex)--; 
  
    if (inStrt == inEnd) 
        return node; 

    int iIndex = search(in, inStrt, inEnd, node->data); 
  

    node->right = buildUtil(in, post, iIndex + 1, inEnd, pIndex); 
    node->left = buildUtil(in, post, inStrt, iIndex - 1, pIndex); 
  
    return node; 
} 

Node* buildTree(char in[], char post[], int n) 
{ 
    int pIndex = n - 1; 
    return buildUtil(in, post, 0, n - 1, &pIndex); 
} 

int search(char arr[], char strt, int end, char value) 
{ 
    int i = 0; 
    for (i = strt; i <= end; i++) { 
        if (arr[i] == value) 
            return i;
    } 
    return -1; 
} 
  
Node* newNode(char data) 
{ 
    Node* node = (Node*)malloc(sizeof(Node)); 
    node->data = data; 
    node->left = node->right = NULL; 
    return (node); 
} 
  
void preOrder(Node* node) 
{ 
    if (node == NULL) 
        return; 
    printf("%c ", node->data); 
    preOrder(node->left); 
    preOrder(node->right); 
} 
  
int main() 
{ 
    char in[]   = {'E','A','C','K','F','H','D','B','G'}; 
    char post[] = {'E','C','K','A','H','B','G','D','F'}; 
    int n = sizeof(in) / sizeof(in[0]); 
  
    Node* root = buildTree(in, post, n); 
  
    cout << "Preorder of the constructed tree : \n"; 
    preOrder(root); 
  
    return 0; 
} 
