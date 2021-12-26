//PERFORMIN QUICK SORT IN ASCENDING ORDER

#include<iostream>
using namespace std;

int partion(int *arr, int l, int h){
	
	int pivot = arr[l];
	int i = l;
	int j = h + 1;
	
	while(j > i){
		do
			i++;
		while(arr[i]<=pivot);
		
		do
			j--;
		while(arr[j]>pivot);
		
		if(j > i){
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	arr[l] = arr[j];
	arr[j] = pivot;
	return j;
}

void quick_sort(int *arr, int l, int h){
	if(l < h){
		int j = partion(arr,l,h);
		quick_sort(arr,l,j-1);
		quick_sort(arr,j+1,h);
	}
}

int main(){
	int arr_size;
	cout<<"Enter number of elements in the array: ";
	cin>>arr_size;
	
	int *arr = new int[arr_size];
	
	cout<<"\nEnter array elements:\n";
	for(int i=0; i<arr_size;i++)
		cin>>arr[i];
		
	quick_sort(arr,0,arr_size-1);
	
	for(int i=0;i<arr_size;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	
	return 0;
}
