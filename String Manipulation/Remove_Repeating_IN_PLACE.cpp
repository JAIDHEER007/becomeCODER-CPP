//Removing the repeating characters and return the unique string
//in-place. 

#include<iostream>
//#include<chrono>
using namespace std;

string removeRepeating(string text){
	for(int i=1;i<text.length();){
		if(text[i-1] != text[i])
			i++;
		else
			text = (text.substr(0,(i-1)) + text.substr(i,(text.length()-i)));
	}
	return text;
}

int main(){
	cout<<removeRepeating("jaidheer")<<endl;
	cout<<removeRepeating("aaa")<<endl;
	cout<<removeRepeating("aaaa")<<endl;
	cout<<removeRepeating("QWERTY")<<endl;
	cout<<removeRepeating("AABBA")<<endl;

//Time Testing
//test string length is 500	
/*
	auto start = chrono::high_resolution_clock::now();
	string test = "ldacwlgjoxxneprtfwsyinxfxaymptcpherarjqjtlnqesbepgqlbmyfbxjetflovvhlxqaqxipjhsqioilnloedlmgbfowfbfgydqjtzxpwgrnvamzpaqoywpxysvxodeagaraovptthijilulyodxskodfxqhpprywwqnjqzqwxrlwpinfjrywarqyeltqaymoohzwwecqtqiopaxqlqxexolusoaxpjtmxawrnsvcosyaieaqyseizhlnjjeoqfqqqwckboqyojqujoqqloljhqwlqcwxyghcqllhsbyoqajeixqwogqsfavtyoqkecvgqdrmslxqwriaqeiepkypkpreqbqprwoengaqvebkqpkxrqqadaavxoxaxwtknussnsqhnrsxxhqjdfmdolyqeqhglywarawytaqrropfrgxrekoseyapnjrboulpsjohqryipxwwopgoyemwroaoojsrttogafpmxfecsokgqiyhcono";
	cout<<removeRepeating(test)<<endl;
	auto end = chrono::high_resolution_clock::now();
	
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	cout<<endl<<duration.count()<<" ms"<<endl;
	
	Time Taken: 1004 ms
*/
	
	return 0;
}

/*
OUTPUT:
jaidher
a
a
QWERTY
ABA

*/
