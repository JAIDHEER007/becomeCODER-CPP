// LC 1032 Stream of Characters
// Suffix

#include<iostream>
#include<vector>

using namespace std; 

class StreamChecker{
	private:
		typedef struct node{
			node* children[26]; 
			bool isEnd; 
			
		} node;
		
		node* root;
		string queryStream; 
		int lenLongWord; 
		
		node* getNode(){
			node* newNode = new node; 
			for(int i = 0; i < 26; i++)
				newNode->children[i] = NULL;
			newNode->isEnd = false;
			
			return newNode; 
		}		
		
		void insert(node* root, string txt){
			node* curr = root; 
			for(int i = txt.length() - 1; i >= 0; --i){
				int index = txt[i] - 'a'; 
				if(curr->children[index] == NULL) curr->children[index] = getNode();
				curr = curr->children[index];
			}
			curr->isEnd = true;
		}
		
		bool search(node* root, string key){
			node* curr = root; 
			for(int i = 0; i < key.length(); ++i){
				int index = key[i] - 'a';
				if(curr->children[index]) curr = curr->children[index]; 
				else return false;
				if(curr->isEnd) return true;
			}
			return false; 
		}
	
	public:
		StreamChecker(vector<string> &words){
			lenLongWord = INT_MIN; 
			queryStream = ""; 
			root = getNode();
			
			for(string word:words){
				lenLongWord = max(lenLongWord, int(word.length()));
				insert(root, word); 
			}
		}
		
		bool query(char letter){
			queryStream = letter + queryStream; 
			if(queryStream.length() > lenLongWord) queryStream.pop_back();
			return this->search(root, queryStream);
		}
};

int main(){
	vector<string> words{"ab", "ba", "aaab", "abab", "baa"};
	StreamChecker sc1(words);
	
	cout<<boolalpha<<sc1.query('a')<<endl;
	cout<<boolalpha<<sc1.query('a')<<endl;
	cout<<boolalpha<<sc1.query('a')<<endl;
	cout<<boolalpha<<sc1.query('a')<<endl;
	cout<<boolalpha<<sc1.query('a')<<endl;
	cout<<boolalpha<<sc1.query('b')<<endl;
	return 0; 
}




