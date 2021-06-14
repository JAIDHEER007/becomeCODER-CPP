//Reverse Array in Groups of given size

#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> arr){
	for(int element:arr)
		cout<<element<<" ";
	cout<<endl;
}

void reverse(vector<int> &arr, int start, int end){
	while(start < end)
		swap(arr[start++],arr[end--]);
}

void reverseInGroups(vector<int> &arr, int g_size){
	int arr_size = arr.size();
	int num_grps = arr_size/g_size;
	int i=0;
	for(;i<num_grps;i++){
		int start = (i * g_size);
		int end = start + g_size - 1;
		reverse(arr, start, end);
	}
	if(arr_size % g_size)
		reverse(arr, (i*g_size), (arr_size - 1));
}

int main(){
	vector<int> arr1{1, 2, 3, 4, 5, 6, 7, 8, 9};
	print(arr1);
	reverseInGroups(arr1, 3);
	print(arr1);
	
	vector<int> arr2{1, 2, 3, 4, 5, 6, 7, 8};
	print(arr2);
	reverseInGroups(arr2, 5);
	print(arr2);
	
	vector<int> arr3{1, 2, 3, 4, 5, 6};
	print(arr3);
	reverseInGroups(arr3, 1);
	print(arr3);
	
	return 0;
}
