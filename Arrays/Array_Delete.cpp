//Deleting an element in an array

#include<iostream>
using namespace std;

int main(){
	int capacity;
	cin>>capacity;
	
	int arr[capacity];
	
	int n; //number of elements
	cin>>n;
	
	if(n > capacity)
		cout<<"Number of elements exceeded the capacity"<<endl;
	else{
		for(int i=0;i<n;i++)
			cin>>arr[i];
		
		int element; //element to be deleted
		cin>>element;
		
		int index = -1;
		for(int i=0;i<n;i++){
			if(arr[i] == element){ 
				index = i;
				break;
			}
		}
		
		if(index == -1){
			cout<<"Given element does not exist"<<endl;
			return 0;
		}else{
			n--;
			for(int i=index;i<n;i++)
				arr[i] = arr[i+1];
			
			for(int i=0;i<n;i++)
				cout<<arr[i]<<" ";
			cout<<endl;
		}
	}
	return 0;
}
