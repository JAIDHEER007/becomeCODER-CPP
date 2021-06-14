//Min Max in an array
//Using Loops

#include<iostream>
#include<vector>
using namespace std;

int MIN(vector<int> arr){
	int min = INT_MAX;
	for(int element:arr)	
		if(element < min){ min = element; }
	return min;
}

int MAX(vector<int> arr){
	int max = INT_MIN;
	for(int element:arr)
		if(element > max){ max = element; }
	return max;
}

int main(){
	vector<int> arr1{ 121, 1747, 757, -1130, 864, -1971, 319, -1215, -647, 1810 };
	cout<<"Min: "<<MIN(arr1)<<endl;
	cout<<"Max: "<<MAX(arr1)<<endl;
	
	return 0;
}
