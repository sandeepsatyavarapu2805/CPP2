// BESTBUY AND SELL ALGORITHM

#include<iostream>
#include<vector>
using namespace std;

int main(){

int n;
cout<<"Enter n : ";
cin>>n;

vector<int> arr(n);
for(int i = 0; i < n; i++){
    cout<<"Enter "<<i<<"th index element : ";
    cin>>arr[i];
}

int maxprofit = 0;
int bestbuy = arr[0];

for(int i=0;i<n;i++){
    if(bestbuy<arr[i]){
        maxprofit = max(maxprofit,arr[i]-bestbuy);
    }
    bestbuy = min(bestbuy,arr[i]);
}

cout<<"The price of the best buying price is "<<bestbuy<<" and the best selling price is "<<maxprofit+bestbuy<<" so the result profit is "<<maxprofit;

return 0;
}