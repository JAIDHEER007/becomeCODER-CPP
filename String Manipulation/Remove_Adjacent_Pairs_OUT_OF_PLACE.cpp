//Removing adjacent pair of same characters in a string
//Out of place using stack DS

#include<iostream>
#include<stack>

using namespace std;

string removeAdjacentPairs(string text){
	stack<char> stk;
	for(char ch:text){
		if((!stk.empty()) && (ch == stk.top())){
			stk.pop();
			continue; 
		}
		stk.push(ch);
	}
	string result = "";
	while(!stk.empty()){
		result = stk.top() + result;
		stk.pop();
	}
	return result;
}

int main(){
	cout<<removeAdjacentPairs("jaidheer")<<endl;
	cout<<removeAdjacentPairs("aaa")<<endl;
	cout<<removeAdjacentPairs("aaaa")<<endl;
	cout<<removeAdjacentPairs("QWERTY")<<endl;
	cout<<removeAdjacentPairs("AABBA")<<endl;
	
	return 0;
}

/*
Idea behind it is same as Remove_Repeating_OUT_OF_PLACE but,
we will pop the stack if traversed character is same as that of stack top.
In this way we will remove any adjacent pair of same characters.
*/
