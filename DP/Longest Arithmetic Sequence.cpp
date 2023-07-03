//User function template for C++

class Solution{   
public:
    //to do the backward check
    int solve(int index,int diff, int A[]){
        //base case
        if(index<0){
            return 0;
        }
        
        int ans=0;//check the backward length
        for(int j=index-1;j>=0;j--){
            if(A[index]-A[j]==diff){
                ans=max(ans,1+solve(j,diff,A));
            }
        }
        return ans;
        
    }
    
    //top down solution is not able to solve this problem 
    int solveMem(int index,int diff, int A[],unordered_map<int,int> dp[]){
        //base case
        if(index<0){
            return 0;
        }
        
        //step3:
        if(dp[index].count(diff))
            return dp[index][diff];
        
        int ans=0;//check the backward length
        for(int j=index-1;j>=0;j--){
            if(A[index]-A[j]==diff){
                ans=max(ans,1+solveMem(j,diff,A,dp));
            }
        }
        return dp[index][diff]=ans;
        
    }
    
    int lengthOfLongestAP(int A[], int n) {
        // //base case
        // if(n<=2){
        //     return n;
        // }
        // int ans=0;
        
        // //to find the last 2 elements of the array
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         ans=max(ans,2+solve(i,A[j]-A[i],A));
        //         //we are adding 2 here bec wr have initially already included
        //         //last 2 elements of the sequence and rest all elments are found
        //         //by solve function...so we have to add 2 to solve part to get the correct ans
                
        //     }
        // }
        
        
        // unordered_map<int,int> dp[n+1];
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         ans=max(ans,2+solveMem(i,A[j]-A[i],A,dp));
                
        //     }
        // }
        
        // return ans;
        
        
        
        //bottom up approach
        //base case
        if(n<=2)
            return n;
        
        int ans=0;
        unordered_map<int,int> dp[n+1];
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff=A[i]-A[j];
                int cnt=1;//abhi tak AP mei kitne elements pade hai
                
                
                //check if ans is already present
                if(dp[j].count(diff))
                    cnt=dp[j][diff];//count ke andar peeche ka ans toh aa chuka hai
                    //at i index ans ko update karna hai
                    
                dp[i][diff]=1+cnt; //i index ko bhi toh ans mei include karna hai
                ans=max(ans,dp[i][diff]);
            }
                
        }
        return ans;
    }
};
