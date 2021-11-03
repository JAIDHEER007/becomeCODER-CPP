// Implementing a single linked list using structures
// reversing a linked list

#include<iostream>
using namespace std; 

typedef struct node{
	int value; 
	node* next; 
	
}node;

// Function to create a node with value in it
node* getNode(int value = 0){
	node* newNode = new node; 
	newNode->next = NULL; 
	newNode->value = value; 
	
	return newNode; 
}

// Function to Print SLL
void print(node* head){
	while(head != NULL){
		cout<<(head->value)<<" "; 
		head = head->next; 
	}
	cout<<endl; 
}

node* makeSLL(int length){
	if(length == 0) return NULL; 
	if(length == 1) return getNode(1); 
	
	node* arr[length];
	for(int i = 1; i <= length; i++){
		arr[i - 1] = getNode(i); 
		if(i >= 2)
			arr[i - 2]->next = arr[i - 1]; 
	}
	return arr[0]; 
}

void reverseLinkedList(node* &head){
	node* a = NULL; 
	node* b = head; 
	node* c = NULL; 
	
	while(b != NULL){
		c = b->next; 
		b->next=a; 
		a = b; 
		b = c; 
	}
	head = a; 
}

int main(){
	node* head = makeSLL(0); 
	
	print(head); 
	
	reverseLinkedList(head); 
	
	print(head); 
	
	head = makeSLL(1); 
	
	print(head); 
	
	reverseLinkedList(head); 
	
	print(head); 
	
	head = makeSLL(2); 
	
	print(head); 
	
	reverseLinkedList(head); 
	
	print(head); 
	
	head = makeSLL(7); 
	
	print(head); 
	
	reverseLinkedList(head); 
	
	print(head); 
	
	head = makeSLL(10); 
	
	print(head); 
	
	reverseLinkedList(head); 
	
	print(head); 
	
	
	return 0; 
}
