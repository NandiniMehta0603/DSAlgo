#include <bits/stdc++.h> 
int solve1(vector<int> &num,int x){
    //base case
    if(x==0){
        return 0;
    }
    if(x<0)
    {
        return INT_MAX;
    }
    int mini=INT_MAX;
    for(int i=0;i<num.size();i++){
        int ans=solve1(num,x-num[i]);
        if(ans!=INT_MAX)
            mini=min(mini,1+ans);
    }
    return mini;
}

int solve2(vector<int> &num,int x,vector<int> &dp){
    //base case
    if(x==0)
        return 0;
    if(x<0)
        return INT_MAX;

    //step3:
    if(dp[x]!=-1)
        return dp[x];

    //step2: initialising the dp array
    int mini=INT_MAX;
    for(int i=0;i<num.size();i++){
        int ans=solve2(num,x-num[i],dp);
        if(ans!=INT_MAX)
            mini=min(mini,ans+1);
    }
    dp[x]=mini;
    return mini;
    
}

int solve3(vector<int> &num,int x){
    vector<int> dp(x+1,INT_MAX);
    dp[0]=0;

    for(int i=1;i<=x;i++){
        for(int j=0;j<num.size();j++){
            if(i-num[j]>=0 && dp[i-num[j]]!=INT_MAX){
                dp[i]=min(dp[i],1+dp[i-num[j]]);
            }
        }
    }
    if(dp[x]==INT_MAX)
        return -1;

    return dp[x];
}

int minimumElements(vector<int> &num, int x)
{

        // int ans=solve1(num,x);
        // if(ans==INT_MAX)
        //     return -1;
        // return ans;

        // vector<int> dp(x+1,-1);
        // int ans=solve2(num,x,dp);
        // if(ans==INT_MAX)
        //     return -1;
        // return ans;
    
        return solve3(num,x);
    
}
