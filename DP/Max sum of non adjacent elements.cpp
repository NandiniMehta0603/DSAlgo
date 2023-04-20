#include <bits/stdc++.h> 
//we are solving in right to left order

int solve1(vector<int> &num,int i){
    //base case
    if(i>=num.size())
        return 0;
    int incl=solve1(num,i+2)+num[i];
    int excl=solve1(num,i+1);
    return max(incl,excl);
}

int solve2(vector<int> &num,int i,vector<int> &dp){
    //base case
    if(i>=num.size())
        return 0;
    
    //step3:
    if(dp[i]!=-1)
        return dp[i];

    //step2: fill the dp array
    int incl=solve2(num,i+2,dp)+num[i];
    int excl=solve2(num,i+1,dp);
    dp[i]=max(incl,excl);
    return dp[i];
}

int solve3(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n,0);
    dp[0]=nums[0];

    for(int i=1;i<n;i++){
        int incl=dp[i-2]+nums[i];
        int excl=dp[i-1];
        dp[i]=max(incl,excl);
    }
    return dp[n-1];
}

int solve4(vector<int> &nums){
    int n=nums.size();

    int prev2=0;
    int prev1=nums[0];

    //starting from index 1
    for(int i=1;i<n;i++){
        int incl=prev2+nums[i];
        int excl=prev1+0;
        int curr=max(incl,excl);
        //update the pointers
        prev2=prev1;
        prev1=curr;
    }
    return prev1;

    
}

int maximumNonAdjacentSum(vector<int> &nums){


    // int i=0;
    // int ans=solve1(nums,i);
    // return ans;

    // vector<int> dp(nums.size(),-1);
    // int i=0;
    // return solve2(nums,i,dp);

    // return solve3(nums);

    return solve4(nums);
}
