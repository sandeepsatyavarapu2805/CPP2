//  MOORE'S VOTING ALGORITHM

#include <iostream>
#include<vector>
using namespace std;

int main() {
int n;
cout<<"Enter n : ";
cin>>n;

vector<int> nums(n);

for(int i=0;i<n;i++) {
    cout<<"Enter "<<i<<"th index element";
    cin>>nums[i];
}

int count = 0,maxnum=0;

for(int i=0;i<n;i++) {
    if(count == 0){
        maxnum = nums[i];
        count = 1;
    }else if(nums[i] == maxnum){
        count++;
    }else{
        count--;
    }
}

count = 0;
for (int x : nums) {
    if (x == maxnum){
        count++;
    }
}

if(count>(n/2)){
    cout<<"Majority Element is"<<maxnum<<"which is present more than "<<n/2<<" times"<<endl;
}else{
    cout<<"There is no majority element in the given vector"<<endl;
}

return 0;
}