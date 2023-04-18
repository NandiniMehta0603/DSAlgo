class Solution {
public:
    int solve(vector<int> &cost, int n){
        //base case
        if(n==0)
            return cost[0];
        if(n==1)
            return cost[1];
        
        int ans=cost[n]+min(solve(cost,n-1),solve(cost,n-2));
        return ans;
    }

    //using memoization
    int solve2(vector<int> &cost,int n,vector<int> &dp){
        //base case
        if(n==0 || n==1){
            return cost[n];
        }
        //step3:
        if(dp[n]!=-1)
            return dp[n];


        //step2:
        dp[n]=cost[n]+min(solve2(cost,n-1,dp),solve2(cost,n-2,dp));
        return dp[n];
    }

    //using tabulation
    int solve3(vector<int> &cost,int n){
        //step1: creation of dp array
        vector<int> dp(n+1);
        //step2: base case analysis
        dp[0]=cost[0];
        dp[1]=cost[1];

        //step3:
        for(int i=2;i<n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }


    //space optimization
    int solve4(vector<int> &cost,int n){
        //step1: create variables 
        int prev1=cost[1];
        int prev2=cost[0];

        //step2:
        for(int i=2;i<n;i++){
            int curr=cost[i]+min(prev1,prev2);
            prev2=prev1;
            prev1=curr;
        }
        return min(prev1,prev2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        // int n=cost.size();
        // int ans=min(solve(cost,n-1),solve(cost,n-2));
        // return ans;

        // int n=cost.size();
        // vector<int> dp(n+1,-1);
        // //step1:
        // int ans=min(solve2(cost,n-1,dp),solve2(cost,n-2,dp));
        // return ans;


        // int n=cost.size();
        // return solve3(cost,n);

        int n=cost.size();
        return solve4(cost,n);

    }
};

