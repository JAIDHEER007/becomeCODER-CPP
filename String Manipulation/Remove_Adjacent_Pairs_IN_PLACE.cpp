//Removing adjacent pair of same characters in a string
//In Place

#include<iostream>
using namespace std;

string removeAdjacentPairs(string text){
	for(int i=1;i<text.length();){
		if(text[i-1] != text[i])
			i++;
		else{
			text = (text.substr(0,(i-1)) + text.substr(i+1,(text.length()-i-1)));
			i--;
		}
	}
	return text;
}

int main(){
	cout<<removeAdjacentPairs("jaidheer")<<endl;
	cout<<removeAdjacentPairs("aaa")<<endl;
	cout<<removeAdjacentPairs("aaaa")<<endl;
	cout<<removeAdjacentPairs("QWERTY")<<endl;
	cout<<removeAdjacentPairs("AABBA")<<endl;
	
	return 0;
	
}


