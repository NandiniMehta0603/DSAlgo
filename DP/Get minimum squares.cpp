//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int solve(int n,vector<int> numbers){
	    //base case
	    if(n==0){
	        return 0;
	    }
	    else if(n<0){
	        return INT_MAX;
	    }
	    int mini=INT_MAX;
	    for(int i=0;i<numbers.size();i++){
	        int ans=solve(n-numbers[i],numbers);
	        if(ans!=INT_MAX)
	            mini=min(mini,ans+1);
	    }
	    return mini;
	}
	
	int solve1(int n,vector<int> numbers,vector<int> &dp){
	    //base case
	    if(n==0){
	        return 0;
	    }
	    else if(n<0){
	        return INT_MAX;
	    }
	    
	    if(dp[n]!=-1){
	        return dp[n];
	    }
	    int mini=INT_MAX;
	    for(int i=0;i<numbers.size();i++){
	        int ans=solve1(n-numbers[i],numbers,dp);
	        if(ans!=INT_MAX){
	            mini=min(mini,ans+1);
	        }
	         
	    }
	    dp[n]=mini;
	    return dp[n];
	}
	int solve2(int n,vector<int> numbers){
	    vector<int> dp(n+1,0);
	    
	    //base case
	    dp[0]=0;
	    
	    for(int i=1;i<=n;i++){
	        int mini=INT_MAX;
	        for(int j=0;j<numbers.size();j++){
	            if(i-numbers[j]>=0){
	                int ans=dp[i-numbers[j]]+1; 
	                mini=min(ans,mini);
	            }
	        }
	        dp[i]=mini;
	    }
	    if(dp[n]==INT_MAX){
	        return -1;
	    }
	    else{
	        return dp[n];
	    }
	}
	
	int MinSquares(int n)
	{
	    if(n==1){
	        return 1;
	    }
	    vector<int> numbers;
	    for(int i=1;i<=n;i++){
	        if(i*i<=n){
	            numbers.push_back(i*i);
	        }
	        else{
	            break;
	        }
	    }
	   // int ans=solve(n,numbers);
	   // if(ans==INT_MAX){
	   //     return -1;
	   // }
	   // else{
	   //     return ans;
	   // }
	   
	   //vector<int> dp(n+1,-1);
	   //int ans=solve1(n,numbers,dp);
	   //if(ans==INT_MAX){
	   //    return -1;
	   //}
	   //else{
	   //    return ans;
	   //}
	   
	   return solve2(n,numbers);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
