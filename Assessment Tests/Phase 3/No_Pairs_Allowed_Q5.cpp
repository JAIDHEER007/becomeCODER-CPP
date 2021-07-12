//Question 5
//No Pairs Allowed

#include<bits/stdc++.h>
#define NeedForSpeed ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int substitutions(string word){
	stack<char> stk;
	int count = 0;
	for(char ch:word){
		if(stk.empty()){
			stk.push(ch);
			continue;
		}
		
		if(ch == stk.top()){
			ch = '#';
			++count; 
		}
		stk.push(ch);
	}
	return count; 
}

vector<int> minimalOperations(vector<string> words){
	vector<int> result;
	for(string word:words)
		result.push_back(substitutions(word));
	return result; 
}

int main(){
	NeedForSpeed;
	
	int n; cin>>n;
	vector<string> words;
	
	for(int i=0;i<n;++i){
		string word; cin>>word;
		words.push_back(word);
	}
	
	vector<int> result = minimalOperations(words);
	
	for(int element:result)
		cout<<element<<" ";
	
	return 0;
}



