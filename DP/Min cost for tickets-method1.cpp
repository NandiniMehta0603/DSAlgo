int solve(int n, vector<int> &days, vector<int> &cost,int index){
    //base case
    if(index>=n){
        return 0;
    }

    int option1=cost[0]+solve(n,days,cost,index+1);

    int i;
    for(i=index;i<n && days[i]<days[index]+7;i++);

    int option2=cost[1]+solve(n,days,cost,i);

    for(i=index;i<n && days[i]<days[index]+30;i++);

    int option3=cost[2]+solve(n,days,cost,i);

    return min(option1,min(option2,option3));
}

int solve1(int n, vector<int> &days, vector<int> &cost,int index,vector<int> &dp){
    if(index>=n){
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    int option1=cost[0]+solve1(n,days,cost,index+1,dp);

    int i;
    for(i=index;i<n && days[i]<days[index]+7;i++);
    int option2=cost[1]+solve1(n,days,cost,i,dp);

    for(i=index;i<n && days[i]<days[index]+30;i++);
    int option3=cost[2]+solve1(n,days,cost,i,dp);

    dp[index]=min(option1,min(option2,option3));
    return dp[index];
}

int solve2(int n, vector<int> &days, vector<int> &cost){
    vector<int> dp(n+1, INT_MAX);
    
    dp[n]=0;
    for(int k=n-1;k>=0;k--){
        int option1=cost[0]+dp[k+1];

        int i;
        for(i=k;i<n && days[i]<days[k]+7;i++);
        int option2=cost[1]+dp[i];

        for(i=k;i<n && days[i]<days[k]+7;i++);
        int option3=cost[2]+dp[i];

        dp[k]=min(option1,min(option2,option3));
    }
    return dp[0];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // int ans=solve(n,days,cost,0);
    // return ans;

    // vector<int> dp(n+1,-1);
    // return solve1(n,days,cost,0,dp);

    return solve2(n,days,cost);
}
