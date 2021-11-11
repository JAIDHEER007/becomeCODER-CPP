// LRU Cache using DLL

#include<iostream>
#include<unordered_map>
using namespace std; 

typedef struct node{
	int key; 
	int value; 
	node* next; 
	node* prev; 
	
	node(int _key = 0, int _value = 0){
		key = _key; 
		value = _value; 
		next = NULL; 
		prev = NULL; 
	}
} node;

class LRU{
	private:
		int capacity; 
		int size; 
		
		node* head; 
		node* tail; 
		
		unordered_map<int, node*> table; 
		
	public:

		LRU(int capacity){
			this->capacity = capacity; 
			size = 0; 
			head = NULL; 
			tail = NULL; 
		}
		
		
		// DLL Managing Functions
		void pushBack(int, int); 
		void remove(node*); 
		void printVerify(); 
		
		// LRU Functions
		void put(int, int); 
		int get(int); 
				
};

void LRU::pushBack(int key, int value){
	node* newNode = new node(key, value); 
	table[key] = newNode; 
	++size; 
	
	if((head == tail) && (tail == NULL))
		head = tail = newNode; 
	else{
		newNode->prev = tail; 
		tail->next = newNode; 
		tail = newNode; 
	}
}

void LRU::remove(node* address){
	table[address->key] = NULL; 
	--size; 
	
	if((head == tail) && (head == address))	// DLL Contains single Node
		head = tail = NULL; 
	if(address == head){	// Head Node
		head->next->prev = NULL; 
		head = head->next;  
		address->next = NULL; 
	}else if(address == tail){	// Tail Node
		tail->prev->next = NULL; 
		tail = tail->prev;
		address->prev = NULL;  
	}else{
		node* nextNode = address->next; 
		node* prevNode = address->prev; 
		
		prevNode->next = nextNode; 
		nextNode->prev = prevNode; 
	}
	
	delete(address); 
}

void LRU::printVerify(){
	// Debugging Function
	cout<<"Size: "<<size<<endl; 
	node* curr = head; 
	while(curr != NULL){
		cout<<"("<<(curr->key)<<" "<<(curr->value)<<")"<<"  "; 
		curr = curr->next; 
	}cout<<endl; 
	
	curr = tail; 
	while(curr != NULL){
		cout<<"("<<(curr->key)<<" "<<(curr->value)<<")"<<"  "; 
		curr = curr->prev; 
	}cout<<endl; 
}

void LRU::put(int key, int value){
	// Check if the key already exist
	if(table[key] != NULL)
            remove(table[key]); 
    else if(size >= capacity) remove(head); 
    pushBack(key, value); 
}

int LRU::get(int key){
	if(table[key] == NULL) return -1; 
	
	node* address = table[key]; 
	int value = address->value; 
	remove(address); 
	pushBack(key, value); 
	return value; 	
}

int main(){
	LRU test(2); 
	test.put(1, 1); 
	test.put(2, 2); 
	cout<<test.get(1)<<endl; 
	test.put(3, 3); 
	cout<<test.get(2)<<endl; 
	test.put(4, 4); 
	cout<<test.get(1)<<endl;
	cout<<test.get(3)<<endl;
	cout<<test.get(4)<<endl; 
	
	return 0; 
}
