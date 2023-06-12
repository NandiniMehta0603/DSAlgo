#include <bits/stdc++.h> 

long long solve(vector<int> nums){
    long long n=nums.size();
    long long prev1=nums[n-1];
    long long prev2=0;

    for(int i=n-2;i>=0;i--){
        long long curr=max(prev2+nums[i],prev1);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    if (valueInHouse.size()==1){
        return valueInHouse[0];
    }
    //taking care of the edge cases
    vector<int> case1;
    vector<int> case2;
    for(int i=0;i<valueInHouse.size();i++){
        if(i!=valueInHouse.size()-1){
            case1.push_back(valueInHouse[i]);
        }
        if(i!=0){
            case2.push_back(valueInHouse[i]);
        }
    }
    long long ans1=solve(case1);
    long long ans2=solve(case2);
    long long ans=max(ans1,ans2);

    return ans;
}
