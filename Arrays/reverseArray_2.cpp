//Reverse the array
//Two pointer method

#include<iostream>
#include<vector>
using namespace std;

void reverseArr(vector<int> &arr){
	int start = 0, end = arr.size() - 1;
	
	while(start < end){
		swap(arr[start],arr[end]);
		start++;
		end--;
	}
}

void print(vector<int> &arr){
	for(int element:arr)
		cout<<element<<" ";
	cout<<endl;
}

int main(){
	
	//Single Element
	vector<int> arr1{ 553 };
	//Original array
	print(arr1);
	
	reverseArr(arr1);
	
	//Reverse Array
	print(arr1);
	
	//Even Number of elements
	vector<int> arr2{ 378, 1573, 794, 1620, 1235, 1070, 1628, 477, 1260, 1113 };
	//Original array
	print(arr2);
	
	reverseArr(arr2);
	
	//Reverse Array
	print(arr2);
	
	//Odd Number of elements
	vector<int> arr3{ 1609, 1133, 448, 628, 1423, 574, 235, 1587, 817, 1889, 1944, 1146, 363 };
	//Original array
	print(arr3);
	
	reverseArr(arr3);
	
	//Reverse Array
	print(arr3);
		
	return 0;
}
