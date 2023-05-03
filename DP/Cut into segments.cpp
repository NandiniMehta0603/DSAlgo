#include<limits.h>

int solve(int n,int x,int y,int z){
    //base case
    if(n==0){
        return 0;
    }
    if(n<0){
        return INT_MIN;
    }

    int a=solve(n-x,x,y,z)+1;
    int b=solve(n-y,x,y,z)+1;
    int c=solve(n-z,x,y,z)+1;
    return max(a,max(b,c));
}


int solveMem(int n,vector<int> &dp,int x,int y,int z){
    //base case
    if(n==0)
        return 0;
    if(n<0){
        return INT_MIN;
    }
    //step3:
    if(dp[n]!=-1){
        return dp[n];
    }

    //step2: fill the d array
    int a=solveMem(n-x,dp,x,y,z)+1;
    int b=solveMem(n-y,dp,x,y,z)+1;
    int c=solveMem(n-z,dp,x,y,z)+1;

    dp[n]=max(a,max(a,b));
    return dp[n];
}

int solveTab(int n,int x,int y,int z){
    vector<int> dp(n+1,INT_MIN);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        if(i-x>=0){
            dp[i]=max(dp[i],dp[i-x]+1);
        }
        if(i-y>=0){
            dp[i]=max(dp[i],dp[i-y]+1);
        }
        if(i-z>=0){
            dp[i]=max(dp[i],dp[i-z]+1);
        }
    }
    if(dp[n]<0)
        return 0;
    else    
        return dp[n];
}
int cutSegments(int n, int x, int y, int z) {
    // int ans=solve(n,x,y,z);
    // if(ans<0)
    //     return 0;
    // else
    //     return ans;

//     vector<int> dp(n+1,-1);//n+1 bec its 0 based indexing and we want ans to be stored in nth index itself
//     int ans=solveMem(n,x,y,z,dp);
//     if(ans<0)
//         return 0;
//     else
//         return ans;

    // vector<int> dp(n+1,-1);
    // int ans=solveMem(n,dp,x,y,z);
    // if(ans<0){
    //     return 0;
    // }
    // else{
    //     return ans;
    // }
    return solveTab(n,x,y,z);

}
