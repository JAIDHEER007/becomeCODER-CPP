//Return the next and before 2 powers of a given number

#include<iostream>
#include<vector>
using namespace std;

vector<int> power2_next_before(int num){
	vector<int> result;
	if(num == 0){
		result.push_back(1);
		result.push_back(0);
		return result;
	}
	
	int bits;
	for(bits=0;num;bits++,num>>=1);

	result.push_back(1<<(bits));
	result.push_back(1<<(bits-1));
	
	return result;
}

int main(){
	int num = 533;
	vector<int> result = power2_next_before(num);
	
	cout<<result[0]<<" "<<num<<" "<<result[1]<<endl;
	
	return 0;
}

