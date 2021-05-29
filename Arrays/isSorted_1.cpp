//isSorted 
//Method 1

#include<iostream>
#include<vector>

using namespace std;

bool isSorted(vector<int> &arr){
	for(int i=0;i<arr.size()-1;i++){
		for(int j=i+1;j<arr.size();j++){
			if(arr[i] > arr[j]){ return false; }
		}
	}
	
	return true;
}

int main(){
	cout<<boolalpha;
	
	//Single element
	vector<int> arr1{ 553 };
	cout<<isSorted(arr1)<<endl; //true
	
	//Same elements
	vector<int> arr2{ 553,553,553,553 };
	cout<<isSorted(arr2)<<endl; //true
	
	//sorted in ascending order
	vector<int> arr3{ 402, 645, 921, 1752, 1843 };
	cout<<isSorted(arr3)<<endl; //true
	
	//sorted in descending order
	vector<int> arr4{ 1843, 1752, 921, 645, 402 };
	cout<<isSorted(arr4)<<endl;	//false
	
	vector<int> arr5{ 402, 645, 553, 921, 1752, 1843 };
	cout<<isSorted(arr5)<<endl;	//false
	
	return 0;
}
