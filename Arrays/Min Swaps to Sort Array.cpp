#include<iostream>
#include<vector>

using namespace std; 

int minSwaps(vector<int> arr){
    int swapCount = 0; 
    for(int i = 0; i < arr.size() - 1; ++i){
        // Finding the minimum
        int minElement = arr[i]; 
        int minIndex = i; 
        for(int j = i + 1; j < arr.size(); ++j){
            if(arr[j] < minElement){
                minElement = arr[j]; 
                minIndex = j;
            }
        }

        if(minIndex != i){
            ++swapCount; 
            swap(arr[i], arr[minIndex]); 
        }
    }

    return swapCount; 
}

int main(){
    int n; 
    cin>>n;
     
    vector<int> arr(n);     
    for(int i = 0; i < n; ++i)  
        cin>>arr[i]; 

    cout<<minSwaps(arr)<<endl; 

    return 0; 
}