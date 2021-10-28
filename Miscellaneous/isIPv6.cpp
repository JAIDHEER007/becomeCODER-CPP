// IPv6 Validation

#include<iostream>
using namespace std; 

bool isIPv6(string ipAdd){
	int tokenCount = 0; 
	int tokenLength = 0; 
	
	for(int i = 0; i < ipAdd.length(); ++i){
		if(tokenCount > 8) return false; 
		if(tokenLength > 4) return false; 
		if(((ipAdd[i] >= '0') && (ipAdd[i] <= '9')) || 
		   ((tolower(ipAdd[i]) >= 'a') && (tolower(ipAdd[i]) <= 'f')))
		   ++tokenLength;
		else if(ipAdd[i] == ':'){
			if((tokenLength < 1) || (tokenLength > 4)) return false; 
			++tokenCount; 
			tokenLength = 0; 
		}
		else return false; 
	}
	return (tokenCount == 7) && ((tokenLength >= 1) && (tokenLength <= 4)); 
}

int main(){
	cout<<boolalpha<<isIPv6("2001:0db8:85a3:0000:0000:8a2e:0370:7334")<<endl; 
	cout<<boolalpha<<isIPv6("2001:db8:85a3:0:0:8A2E:0370:7334")<<endl; 
	
	cout<<boolalpha<<isIPv6("2001:0db8:85a3::8A2E:037j:7334")<<endl; 
	cout<<boolalpha<<isIPv6("02001:0db8:85a3:0000:0000:8a2e:0370:7334")<<endl; 
	cout<<boolalpha<<isIPv6("2001:0db8:85a3:0:0:8A2E:0370:73341")<<endl; 
	return 0; 
}
