// Implementing a single linked list using structures
// Deleting a node

#include<iostream>
using namespace std; 

typedef struct node{
	int value; 
	node* next; 
}node;

node* getNode(int value){
	node* newNode = new node; 
	newNode->value = value; 
	newNode->next = NULL; 
	
	return newNode; 
}

void print(node* head){
	while(head != NULL){
		cout<<head->value<<" "; 
		head = head->next; 
	}
	cout<<endl; 
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

void deleteHead(node* &head){
	node* temp = head; 
	head = head->next;
	delete(temp); 
}

void deleteTail(node* head){
	if(head == NULL) return; 
	if(head->next == NULL){		//Single Node
		delete(head); 
		head = NULL; 
		return; 
	}
	while(head->next->next != NULL)
		head = head->next; 
		
	delete(head->next); 
	head->next = NULL; 
}

void deletePosition(node* &head, int position){
	if(position == 1){
		deleteHead(head); 
		return; 
	}
	int currPosition = 1; 
	node* curr = head; 
	while(currPosition < (position - 1)){
		curr = curr->next; 
		++currPosition; 
	}
	node* temp = curr->next; 
	curr->next = temp->next; 
	delete(temp); 
}

int main(){
	node* head = makeSLL(); 
	
	print(head); 
	
	deleteHead(head); 
	
	print(head); 
	
	deleteTail(head); 
	
	print(head); 
	
	deletePosition(head, 5); 
	
	print(head); 
	
	return 0; 
}
