//Question 6
//Reverse Array Queries

#include<bits/stdc++.h>
#define NeedForSpeed ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void reverseArray(vector<int> &arr, int start, int end){
	while(start < end){
		swap(arr[start],arr[end]);
		++start;
		--end; 
	}
}

vector<int> performOperations(vector<int> arr, vector<vector<int>> operations){
	for(vector<int> operation:operations)
		reverseArray(arr,operation[0],operation[1]);
	return arr; 
}

int main(){
	NeedForSpeed;
	int n; //Main Array
	cin>>n;
	
	vector<int> arr; 
	for(int i=0;i<n;++i){
		int num; cin>>num;
		arr.push_back(num);
	}
	
	int q; //Operations
	cin>>q;
	vector<vector<int>> operations;
	
	for(int i=0;i<q;++i){
		vector<int> operation;
		for(int j=0;j<2;++j){
			int index; cin>>index;
			operation.push_back(index);
		}
		operations.push_back(operation);
	}
	
	vector<int> result = performOperations(arr,operations);
	for(int element:result)
		cout<<element<<" ";
	cout<<endl;
	
	return 0;
}



