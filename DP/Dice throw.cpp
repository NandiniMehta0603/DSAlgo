//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long solve(int dice, int faces, int target){
        //base case
        if(target<0){
            return 0;
        }
        if(dice==0 && target!=0){
            return 0;
        }
        if(dice ==0 && target==0){
            return 1;
        }
        
        long long ans=0;
        for(int i=1;i<=faces;i++){
            ans=ans+solve(dice-1,faces,target-i);
        }
        return ans;
    }
    
    long long solve1(int dice,int faces,int target,vector<vector<long long>> &dp){
        if(target<0){
            return 0;
        }
        if(dice==0 && target!=0){
            return 0;
        }
        if(target==0 && dice==0){
            return 1;
        }
        if(dp[dice][target]!=-1){
            return dp[dice][target];
        }
        
        long long ans=0;
        for(int i=1;i<=faces;i++){
            ans=ans+solve1(dice-1,faces,target-i,dp);
        }
        dp[dice][target]=ans;
        return dp[dice][target];
    }
    
    long long solve2(int N, int M, int X){
        vector<vector<long long>> dp(N+1, vector<long long> (X+1,0));
        
        //base case
        dp[0][0]=1;
        for(int dice=1;dice<=N;dice++){
            for(int target=1;target<=X;target++){
                long long ans=0;
                for(int face=1;face<=M;face++){
                    if(target-face>=0)
                        ans+=dp[dice-1][target-face];
                }
                dp[dice][target]=ans;
            }
        }
        return dp[N][X];
    }
    
    long long solve3(int N,int M,int X){
        vector<long long> curr(X+1,0);
        vector<long long> prev(X+1,0);
        prev[0]=1;
        
        for(int dice=1;dice<=N;dice++){
            for(int target=1;target<=X;target++){
                long long ans=0;
                for(int face=1;face<=M;face++){
                    if(target-face>=0)
                        ans+=prev[target-face];
                }
                curr[target]=ans;
            }
            prev=curr;
        }
        return prev[X];
    }
    long long noOfWays(int M , int N , int X) {
        //M-> no of options for each dice 
        //N-> no of dice
        //X-> target sum
        
        
        // return solve(N,M,X);
        
        
        // vector<vector<long long>> dp(N+1, vector<long long> (X+1,-1));
        // return  solve1(N,M,X,dp);
        
        // return solve2(N,M,X);
        
        return solve3(N,M,X);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends
