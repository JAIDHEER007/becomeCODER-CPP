//Fiding second max using another variable

#include<iostream>
#include<vector>
using namespace std;

int secondMAX(vector<int> &arr){
	int firstMAX, secondMAX;
	firstMAX = secondMAX = INT_MIN;
	
	for(int element:arr){
		if(element > firstMAX){
			secondMAX  = firstMAX;
			firstMAX = element;
		}else if(element > secondMAX)
			secondMAX = element; 
	}
	
	return secondMAX;
}

int main(){
	vector<int> arr1{ 5, 12, 6 };
	cout<<secondMAX(arr1)<<endl;
	
	vector<int> arr2{-4, -146, 128, 89, -178,
					 -56, -170, -101, 31, -61 };
					 
	cout<<secondMAX(arr2)<<endl;
	
	return 0;
}
