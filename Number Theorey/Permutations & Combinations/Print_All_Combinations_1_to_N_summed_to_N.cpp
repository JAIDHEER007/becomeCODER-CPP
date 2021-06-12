//Given a number N
//Print all combinations from 1 to N through which N can be formed

#include<iostream>
#include<vector>

using namespace std;

void printCombinations(int n, vector<int> &arr){
	if(n == 0){
		for(int element:arr)
			cout<<element<<" ";
		cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		arr.push_back(i);
		printCombinations((n-i),arr);
		arr.pop_back();
	}
}

int main(){
	vector<int> arr;
	
	printCombinations(4,arr);
	arr.clear();
	
	cout<<endl<<endl;
	
	printCombinations(3,arr);
	arr.clear();
	
	cout<<endl<<endl;
	
	printCombinations(0,arr);
	arr.clear();
	
//	cout<<endl<<endl;
//	
//	printCombinations(10,arr);
//	arr.clear();
	
	return 0;
}


