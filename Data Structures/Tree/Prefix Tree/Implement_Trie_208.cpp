// 208. Implement Trie (Prefix Tree)
// https://leetcode.com/problems/implement-trie-prefix-tree/

#include<iostream>
using namespace std; 

class node{
public:
    node *children[26] = {NULL};
    bool isEnd; 
    
    node(){
        this->isEnd = false; 
    }
};
class Trie:protected node{
private:
    node *root; 
public:
    Trie() {
       root = new node();  
    }
    
    void insert(string word) {
        node *curr = root; 
        for(char ch:word){
            int index = ch - 'a';
            if(curr->children[index] == NULL)
                curr->children[index] = new node(); 
            curr = curr->children[index];
        }
        curr->isEnd = true; 
    }
    
    bool search(string word) {
        node *curr = root; 
        for(char ch:word){
            int index = ch - 'a'; 
            if(curr->children[index] == NULL) return false; 
            curr = curr->children[index]; 
        }
        return curr->isEnd; 
    }
    
    bool startsWith(string prefix) {
        node *curr = root;
        for(char ch:prefix){
            int index = ch - 'a';
            if(curr->children[index] == NULL) return false;
            curr = curr->children[index];
        }
        return true; 
    }
};

int main(){
    Trie *obj = new Trie(); 

    obj->insert("apple");
    cout<<boolalpha<<obj->search("apple")<<endl; 

    cout<<boolalpha<<obj->search("app")<<endl;

    cout<<boolalpha<<obj->startsWith("app")<<endl;

    obj->insert("app"); 

    cout<<boolalpha<<obj->search("app")<<endl; 

    return 0;  
}