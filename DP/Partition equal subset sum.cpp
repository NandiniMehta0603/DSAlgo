// User function Template for C++

class Solution{
public:

    bool solve(int target, int index, int arr[], int N)
    {
        // Base Case
        if(index >= N)
            return 0;
            
        if(target < 0)
            return 0;
            
        if(target == 0)
            return 1;
            
        bool include = solve(target - arr[index], index+1, arr, N);
        bool exclude = solve(target - 0, index+1, arr, N);
        
        return (include or exclude);
    }
    
    bool solveMem(int target, int index, int arr[], int N, vector<vector<int>> &dp)
    {
        // Base Case
        if(index >= N)
            return 0;
            
        if(target < 0)
            return 0;
            
        if(target == 0)
            return 1;
            
        if(dp[index][target] != -1)
            return dp[index][target];
            
        bool include = solveMem(target - arr[index], index+1, arr, N, dp);
        bool exclude = solveMem(target - 0, index+1, arr, N, dp);
        
        return dp[index][target] = (include or exclude);
    }
    
    bool solveTab(int total, int arr[], int N)
    {
        vector<vector<int>> dp(N+1, vector<int> (total+1, 0));
        
        for(int i=0; i<=N; i++){
            dp[i][0] = 1;
        }
        
        for(int index = N-1; index >= 0; index--){
            for(int target = 0; target <= (total/2); target++){
                
                bool include = 0;
                
                if(target - arr[index] >=0)
                    include = dp[index+1][target - arr[index]];
                    
                bool exclude = dp[index+1][target - 0];
                
                dp[index][target] = (include or exclude);
            }
        }
        
        return dp[0][total/2];
    }
    
    bool solveSpaceOP(int total, int arr[], int N)
    {
        vector<int> curr(total/2 +1);
        vector<int> next(total/2 +1);
        
        curr[0] = 1;
        next[0] = 1;
        
        for(int index = N-1; index >= 0; index--){
            for(int target = 0; target <= (total/2); target++){
                
                bool include = 0;
                
                if(target - arr[index] >=0)
                    include = next[target - arr[index]];
                    
                bool exclude = next[target - 0];
                
                curr[target] = (include or exclude);
            }
            
            next = curr;
        }
        
        return next[total/2];
    }
    
    int equalPartition(int N, int arr[])
    {
        int total = 0;
        
        for(int i=0; i<N; i++){
            total += arr[i];
        }
        
        if(total & 1)
            return 0;
        
        int target = total / 2;
        
        // RECURSION
        /*
        return solve(target, 0, arr, N);
        */
        
        // RECURSION + MEMOIZATION
        
        // vector<vector<int>> dp(target+1, vector<int> (N+1, -1));
        /*
        vector<vector<int>> dp(N+1, vector<int> (target+1, -1));
        return solveMem(target, 0, arr, N, dp); */
        
        // TABULATION
        // return solveTab(total, arr, N);
        
        // SPACE OPTIMIZATION
        return solveSpaceOP(total, arr, N);
    }
};
