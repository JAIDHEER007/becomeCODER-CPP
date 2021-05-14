//Anagrams or not
//using Hashing
//For alphanumeric

#include<iostream>
#include<vector>

using namespace std;

bool isAnagram(string str1, string str2){
	if(str1.length() != str2.length()){ return false; }
	
	vector<int> alphabets_lower(26);
	vector<int> alphabets_upper(26);
	vector<int> numbers(10);
	
	for(char ch:str1){
		if((ch>='0')&&(ch<='9')){ numbers[ch - '0']++; }
		else if((ch>='a')&&(ch<='z')){ alphabets_lower[ch - 'a']++; }
		else if((ch>='A')&&(ch<='Z')){ alphabets_upper[ch - 'A']++; }
	}
		
	for(char ch:str2){
		if((ch>='0')&&(ch<='9')){ numbers[ch - '0']--; }
		else if((ch>='a')&&(ch<='z')){ alphabets_lower[ch - 'a']--; }
		else if((ch>='A')&&(ch<='Z')){ alphabets_upper[ch - 'A']--; }
	}

	for(int frequency:alphabets_lower)
		if(frequency!=0){ return false; }
	for(int frequency:alphabets_upper)
		if(frequency!=0){ return false; }
	for(int frequency:numbers)
		if(frequency!=0){ return false; }
	return true; 
	
}

int main(){
	string str1 = "PDwVf0udVtbqf1SSylsch6WG2Horubr8aOtSUqyTnOIV00tyuhphSqjt2IXeQLvpaW8yN8UN0qrKaY6dHptDAxhkWadSE63su1Bc";	
	string str2 = "V010Lu2OpVSqrUqbr8sqwWDlVW6hydTd2SrOIt3nc8Pajyt0H1N6vQhGyhf6DfppuStYStaWaAaHxS08IsyquBbXedtUNkchKouE";
	//cin>>str1>>str2;
	
	cout<<boolalpha<<isAnagram(str1, str2)<<endl;
	
	return 0;
}

//Output
//true
//Execution Time: 0.02591 seconds

