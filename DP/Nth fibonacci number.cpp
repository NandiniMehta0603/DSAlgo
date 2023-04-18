#include<bits/stdc++.h>
using namespace std;
#include<vector>
//using recusrion-->keep storing the result of each ele using recursion
int fib(int n,vector<int> &dp){
    //base case
    //step1:
    if(n==1 || n==0){
        return n;
    }

    //step3: 
    if(dp[n]!=-1){
        return dp[n];
    }

    //step2:
    dp[n]=fib(n-1,dp)+fib(n-2,dp);
    return dp[n];
}

// int main()
// {
//         int n;
//         cin>>n;
        
//         vector<int> dp(n+1);
//         for(int i=0;i<=n;i++){
//             dp[i]=-1;
//         }
//         cout<<fib(n,dp)<<endl;
//         return 0;
// }

//using tabulation
// int main(){
//     int n;
//     cin>>n;
//     //step1:
//     vector<int> dp(n+1);

//     //step2:
//     dp[1]=1;
//     dp[0]=0;

//     //step3:
//     for(int i=2;i<=n;i++){
//         dp[i]=dp[i-1]+dp[i-2];
//     }
//     cout<<dp[n]<<endl;
// }

//using space optimisation
int main(){
    int n;
    cin>>n;
    
    int prev1=1;
    int prev2=0;
    
    //edge case
    if(n==0)
        return prev2;
    // if(n==1)
    //     return prev1;
    for(int i=2;i<=n;i++){
        int curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    cout<<prev1<<endl;
    return 0;
}

