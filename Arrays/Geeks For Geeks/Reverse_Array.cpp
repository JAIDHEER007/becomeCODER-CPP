//Program to Reverse an array

#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> arr){
	for(int element:arr)
		cout<<element<<" ";
	cout<<endl;
}

void reverseArr1(vector<int> &arr){
	int start = 0;
	int end = arr.size() - 1;
	while(start < end){
		swap(arr[start],arr[end]);
		start++;
		end--;
	}
}

void reverseArr1Recursive(vector<int> &arr, int start, int end){
	if(start >= end)
		return;
	swap(arr[start],arr[end]);
	reverseArr1Recursive(arr, (start + 1), (end - 1));
}

void reverseArr2(vector<int> &arr){
	int arr_size = arr.size();
	for(int i=0;i<(arr_size>>1);i++)	//arr_size>>1 == arr_size/2
		swap(arr[i],arr[arr_size - i - 1]);
}

int main(){
	vector<int> arr{121, 1747, 757, -1130, 864, -1971, 319, -1215, -647, 1810};
	print(arr);
	reverseArr1(arr);
	print(arr);
	reverseArr2(arr);
	print(arr);
	reverseArr1Recursive(arr,0,arr.size()-1);
	print(arr);
	
	return 0;
}
