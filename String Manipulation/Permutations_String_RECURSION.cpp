//Print all permutations of a string

#include<iostream>
#include<vector>
using namespace std;

typedef vector<bool> vb;

void printPermutationsSTR(string e_str, string str, vb visited){
	if((e_str.length()) == (str.length())){
		cout<<e_str<<endl;
		return;
	}
	for(int i=0;str[i] != '\0'; i++){
		if(!visited[i]){
			visited[i] = true;
			printPermutationsSTR((e_str + str[i]),str,visited);
			visited[i] = false; 
		}
	}
}

int main(){
	string str = "abc"; 	//Original String
	string e_str = ""; 		//Empty Str;
	
	vb visited(str.length());
	
	printPermutationsSTR(e_str,str,visited);
	
	return 0;
}
