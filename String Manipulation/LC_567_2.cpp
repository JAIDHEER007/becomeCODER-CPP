// LC 567
// Permutation in a string
// Sliding Window and 2 Pointer

#include<iostream>
#include<vector>
using namespace std; 

bool checkInclusion(string s1, string s2){
	// Creating a frequency array
	vector<int> farray(26, 0); 
	for(int i = 0; i < s1.length(); ++farray[s1[i] - 'a'], ++i); 
	
	// Length of the Strings
	int s1len = s1.length(); // Window Length
	int s2len = s2.length(); // Limit for traversal
	
	// Creating the pointer with window size equal to s1len
	int i = 0; 
	int j = i + s1len - 1; 
	
	while((i < s2len) && (j < s2len)){
		vector<int> temp = farray; 
		while(j >= i){
			if(temp[s2[j] - 'a'] > 0){
				--temp[s2[j] - 'a'];
				--j;	
			}
			else break;
		}
		if(j < i) return true;
		else{
			i = j + 1; 
			j = i + s1len - 1;
		}
	}
	return false; 
}

int main(){
	cout<<boolalpha<<checkInclusion("adca", "ejdcajkmcaadm")<<endl; 
	
	return 0; 
}
