class Solution {
public:
    int solve(int index,int buy,vector<int> &prices,int fee,vector<vector<int>> &dp){
        //base case
        if(index==prices.size()){
            return 0;
        }

        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        int profit=0;
        if(buy){
            int buyKaro= -prices[index]+solve(index+1,0,prices,fee,dp);
            int ignoreKaro=0+solve(index+1,1,prices,fee,dp);
            profit=max(buyKaro,ignoreKaro);
        }
        else{
            int sellKaro= +prices[index]+solve(index+1,1,prices,fee,dp)-fee;
            int ignoreKaro=0+solve(index+1,0,prices,fee,dp);
            profit=max(sellKaro,ignoreKaro);
        }

        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));

        return solve(0,1,prices,fee,dp);
    }
};
