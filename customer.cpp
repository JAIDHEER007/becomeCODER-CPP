#include<iostream>
#include<vector>
#include<map>

using namespace std;

typedef map<int,int> frequency;

int main(){
	frequency f1;
	vector<int> customer_ids{ 1,2,1,3,4,1,5,6,2,3,1,4,7,2,2,3,1 };
	
	for(int customer_id:customer_ids)
		f1[customer_id]++;
		
	int max_visits = -1;
	int customer;
	for(auto itr = f1.begin();itr!=f1.end();itr++){
		if(itr->second > max_visits){
			max_visits = (itr->second);
			customer = (itr->first);
		}
	}
	
	cout<<"Customer id: "<<customer<<endl;
	cout<<"Number of Visits: "<<max_visits<<endl;
	
	return 0;
}
