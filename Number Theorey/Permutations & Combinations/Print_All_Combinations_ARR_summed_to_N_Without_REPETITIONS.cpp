//Given a number 'N'
//Given an array of integers 'a'
//Print combinations which can be formed form given array 'a' such that their sum is equal to 'N'

//Combiations are not repeated or is selection is not taken from back element

//For Example
//N = 4
//a = {1,2,4}

// All combinations formed by picking one are
// {1, 1, 1, 1}
// {1, 1, 2}

// All combinations formed by picking two are
// {2, 2} only 
// {1,2,1} cannot be chosen as one is already picked

#include<iostream>
#include<vector>

using namespace std;

typedef vector<int> vi;

void printCombinations(int N, vi &a, vi &arr, int index = 0){
	if(index == a.size()){
		if(N == 0){
			for(int element:arr)
				cout<<element<<" ";
			cout<<endl;
		}
		return;
	}
	if(a[index] <= N){
		arr.push_back(a[index]);
		printCombinations((N - a[index]),a,arr,index);
		arr.pop_back();
	}
	printCombinations(N,a,arr,index+1);
}

int main(){
	vi arr;
	vi a{1,2,4};
	
	printCombinations(4,a,arr);
	
	return 0;
}

