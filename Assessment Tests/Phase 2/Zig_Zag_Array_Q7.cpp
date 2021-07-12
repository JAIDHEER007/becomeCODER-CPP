//Zig Zag Array

#include<bits/stdc++.h>
#define NeedForSpeed ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int LH(vector<int> arr){
	int operations = 0; 
	int i = 0;
	int j = i + 1;
	int k = j + 1;
	int arr_size = arr.size();
	
	while(k < arr_size){
		if((arr[i]>=arr[j])&&(arr[j]>arr[k])){
			arr[i] = INT_MIN;
			++operations; 
		}
		else if((arr[i]<arr[j])&&(arr[j]<=arr[k])){
			arr[k] = INT_MIN;
			++operations;
		}
		else if((arr[i]>=arr[j])&&(arr[j]<=arr[k])){
			arr[j] = INT_MAX;
			++operations;
		}
		i = k;
		j = i + 1;
		k = j + 1;
	}
	if(j != arr_size){
		if(arr[j] < arr[j-1]){
			arr[j] = INT_MAX; 
			++operations;
		}
	}
	return operations;
}

int HL(vector<int> arr){
	int operations = 0;
	int i = 0;
	int j = i + 1;
	int k = j + 1;
	int arr_size = arr.size();
	
	while(k < arr_size){
		if((arr[i]<=arr[j])&&(arr[j]<arr[k])){
			arr[i] = INT_MAX;
			++operations;
		}
		else if((arr[i]>arr[j])&&(arr[j]>=arr[k])){
			arr[k] = INT_MAX;
			++operations;
		}
		else if((arr[i]<=arr[j])&&(arr[j]>=arr[k])){
			arr[j] = INT_MIN;
			++operations;
		}
		i = k;
		j = i + 1;
		k = j + 1;
	}
	if(j != arr_size){
		if(arr[j] > arr[j-1]){
			arr[j] = INT_MIN; 
			++operations;
		}
	}
	return operations; 
}

int minOperations(vector<int> arr){
	return min(LH(arr),HL(arr));
}

int main(){
	NeedForSpeed;
	vector<int> arr;
	
	arr={1,2,3,4,5};
	cout<<minOperations(arr)<<endl;
	arr={2,1,2,3,4,5,2,9};
	cout<<minOperations(arr)<<endl;
	arr={1,2,4,4,5,6};
	cout<<minOperations(arr)<<endl;
	
	return 0;
}



