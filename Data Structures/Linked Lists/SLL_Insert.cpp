// Implementing a single linked list using structures
// Inserting a node in the linked list
// With different Methods

#include<iostream>
using namespace std; 

typedef struct node{
	int value; 
	node* next; 
} node;

node* getNode(int value){
	node* newNode = new node; 
	newNode->next = NULL; 
	newNode->value = value; 
	
	return newNode; 
}

node* makeSLL(){
	node* arr[10];
	for(int i = 1; i <= 10; ++i){
		arr[i - 1] = getNode(i); 
		if(i >= 2)
			arr[i - 2]->next = arr[i - 1]; 
	}
	return arr[0]; 
}

void print(node *head){
	while(head != NULL){
		cout<<head->value<<" "; 
		head = head->next; 
	}
	cout<<endl; 
}

// Inserting at head
// Type1
// Takes Head Pointer
// Takes a value
// Creates a Node with value
// Adds that node to old head
// Returns the newNode address as new Head
// This method takes O(1) time
node* insertHead_Type1(node* head, int value){
	node* newNode = getNode(value); 
	newNode->next = head; 
	return newNode; 
}

// Inserting at head
// Type2
// Takes reference to Head Pointer
// Takes a value
// Creates a Node with value
// Adds that node to old head
// assigns the newNode as head
// There is no return Type as reference is passed
// This method will be used 
// This method takes O(1) time
void insertHead_Type2(node* &head, int value){
	node* newNode = getNode(value); 
	newNode->next = head; 
	head = newNode;
}


// Inserting at tail
// First we should reach the tail node
// Then simply insert the newNode
// This method takes O(n) time
// This can be optimized by use of "tail" pointer
void insertTail(node* head, int value){
	node* newNode = getNode(value); 
	while(head->next != NULL)
		head = head->next; 
		
	head->next = newNode; 
}

// Inserting at middle location
// Inserting at given possition
// Position can vary from 1 to len(SLL) + 1
void insertPosition(node* &head, int position, int value){
	if(position == 1) {
		insertHead_Type2(head, value); 
		return; 
	}
	
	int currPosition = 1; 
	node* curr = head; 
	node* newNode = getNode(value); 
	while(currPosition < (position - 1)){
		curr = curr->next; 
		++currPosition; 
	}
	newNode->next = curr->next; 
	curr->next = newNode; 
}

int main(){
	node* head = makeSLL(); 
	
	print(head); 
	
	head = insertHead_Type1(head, 0); 
	
	print(head); 
	
	insertHead_Type2(head, -1);
	
	print(head); 
	
	insertTail(head, 11); 
	
	print(head); 
	
	insertPosition(head, 7, -7); 
	
	print(head); 
	
	
	return 0; 
}
