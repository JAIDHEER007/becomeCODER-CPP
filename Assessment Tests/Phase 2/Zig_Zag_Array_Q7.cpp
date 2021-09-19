#include<iostream>
#include<vector>
#define NeedForSpeed ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std; 

int LHoperation(vector<int> arr){
    int count = 0; 
    int toggle = false; 
    int limit = arr.size() - 1; 
    for(int i=0;i<limit;++i){
        if(!toggle){
            if((arr[i] >= arr[i+1]) && (arr[i+1] <= arr[i+2])){
                arr[i+1] = INT_MAX; 
                ++count; 
            }
            else if(arr[i] >= arr[i+1]){
                arr[i] = INT_MIN; 
                ++count; 
            }
            toggle = true; 
        }else{
            if((arr[i] <= arr[i+1]) && (arr[i+1] >= arr[i+2])){
                arr[i+1] = INT_MIN; 
                ++count; 
            }
            else if(arr[i] <= arr[i+1]){
                arr[i] = INT_MAX; 
                ++count; 
            }
            toggle = false; 
        }
    }
    return count; 
}

int HLoperation(vector<int> arr){
    int count = 0; 
    int toggle = false; 
    int limit = arr.size() - 1; 
    for(int i=0;i<limit;++i){
        if(!toggle){
            if((arr[i] <= arr[i+1]) && (arr[i+1] >= arr[i+2])){
                arr[i+1] = INT_MIN; 
                ++count; 
            }
            else if(arr[i] <= arr[i+1]){
                arr[i] = INT_MAX; 
                ++count; 
            }
            toggle = true; 
        }else{
            if((arr[i] >= arr[i+1]) && (arr[i+1] <= arr[i+2])){
                arr[i+1] = INT_MAX; 
                ++count; 
            }
            else if(arr[i] >= arr[i+1]){
                arr[i] = INT_MIN; 
                ++count; 
            }
            toggle = false; 
        }
    }
    return count; 
}

int minOperations(vector<int> arr){
	return min(LHoperation(arr), HLoperation(arr));
}

int main(){
	NeedForSpeed;
	vector<int> arr;
	
	arr={1,2,3,4,5};
	cout<<minOperations(arr)<<endl;
	arr={2,1,2,3,4,5,2,9};
	cout<<minOperations(arr)<<endl;
	arr={1,2,4,4,5,6};
	cout<<minOperations(arr)<<endl;
	
	return 0;
}
