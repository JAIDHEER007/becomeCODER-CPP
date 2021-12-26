#include<iostream>
#include<vector>
using namespace std; 

int partition(vector<int> &arr, int start, int end, int pivot){
    int pivotElement = arr[pivot];
    int i = start; 
    int j = end; 

    while(j > i){
        while(arr[i] <= pivotElement)
            ++i; 
        while(arr[j] > pivotElement)
            --j; 

        if(j > i)
            swap(arr[i], arr[j]);

    }
    swap(arr[pivot], arr[j]);
    return j; 
}

void quickSort(vector<int> &arr, int start, int end){
    // Base Case
    if(start >= end)
        return;

    // Wannabe pivot
    int pivot = start;

    // Finding the Sorted Possn of pivot element
    int j = partition(arr, start, end, pivot); 

    // Performing Quick Sort on Left Side of Pivot
    quickSort(arr, start, j - 1);

    // Performing Quick Sort on the Right Side of Pivot
    quickSort(arr, j + 1, end); 
}
int main(){
    int n; cin>>n;
    vector<int> arr(n); 

    for (int i = 0; i < n; ++i)
        cin>>arr[i]; 

    quickSort(arr, 0, n - 1); 

    for(int i = 0; i < arr.size(); ++i)
        cout<<arr[i]<<" "; 
    cout<<endl; 

    return 0; 
}