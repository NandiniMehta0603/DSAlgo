#define MOD 1000000007
#include<vector>
long long solve1(int n,vector<long long>&dp){
    //base case
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    
    //step3: 
    if(dp[n]!=-1)
        return dp[n];
    
    dp[n]=(((n-1)%MOD)*(((solve1(n-1,dp))%MOD)+((solve1(n-2,dp))%MOD)))%MOD;
    return dp[n];
    
}

//using tabulation
long long solve2(int n){
    vector<long long> dp(n+1,0);

    //base case
    dp[1]=0;
    dp[2]=1;

    for(int i=3;i<=n;i++){
        long long first=dp[i-1]%MOD;
        long long second=dp[i-2]%MOD;
        long long sum=(first+second)%MOD;
        
        long long ans=((i-1)*sum)%MOD;
        dp[i]=ans;
    }
    return dp[n];
}


long long solve3(int n){
    long long prev2=0;
    long long prev1=1;
    for(int i=3;i<=n;i++){
        long long first=prev1%MOD;
        long long second=prev2%MOD;
        long long sum=(first+second)%MOD;

        long long ans=((i-1)*sum)%MOD;
        long long curr=ans;
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}



long long int countDerangements(int n) {
    // if(n==1)  
    //     return 0;
    // if(n==2)
    //     return 1;
    // int ans=(((n-1)%MOD)*(((countDerangements(n-1))%MOD)+((countDerangements(n-2))%MOD)))%MOD;
    // return ans;


    // vector<long long> dp(n+1,-1);
    // long long ans=solve1(n,dp);
    // return ans;

    // return solve2(n);

    return solve3(n);
    
}
