class Solution {
public:
    int solve(int n){
        if(n<=1){
            return 1;
        }

        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=solve(i-1)*solve(n-i);
        }
        return ans;
    }

    int solve1(int n,vector<int> &dp){
        //base case
        if(n<=1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=solve1(i-1,dp)*solve1(n-i,dp);
        }
        return dp[n]=ans;
    }

    int solve2(int n){
        vector<int> dp(n+1,0);
        dp[0]=dp[1]=1;
        int ans=0;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i]+=dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }

    int numTrees(int n) {
        // return solve(n);

        // vector<int> dp(n+1,-1);
        // return solve1(n,dp);

        return solve2(n);
    }
};
