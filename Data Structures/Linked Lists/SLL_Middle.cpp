#include<iostream>
#define NeedForSpeed ios_base::sync_with_stdio(false); cin.tie(NULL);

// 876. Middle of the Linked List
// Finding the middle of Linked List

using namespace std;

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

void print(node* head){
	while(head != NULL){
		cout<<head->value<<" ";
		head = head->next;
	}
	cout<<endl;
}

int lengthSLL(node* head){
	int length = 0; 
	while(head != NULL){
		head = head->next; 
		++length;
	}
	return length; 
}

node* middleNaive(node* head){
	int length = lengthSLL(head); 
	int middle = length / 2; 
	
	for(int i = 1; i <= middle; i++)
		head = head->next; 
		
	return head; 
}

// a - slow pointer, 1 step at a time
// b - fast pointer, 2 steps at a time

// When 'b' beomes null (even Length) or 'b->next' becomes null (odd length)
// 'a' reaches the middle node
node* middleEfficient(node* head){
	if(head == NULL) return head; 
	node* a = head; 
	node* b = head; 
	
	while(b != NULL && b->next != NULL){
		a = a->next; 
		b = b->next->next; 
	} 
	return a; 
}

int main(){
	NeedForSpeed;
	node* head = makeSLL(5);
	print(head);
	
	
	node* middle1 = middleNaive(head); 
	cout<<middle1->value<<endl; 
	
	node* middle2 = middleEfficient(head); 
	cout<<middle2->value<<endl;
	
	return 0;
}

