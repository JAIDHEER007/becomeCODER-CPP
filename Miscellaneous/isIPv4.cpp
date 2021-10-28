// IPv4 validation

#include<iostream>
using namespace std; 

bool validIPv4Token(int token, int tokenLength){
	if((token > 255) || (token < 0)) return false;
	switch(tokenLength){
		case 0: return false; 
		case 1: 
			if(token >= 10) return false; 
			break; 
		case 2:
			if((token < 10) || (token >= 100)) return false; 
			break; 
		case 3:
			if((token < 100) || (token >= 256)) return false; 
			break;
		default: return false; 
	}
	return true; 
}

bool isIPv4(string ipAdd){
	int tokensCount = 0;
	int tokenNumber = 0;
	int tokenLen = 0; 
	
	for(int i = 0; i < ipAdd.length(); ++i){
		if(tokensCount > 4) return false; 
		if(tokenLen > 3) return false; 
		
		if((ipAdd[i] >= '0') && (ipAdd[i] <= '9')){
			tokenNumber = (tokenNumber * 10) + (ipAdd[i] - '0'); 
			++tokenLen; 
		}
		else if(ipAdd[i] == '.'){
			if(!validIPv4Token(tokenNumber, tokenLen)) return false; 
			++tokensCount; 
			tokenNumber = 0; 
			tokenLen = 0; 
		}else return false; 
	}
	
	return ((tokensCount == 3) && (validIPv4Token(tokenNumber, tokenLen))); 
}

int main(){
	
	cout<<boolalpha<<isIPv4("172.7.7.12")<<endl; 
	cout<<boolalpha<<isIPv4("172.16.254.1")<<endl; 
	cout<<boolalpha<<isIPv4("172.316.254.1")<<endl; 
	cout<<boolalpha<<isIPv4(".254.255.0")<<endl; 
	cout<<boolalpha<<isIPv4("1.1.1.1a")<<endl; 
	cout<<boolalpha<<isIPv4("1")<<endl; 
	cout<<boolalpha<<isIPv4("0.254.255.0")<<endl; 
	cout<<boolalpha<<isIPv4("1.23.256.255")<<endl; 
	cout<<boolalpha<<isIPv4("64.233.161.00")<<endl; 
	cout<<boolalpha<<isIPv4("1.256.1.1")<<endl; 
	cout<<boolalpha<<isIPv4("255.255.255.255abcdekjhf")<<endl; 
	
	return 0; 
}
