//Min Max in an array
//Using Recursion
//Vector doesn't work in this case

#include<iostream>
using namespace std;

int MIN(int arr[], int n){
	if(n == 1){ return arr[0]; }	//If array is of single element, then return it
	int next_min = MIN(arr+1,n-1);	//Finding the min element in the next subarray
	return (arr[0] < next_min)?(arr[0]):(next_min);
}

int MAX(int arr[], int n){
	if(n == 1){ return arr[0]; }
	int next_max = MAX(arr+1,n-1);
	return (arr[0] > next_max)?(arr[0]):(next_max);
}

int main(){
	int arr1[] = { 121, 1747, 757, -1130, 864, -1971, 319, -1215, -647, 1810 };
	cout<<"Min: "<<MIN(arr1,10)<<endl;
	cout<<"Max: "<<MAX(arr1,10)<<endl;
	
	return 0;
}
