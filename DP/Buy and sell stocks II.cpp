class Solution {
public:
    int solve(int index,int buy,vector<int> &prices){
        //base case
        if(index==prices.size()){
            return 0;
        }
        int profit=0;
        if(buy){
            int buyKaro=-prices[index]+solve(index+1,0,prices);
            int ignoreKaro=0+solve(index+1,1,prices);
            profit=max(buyKaro,ignoreKaro);
        }
        else{
            int sellKaro=+prices[index]+solve(index+1,1,prices);
            int ignoreKaro=0+solve(index+1,0,prices);
            profit=max(sellKaro,ignoreKaro);
        }
        return profit;
    }
    int solve1(int index,int buy,vector<int> &prices,vector<vector<int>> &dp){
        //base case
        if(index==prices.size()){
            return 0;
        }
        int profit=0;
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        if(buy){
            int buyKaro=-prices[index]+solve1(index+1,0,prices,dp);
            int ignoreKaro=0+solve1(index+1,1,prices,dp);
            profit=max(buyKaro,ignoreKaro);
        }
        else{
            int sellKaro=+prices[index]+solve1(index+1,1,prices,dp);
            int ignoreKaro=0+solve1(index+1,0,prices,dp);
            profit=max(sellKaro,ignoreKaro);
        }
        dp[index][buy]=profit;
        return dp[index][buy];
    }

    int solve2(vector<int> &prices){
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2,0));

        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    int buyKaro= -prices[index]+dp[index+1][0];
                    int ignoreKaro= 0+ dp[index+1][1];
                    profit=max(buyKaro,ignoreKaro);
                }
                else{
                    int sellKaro= +prices[index]+dp[index+1][1];
                    int ignoreKaro= 0+ dp[index+1][0];
                    profit=max(sellKaro,ignoreKaro);
                }
                dp[index][buy]=profit;
            }
        }
        return dp[0][1];
    }

    int solve3(vector<int> &prices){
        int n=prices.size();

        vector<int> curr(2,0);
        vector<int> next(2,0);

        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    int buyKaro= -prices[index]+next[0];
                    int ignoreKaro= 0+ next[1];
                    profit=max(buyKaro,ignoreKaro);
                }
                else{
                    int sellKaro= +prices[index]+next[1];
                    int ignoreKaro= 0+ next[0];
                    profit=max(sellKaro,ignoreKaro);
                }
                curr[buy]=profit;
            }
            next=curr;
        }
        return next[1];
    }

    int maxProfit(vector<int>& prices) {
        // return solve(0,1,prices);
        int n=prices.size();
        // vector<vector<int>> dp(n+1,vector<int> (2,-1));
        // return solve1(0,1,prices,dp);

        return solve2(prices);
    }
};
