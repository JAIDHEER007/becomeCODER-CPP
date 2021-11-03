#include<iostream>
#include<map>
#define NeedForSpeed ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

// Detecting a cycle in Single Linked List

typedef struct node{
	int value;
	node* next;
} node;

node* getNode(int value){
	node* newNode = new node;
	newNode->value = value;
	newNode->next = NULL;

	return newNode;
}

node* makeSLL(int length){
	if(length == 0) return NULL;
	if(length == 1) return getNode(1);

	node* arr[length];

	for(int i = 1; i <= length; ++i){
		arr[i - 1] = getNode(i);
		if(i >= 2)
			arr[i - 2]->next = arr[i - 1];
	}
	
	return arr[0];
}


node* makeSLL_Cycle(int length){
	if(length == 0) return NULL;
	if(length == 1) return getNode(1);

	node* arr[length];

	for(int i = 1; i <= length; ++i){
		arr[i - 1] = getNode(i);
		if(i >= 2)
			arr[i - 2]->next = arr[i - 1];
	}
	
	
	arr[length - 1]->next = arr[length / 2]; 
	return arr[0];
}

void print(node* head){
	while(head != NULL){
		cout<<head->value<<" ";
		head = head->next;
	}
	cout<<endl;
}

void printCycle(node* head){
	for(int i = 0; i < 25; ++i, head = head->next)
		cout<<head->value<<" "; 
	cout<<endl; 
}

bool hasCycle_Naive(node* head){
	map<node*, bool> hashTable; 
	while(head != NULL){
		if(hashTable[head]) return true;  
		else hashTable[head] = true;
		head = head->next;
	}
	return false; 
}

bool hasCycle_Efficient(node* head){
	node* slow = head; 
	node* fast = head; 
	
	while(slow && fast && fast->next){
		slow = slow->next; 
		fast = fast->next->next; 
		
		if(slow == fast) return true; 
	}
	return false;
}

int main(){
	NeedForSpeed;
	node* head1 = makeSLL_Cycle(10);
	cout<<boolalpha<<hasCycle_Naive(head1)<<endl;
	
	node* head2 = makeSLL(10); 
	cout<<boolalpha<<hasCycle_Naive(head2)<<endl; 
	
	cout<<boolalpha<<hasCycle_Efficient(head1)<<endl; 
	cout<<boolalpha<<hasCycle_Efficient(head2)<<endl; 
	
	return 0;
}

