//Count Occurrences in an sorted array

#include<iostream>
#include<vector>

using namespace std;

int binarySearch(vector<int> arr, int key){
	int start = 0;
	int end = arr.size() - 1;
	int mid = (start + end) / 2;
	
	while(start <= end){
		if(arr[mid] > key){ end = mid - 1; }
		else if(arr[mid] < key){ start = mid + 1; }
		else{ return mid; }
		mid = (start + end) / 2;
	}
	if(start > end){ return -1; }
}

int countOccurences(vector<int> arr, int key){
	int index = binarySearch(arr,key);
	if(index == -1){ return 0; }
	int count = 1;
	
	//Left Side;
	int left = index - 1;
	while(left >= 0 && arr[left] == key){
		left--;
		count++;
	}
	
	//Right Side
	int right = index + 1;
	while(right < arr.size() && arr[right] == key){
		right++;
		count++;
	}
	
	return count;
}

int main(){
	vector<int> arr1{1,2,3,4,5,6};
	cout<<countOccurences(arr1,7)<<endl;
	
	
	vector<int> arr2{1,2,3,4,5,6};
	cout<<countOccurences(arr2,4)<<endl;
	
	vector<int> arr3{2,2,2,4,5,6};
	cout<<countOccurences(arr3,2)<<endl;
	
	vector<int> arr4{1,2,3,6,6,6};
	cout<<countOccurences(arr4,6)<<endl;
	
	vector<int> arr5{1,2,3,4,4,4,4,5,6};
	cout<<countOccurences(arr5,4)<<endl;
	
	vector<int> arr6{1,1,1,1,1,1};
	cout<<countOccurences(arr6,1)<<endl;
	
	
	
	
	return 0;
}
