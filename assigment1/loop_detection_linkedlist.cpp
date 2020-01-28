#include <iostream> 
using namespace std; 

struct  Node { 
    
	int data; 
	Node* next; 
}; 

void push(Node** head_ref, int new_data) 
{ 
	Node* new_node = new Node(); 
	new_node->data = new_data; 
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 

int detectloop(Node* head) 
{ 
	Node *slow_p = head, *fast_p = head; 

	while (slow_p && fast_p && fast_p->next) { 
		slow_p = slow_p->next; 
		fast_p = fast_p->next->next; 
		if (slow_p == fast_p) { 
			return 1; 
		} 
	} 
	return 0; 
} 

int main() 
{
    Node* head = NULL; 
	push(&head, 1); 
	push(&head, 2); 
	push(&head, 3); 
	push(&head, 4); 
	head->next->next->next->next = head; 
	int flag = detectloop(head); 
    if(flag==0)cout<<"NULL TERMINATED \n";
    else cout<<"LOOP FOUND \n";
	return 0; 
} 

