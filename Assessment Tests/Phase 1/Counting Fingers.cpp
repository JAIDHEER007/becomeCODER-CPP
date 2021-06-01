//Counting fingers

#include<iostream>
using namespace std;

int CF1(int number){
	int num_mod_8 = (number % 8);
	
	if(num_mod_8 == 1){ return 1; }
	else if((num_mod_8 == 2) || (num_mod_8 == 0)){ return 2; }
	else if((num_mod_8 == 3) || (num_mod_8 == 7)){ return 3; }
	else if((num_mod_8 == 4) || (num_mod_8 == 6)){ return 4; }
	else if(num_mod_8 == 5){ return 5; }
}

int CF2(int number){
	int counting_fingers[] = {2,1,2,3,4,5,4,3};
	return counting_fingers[number % 8];
}

int main(){
	cout<<CF1(32)<<" "<<CF2(32)<<endl;
	cout<<CF1(685)<<" "<<CF2(685)<<endl;
	cout<<CF1(12)<<" "<<CF2(12)<<endl;
	cout<<CF1(347)<<" "<<CF2(347)<<endl;
	cout<<CF1(83)<<" "<<CF2(83)<<endl;
	
	return 0;
}
