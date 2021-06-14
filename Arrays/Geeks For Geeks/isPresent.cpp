//GFG problem 1
//Check if a key is present in every segment of size k in an array

#include<iostream>
#include<vector>
using namespace std;

bool linearSearch(vector<int> arr, int start, int end, int key){
	for(int i=start;i<end;i++)
		if(arr[i] == key){ return true; }
	return false;
}

bool isPresent(vector<int> arr, int seg_size, int k){
	int arr_size = arr.size();
	int no_of_segs = arr_size/seg_size;
	int i = 0;
	for(;i<no_of_segs;i++){
		int start = (i*seg_size);
		int end = start + seg_size;
		if(!linearSearch(arr,start,end,k)){ return false; }
	}
	if(arr_size % seg_size)
		if(!linearSearch(arr,(i*seg_size),arr_size,k)){ return false; }
	
	
	return true;
}

int main(){
	vector<int> arr1{3, 5, 2, 4, 9, 3, 1, 7, 3, 11, 12, 3};
	cout<<boolalpha<<isPresent(arr1,3,3)<<endl;
	
	vector<int> arr2{21, 23, 56, 65, 34, 54, 76, 32, 23, 45, 21, 23, 25}; 
	cout<<boolalpha<<isPresent(arr2,5,23)<<endl;
	
	vector<int> arr3{5, 8, 7, 12, 14, 3, 9}; 
	cout<<boolalpha<<isPresent(arr3,2,8)<<endl;
	
	
	return 0;
}
