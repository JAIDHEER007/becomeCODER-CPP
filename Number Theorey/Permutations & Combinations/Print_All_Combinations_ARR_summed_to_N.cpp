//Given a number 'N'
//Given an array of integers 'a'
//Print all combinations which can be formed form given array 'a' such that their sum is equal to 'N'

#include<iostream>
#include<vector>

using namespace std;

typedef vector<int> vi;

void printCombinations(int n, vi &a, vi arr){
	if(n == 0){
		for(int element:arr)
			cout<<element<<" ";
		cout<<endl;
		return;
	}
	for(int element:a){
		arr.push_back(element);
		if((n - element) >= 0)
			printCombinations((n - element),a,arr);
		arr.pop_back();
	}
}

int main(){
	vi arr;
	vi a{1,2,4,5,7};
	
	printCombinations(5,a,arr);
	arr.clear();
	
	cout<<endl<<endl;
	
	printCombinations(9,a,arr);
	return 0;
}
