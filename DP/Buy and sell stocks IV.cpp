class Solution {
public:
    int solve(int index,int operationsNo,int k,vector<int> &prices){
        //base case
        if(index==prices.size())
            return 0;
        if(operationsNo==2*k)
            return 0;

        int profit=0;
        if(operationsNo%2==0)
        {
            //buy karna allowed
            int buyKaro=-prices[index]+solve(index+1,operationsNo+1,k,prices);
            int skipKaro=0+solve(index+1,operationsNo,k,prices);
            profit=max(buyKaro,skipKaro);
        }
        else{
            int sellKaro=prices[index]+solve(index+1,operationsNo+1,k,prices);
            int skipKaro=0+solve(index+1,operationsNo,k,prices);
            profit=max(sellKaro,skipKaro);
        }
        return profit;
    }

    int solveMem(int index,int operationsNo,int k,vector<int> &prices,vector<vector<int>>&dp){
        //base case
        if(index==prices.size())
            return 0;
        if(operationsNo==2*k)
            return 0;

        if(dp[index][operationsNo]!=-1)
            return dp[index][operationsNo];
        int profit=0;
        if(operationsNo%2==0)
        {
            //buy karna allowed
            int buyKaro=-prices[index]+solveMem(index+1,operationsNo+1,k,prices,dp);
            int skipKaro=0+solveMem(index+1,operationsNo,k,prices,dp);
            profit=max(buyKaro,skipKaro);
        }
        else{
            int sellKaro=prices[index]+solveMem(index+1,operationsNo+1,k,prices,dp);
            int skipKaro=0+solveMem(index+1,operationsNo,k,prices,dp);
            profit=max(sellKaro,skipKaro);
        }
        return dp[index][operationsNo]=profit;
    }

    int solveTab(vector<int> &prices,int k){
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));

        for(int index=n-1;index>=0;index--){
            for(int operationsNo=0;operationsNo<2*k;operationsNo++){
                int profit=0;
                if(operationsNo%2==0)
                {
                    //buy karna allowed
                    int buyKaro=-prices[index]+dp[index+1][operationsNo+1];
                    int skipKaro=0+dp[index+1][operationsNo];
                    profit=max(buyKaro,skipKaro);
                }
                else{
                    int sellKaro=prices[index]+dp[index+1][operationsNo+1];
                    int skipKaro=0+dp[index+1][operationsNo];
                    profit=max(sellKaro,skipKaro);
                }
                dp[index][operationsNo]=profit;
            }
        }
        return dp[0][0];
    }


    int spaceOP(vector<int> &prices,int k){
        int n=prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));

        vector<int> curr(2*k+1,0);
        vector<int> next(2*k+1,0);

        for(int index=n-1;index>=0;index--){
            for(int operationsNo=0;operationsNo<2*k;operationsNo++){
                int profit=0;
                if(operationsNo%2==0)
                {
                    //buy karna allowed
                    int buyKaro=-prices[index]+next[operationsNo+1];
                    int skipKaro=0+next[operationsNo];
                    profit=max(buyKaro,skipKaro);
                }
                else{
                    int sellKaro=prices[index]+next[operationsNo+1];
                    int skipKaro=0+next[operationsNo];
                    profit=max(sellKaro,skipKaro);
                }
                curr[operationsNo]=profit;
            }
            next=curr;
        }
        return next[0];
    }
    
    
    
    //index and operationsNo is changing - 2d dp


    int maxProfit(int k, vector<int>& prices) {
        // return solve(0,0,k,prices);
        // int n=prices.size();

        // vector<vector<int>> dp(n,vector<int>(2*k,-1));
        // return solveMem(0,0,k,prices,dp);

        // return solveTab(prices,k);

        return spaceOP(prices,k);
    }
};
