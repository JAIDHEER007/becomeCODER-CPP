//Subarray sum

#include<iostream>
#include<vector>

using namespace std;

bool subArraySum(vector<int> arr, int sum){
	int arr_size = arr.size();
	for(int i=0;i<arr_size;i++){
		for(int j=0;j<arr_size;j++){
			int sub_sum = 0;
			for(int k=i;k<=j;sub_sum += arr[k],k++);
			if(sub_sum == sum){ return true; }
		}
	}
	return false;
}

int main(){
	vector<int> arr{1,2,2,5};
	
	cout<<boolalpha<<subArraySum(arr,5)<<endl;
	cout<<boolalpha<<subArraySum(arr,3)<<endl;
	cout<<boolalpha<<subArraySum(arr,4)<<endl;
	
	return 0;
}
