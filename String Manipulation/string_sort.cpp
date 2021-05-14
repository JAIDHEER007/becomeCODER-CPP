//Sorting a string
//using sort() function: O(nlogn)
//using Hashing: O(n)

#include<iostream>
#include<algorithm> //sort()
using namespace std;

bool inline comp(char a, char b){
	return a > b; 
}

int main(){
	string test1 = "fdcyjudqcwvfyqpdckblpgjcxtoipgsrwcawrqrviodfndxrow"; 
	//cin>>test1;
	
	//Sorting in ascending order using sort() function
	sort(test1.begin(),test1.end());
	cout<<test1<<endl;		//abcccccdddddfffggiijjklnooopppqqqrrrrstuvvwwwwxxyy
	
	//Sorting in descending order using sort() function
	sort(test1.begin(),test1.end(),comp);
	cout<<test1<<endl; 		//yyxxwwwwvvutsrrrrqqqpppooonlkjjiiggfffdddddcccccba
	
	//using Hashing
	
	//constructing a hash table
	vector<int> alphabets(26);
	for(char ch:test1)
		alphabets[ch -'a']++;
	
	//Reconstructing the string from hash table
	
	//Sorting in ascending order
	string result = "";
	for(int i=0;i<alphabets.size();i++)
		result += string(alphabets[i],char('a'+i));
	cout<<result<<endl;		//abcccccdddddfffggiijjklnooopppqqqrrrrstuvvwwwwxxyy
	
	//Sorting in descending order
	result = "";
	for(int i=alphabets.size()-1;i>=0;i--)
		result += string(alphabets[i],char('a'+i));
	cout<<result<<endl;		//yyxxwwwwvvutsrrrrqqqpppooonlkjjiiggfffdddddcccccba
	
	
	return 0;
}

//With sort() function we can sort a alphanumeric string, even if it has special characters.
//As it is based on comparision

//Sorting by hashing cannot sort alphanumeric strings
//We can do it but the code complexity will be increased
//It is not based on comparision 
