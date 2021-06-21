//LeetCode: 1154. Day of the Year
//Link: https://leetcode.com/problems/day-of-the-year/

#include<bits/stdc++.h>
using namespace std;

bool isLeapYear(int year){
	if(year % 400 == 0)
		return true;
	if(year % 100 == 0)
		return false;
	if(year % 4 == 0)
		return true;
	return false;
}

int dayOfYear(string date){
	int year = stoi(date.substr(0,4));
	int month = stoi(date.substr(5,2));
	int day = stoi(date.substr(8,2));
	
	int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int Cmonths[] = {31,59,90,120,151,181,212,243,273,304,334,365};
	
	return (Cmonths[month-1]-(months[month-1]-day))+(((isLeapYear(year))&&(month>2))?(1):(0));
}

int main(){
	cout<<dayOfYear("2019-01-09")<<endl;
	cout<<dayOfYear("2003-03-01")<<endl;
	cout<<dayOfYear("2004-03-01")<<endl;
	cout<<dayOfYear("2008-10-10")<<endl;
	return 0;
}

