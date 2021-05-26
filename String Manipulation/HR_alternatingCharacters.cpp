#include<iostream>
using namespace std;


//HACKERRANK PROBLEM
//Alternating Characters

//TLE APPROACH
/*
int alternatingCharacters(string text) {
    int count = 0;
    for(int i=1;i<text.length();){
        if(text[i-1] != text[i])
            i++;
        else{
            text = (text.substr(0,(i-1)) + text.substr(i,(text.length()-i)));
            count++;
        }
            
    }
    return count;
}
*/
//This is 100% correct approach but as number of deletions are only needed, so there is no need
//to modify the given string

//WORKED APPROACH
int alternatingCharacters(string text){
    int count = 0;
    for(int i=1;i<text.length();i++)
        if(text[i-1] == text[i]){ count++; }
    return count;
}

int main(){
	cout<<alternatingCharacters("AAAA")<<endl;
	cout<<alternatingCharacters("BBBBB")<<endl;
	cout<<alternatingCharacters("ABABABAB")<<endl;
	cout<<alternatingCharacters("BABABA")<<endl;
	cout<<alternatingCharacters("AAABBB")<<endl;
	
	return 0;
}
