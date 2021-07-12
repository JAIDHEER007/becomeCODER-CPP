//Question 9
//Grouping Transactions by Items' Names

#include<bits/stdc++.h>
#define NeedForSpeed ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

vector<string> groupTransactions(vector<string> transactions){
	map<string,int> table;
	for(string transaction:transactions)
		++table[transaction];
	vector<string> result;
	for(auto it:table)
		result.push_back((it.first)+" "+to_string(it.second));
	return result;
}
int main(){
	NeedForSpeed;
	
	int n;
	cin>>n;
	vector<string> transactions;
	
	for(int i=0;i<n;++i){
		string transaction; cin>>transaction;
		transactions.push_back(transaction);
	}
	
	vector<string> groupedTransactions = groupTransactions(transactions);
	
	for(string transactionDetails:groupedTransactions)
		cout<<transactionDetails<<endl;
	
	return 0;
}



