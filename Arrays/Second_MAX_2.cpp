//Finding second max using search and ignore operations

#include<iostream>
#include<vector>

using namespace std;

int secondMAX(vector<int> &arr){
	int firstMAX, secondMAX;
	firstMAX = secondMAX = INT_MIN;
	
	//finding the first max
	for(int element:arr)
		if(element > firstMAX){ firstMAX = element; }
	
	//finding the second max
	for(int element:arr)
		if((element!=firstMAX) && (element > secondMAX)){ secondMAX = element; }
	
	return secondMAX;
}

int main(){
	vector<int> arr{ 5, 12, 6 };
	cout<<secondMAX(arr)<<endl;
	
	vector<int> arr2{-4, -146, 128, 89, -178,
			-56, -170, -101, 31, -61 };
					 
	cout<<secondMAX(arr2)<<endl;
	
	return 0;
}
