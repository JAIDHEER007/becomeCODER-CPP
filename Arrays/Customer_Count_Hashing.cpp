//Customer Count
//Using Hashing

#include <iostream>
#include <vector>
using namespace std;

int findMax(vector<int> &arr){
	int max = INT_MIN;
	for(int element:arr)
		if(element > max){ max = element; }
	return max;
}

int main(){
	vector<int> customer_ids{ 1,2,1,3,4,1,5,6,2,3,1,4,7,2,2,3,1 };
	vector<int> frequency(findMax(customer_ids));
	
	for(int customer_id:customer_ids)
		frequency[customer_id]++;
		
	int max_visits = -1;
	int customer;
	for(int i=0;i<frequency.size();i++){
		if(frequency[i] > max_visits){
			max_visits = frequency[i];
			customer = i;
		}
	}
	
	cout<<"Customer id: "<<customer<<endl;
	cout<<"Number of Visits: "<<max_visits<<endl;
		
	return 0;
}
