// Fractional Knapsack Problem using Greedy Method
//Using Lambda Functions for sort

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std; 

struct product{
	int weight; 
	int profit; 
	float p_by_w; 
	float fraction; 
};

typedef struct product product; 

// bool inline comp(product &product1, product &product2){
// 	return (product1.p_by_w) > (product2.p_by_w);
// }

void print(vector<product> products){
	for(product p:products)
		cout<<p.weight<<"  "<<p.profit<<"  "<<p.p_by_w<<"  "<<p.fraction<<endl; 
	cout<<endl<<endl;
}

int main(){
	vector<product> products;
	
	int n;		//Number of Products
	cin>>n;
	
	for(int i=0;i<n;++i){
		cout<<"Enter Weight of Object: ";
		int weight; cin>>weight; 
		cout<<"Enter Profit of Object: "; 
		int profit; cin>>profit; 
		product new_product = { weight, profit, ((profit * 1.0)/(weight * 1.0)) };  
		products.push_back(new_product);
	}
	
	// sort(products.begin(), products.end(), comp); 
	sort(products.begin(), products.end(), [](product &product1, product &product2){ return (product1.p_by_w) > (product2.p_by_w); }); 
	
	int m; //Knapsack Capacity; 
	cout<<"Enter Knapsack Capacity: ";
	cin>>m;  

	print(products); 
	
	for(product &prod:products){
		if(m == 0)
			prod.fraction = 0.0; 	
		else if(m >= prod.weight){
			prod.fraction = 1.0; 
			m -= (prod.weight); 
		}else{
			prod.fraction = (m * 1.0) / (prod.weight * 1.0);
			m = 0;   
		}
	}
	
	
	print(products); 
	
	float total_profit = 0.0; 
	
	for(product prod:products)
		total_profit += (prod.weight * prod.fraction) * prod.p_by_w; 
		
	cout<<"Total Profit: "<<total_profit<<endl; 	
	
	return 0;
}
