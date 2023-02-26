//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

//steps:for O(n) time complexity, use stack..compare all elements one by one 
//then check for potential elements left

class Solution 
{
    public:
    //function to check if a knows b
    bool celeb(vector<vector<int>>& M,int a,int b,int n){
        if(M[a][b]==1){
            return true;
        }
        else{
            return false;
        }
    }
    
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        //step1: push all the candidates in the stack
        for(int i=0;i<n;i++){
            st.push(i);
        }
        
        while(st.size()>1){
            //take top 2 out of the stack, then compare them
            int a=st.top();
            st.pop();
            
            int b=st.top();
            st.pop();
            
            //compare both the numbers
            if(celeb(M,a,b,n)){
                st.push(b);//means b is a potential candidate
            }
            else if(celeb(M,b,a,n)){
                st.push(a);
            }
        }
        int ans=st.top();
        
        //row check- the celeb row should all be 0
        int rowCount=0;
        for(int i=0;i<n;i++){
            if(M[ans][i]==0){
                rowCount++;
            }
        }
        if(rowCount!=n){
            return -1;
        }
        
        //col check- the celeb column should be all 1 except diagonal
        int colCount=0;
        for(int i=0;i<n;i++){
            if(M[i][ans]==1){
                colCount++;
            }
        }
        if(colCount!=n-1){
            return -1;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends
