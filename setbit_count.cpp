//Count Number of setbits

#include<iostream>
using namespace std;

int setBitCount(int num){
	int count = 0;
	while(num){
		if(num & 1){ count++; }
		num >>= 1;
	}
	return count;
}

int main(){
	cout<<setBitCount(0)<<endl;
	cout<<setBitCount(5)<<endl;
	cout<<setBitCount(13)<<endl;
	cout<<setBitCount(15)<<endl;
	
	return 0;
}

/*

Working

Let us consider number 13

Binary representation of 13 is 1101

Maintain setBitCounter with 0 as initial value. 

Number of set bits is 3

					Unset bit
						▲
		1		1		0		1
		▼		▼				▼
		═════════════════════════
				Set Bits
		═════════════════════════
		
◘ We can check if a bit at units place is set or not by performing & with 1 ◘


		1		1		0		1
	&	
		0		0		0		1
		═════════════════════════
		0		0		0		1   ════► 1
		═════════════════════════
		
		♦ Bit at units place is set
		
		1		1		0		0
	&	
		0		0		0		0
		═════════════════════════
		0		0		0		0   ════► 0
		═════════════════════════
		
		♦ Bit at units place is unset
		
		If result from & operation is 1. then increment setBitCounter by 1. 
		
◘ Checking if second bit is set or not ◘

► We can do this by right shifting the number by 1 time

		_________ _________ _________ _________
		║		║ ║ 	  ║	║		║ ║		  ║
		║		║ ║		  ║ ║		║ ║	      ║
		║		▼ ║		  ▼ ║		▼ ║		  ▼	
		1		 1		   0		 1
		
	══► 0		 1		   1		 0  ══► 6

	
► Repeat the & operation again

► Repeat the above steps until the number becomes 0	
*/
