//Question 6
//Last and Second-Last 

#include<bits/stdc++.h>
#define NeedForSpeed ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

string lastLetters(string word){
	return (string(1,(word[word.length()-1]))+" "+string(1,(word[word.length()-2])));
}

int main(){
	NeedForSpeed;
	string s; 
	cin>>s;
	cout<<lastLetters(s)<<endl;
	
	return 0;
}



