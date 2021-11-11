# Least Recently Used (LRU) Cache
### <a href='https://leetcode.com/problems/lru-cache/'>Link to LeetCode</a>

## Working
A **Least Recently Used** (LRU) Cache organizes items in order of use, <br>allowing you to quickly identify which item hasn't been used for the longest amount of time.<br>
* If a new element is added, then it is made as **Most Recently Used** element. 
* If an already existing element is accessed, then it becomes the **Most Recently Used** element. 
* If a new element should be added but the cache is **full**, then the **Least Recently Used** element will be removed and step1 is executed. 
<br>

LRU cache will be implemented by the use of **Double Linked List** and **Hash Map**.<br>
* We require *O(1)* time complexity for **insertion** and **deletion**. 
  * We cannot do it with an array or a vector, So Linked List is advised. 
    * Double Linked List is chosen because we can delete middle elements without the address of previous node.
* For accessing elements in *O(1)* time complexity, we use a **Hash Map** to store address. 

## Implementation

* This is implemented using Class in C++
* We will take a Double Linked List and Hash Map that stores key and address of the coressponding node. 
* We will maintain `size` and `capacity` variables. 
  * `capacity` holds the capacity of LRU cache and id initialized at the start.
  * `size` will be changed based on the operations done. It will **never** exceed `capacity`.
* We will maintain `head` and `tail` pointers to work with list.
  * LRU nodes are added to Head.
  * MRU nodes are added to Tail.  

## Implementing Double Linked List

### Node Structure
Node of the Double Linked List is implemented using structures.<br>
It contains key, value, next pointer and previous pointer. 

```cpp
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
```

### Inserting at Tail
A new node or recently accessed node is inserted at tail. <br>
If we want the MRU element we will simply return the element at Tail. 
In this way, if we insert at tail automatically the elements at head become LRU elements. 

**Steps:**<br>
* create a new node with key, value pairs. Let the new node address be stored in `newNode`.
* now update the hash map of `key` to `newNode`. 
* Increment the `size` by 1.
* If both head and tail are NULL
  * Then the Linked List is empty.
  * Simply make `head` and `tail` as `newNode`. 
  * Return
* In this case the Linked List is not empty, So we have to insert at the tail
  * assign `tail` to previous pointer of `newNode`. 
  * assign `newNode` to next pointer of `tail`.
  * make `newNode` as `tail`. 

```cpp
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
```

### Deleting a node in Linked List
* If the Cache is full, new elements are addedd by **deleting** the LRU element.
* If an element is accessed it is made into MRU element.
  * **Delete** the element in the Linked List. 
  * Add the same element to tail to make it MRU element. 
* Deleting a node is done by providing address to the function. 
* The address is stored in the hash table. 


**Steps: **<br>
* Update key in hash table. Set it to NULL. The key value can be accessed by the key feild in the address. 
* Decrement the size by one. 
* if the Linked List contains a single element. 
  * Set the `head` and `tail` to NULL. 
* If the address provided is `head`. 
  * Make next node as `head`
* If the address provided is `tail`.
  * Make previous node as `tail`.
* Now the address will be pointing to middle node.
  * Join the next node and previous node. 
* Finally delete the node pointed by the provided address.

```cpp
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
```

## Implementing LRU class

### Inserting a element to LRU Cache

* Check if the element is already present in the cache or not. This can be done using the Hash Map.
  * If the element is already present.
    * Make it to MRU Node.
    * Delete the currrent element.
    * Insert the element with updated value to LRU cache. 
    * In this prcess the size will remain constant. 
  * If the element is not present
    * Check for size
      * If the size is less than capacity
        * Insert the element to cache
      * If the size is greator than capacity
        * Remove the LRU node(head) 
        * Insert the same element to Cache
* As inserting is done in every step, we can move it out of If-else ladder
```cpp
void LRU::put(int key, int value){
	// Check if the key already exist
	if(table[key] != NULL)
            remove(table[key]); 
    else if(size >= capacity) remove(head); 
    pushBack(key, value); 
}
```

### Accessing an element from LRU Cache

* Check if the element exist or not
  * If not return -1.
  * If yes
    * Get its address from Hash Table.
    * Store the `value` parameter into a variable.
    * Remove the node using its address.
    * Insert the same node using key and value.
    * This makes the node as MRU node. 
    * return the stored `value`. 
  
```cpp
int LRU::get(int key){
	if(table[key] == NULL) return -1; 
	
	node* address = table[key]; 
	int value = address->value; 
	remove(address); 
	pushBack(key, value); 
	return value; 	
}
```
## Complexity
| Operation   | Complexity   |
| :-----:     | :-----:      |
| Insert      | O(1)         |
| Access      | O(1)         |
| Space       | O(n)         |


* <a href=''>Full Program</a>

## Reference Links
* <a href='https://www.geeksforgeeks.org/unordered_map-in-cpp-stl/#:~:text=unordered_map%20is%20an%20associated%20container,type%20predefined%20or%20user%2Ddefined.'> Unordered Map in C++ STL</a>
* <a href='https://www.interviewcake.com/concept/java/lru-cache'> About LRU Cache</a>
* <a href='https://www.geeksforgeeks.org/lru-cache-implementation/'> About LRU Cache. GeeksForGeeks</a>


 
