//Unit digit of x power y
//Unit digit of xʸ
//Using Look Up Tables

//power % 2 == power & 1
//power % 4 == power & 3

#include<iostream>
#include<vector>

using namespace std;

int main(){
	
	int base, power;
	cin>>base>>power;
	
	int unit_digit;
	switch(base % 10){
		case 0:{
			unit_digit = 0;
			break;
		}
		case 1:{
			unit_digit = 1;
			break;
		}
		case 2:{
			vector<int> lut2{ 6, 2, 4, 8 };
			unit_digit = lut2[power&3];
			break;
		}
		case 3:{
			vector<int> lut3{ 1, 3, 9, 7 };
			unit_digit = lut3[power&3];
			break;
		}
		case 4:{
			unit_digit = ((power&1)==0)?(6):(4);
			break;
		}
		case 5:{
			unit_digit = 5;
			break;
		}
		case 6:{
			unit_digit = 6;
			break;
		}
		case 7:{
			vector<int> lut7{ 1, 7, 9, 3 };
			unit_digit = lut7[power&3];
			break;
		}
		case 8:{
			vector<int> lut8{ 2, 6, 8, 4 };
			unit_digit = lut8[power&3];
			break;
		}
		case 9:{
			unit_digit = ((power&1)==0)?(1):(9);
			break;
		}
	}
	
	cout<<"Unit digit: "<<unit_digit<<endl;
	return 0;
}
