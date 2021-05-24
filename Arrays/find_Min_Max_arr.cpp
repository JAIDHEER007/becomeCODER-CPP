//Finding minimum and maximum element in a given array

#include<iostream>
#include<vector>
using namespace std;

int findMin(vector<int> &arr){
	int min = INT_MAX;
	for(int element:arr)
		if(element < min){ min = element; }
	return min;
}

int findMax(vector<int> &arr){
	int max = INT_MIN;
	for(int element:arr)
		if(element > max){ max = element; }
	return max;
}

int main(){
	vector<int> arr{ 35, 394, -129, 341, 
			 -151, 126, 342, 8, 
			 -145, 389, -125, 249,
			 -135, 2, -170, 310  };
					 
	cout<<"Min element: "<<findMin(arr)<<endl;
	cout<<"Max element: "<<findMax(arr)<<endl;
	
	return 0;
}
