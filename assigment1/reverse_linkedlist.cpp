// program to reverse a linkedlist 

#include<iostream>
using namespace std;
struct Node { 
    int data; 
    struct Node* next; 
}; 

void push(Node** head_ref, int new_data) 
{ 
	Node* new_node = new Node(); 
    new_node->data=new_data;
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
}

 Node* reverse(Node* head) 
    { 
        if (head == NULL || head->next == NULL) 
            return head; 
        Node* rest = reverse(head->next); 
        head->next->next = head; 
        head->next = NULL; 
        return rest; 
    } 
  
    void print(Node* head) 
    { 
        struct Node* temp = head; 
        while (temp != NULL) { 
            cout << temp->data << " "; 
            temp = temp->next; 
        } 
        cout<<endl;
       
    } 

int main(){

   Node* head = new Node();
   head-> data=20;
	push(&head, 1); 
	push(&head, 2); 
	push(&head, 3); 
	push(&head, 4); 
print(head);
head=reverse(head);
print(head);
    return 0;
}