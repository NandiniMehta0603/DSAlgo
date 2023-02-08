//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 

{

    private:
    //function to find if the division of pages is right
    //we use binary search only when we want to shorten the search space
    bool isPossible(int A[],int N,int M,int mid){

        int studentCount=1;
        int sumOfPages=0;
        for(int i=0;i<N;i++){
            //Assigning pages the student

            if(sumOfPages+A[i]<=mid){

                sumOfPages+=A[i];
            }

            else{
                studentCount++;

                //if the studentcount becomes greater than the total no of students
                //If the Array element is greater than the mid :- so we cannot assign the book to a student
                //so return false

                if(studentCount>M||A[i]>mid)return false;

                sumOfPages=A[i];

            }
            if(studentCount>M){
                return false;
            }
        }

        return true;

    }

    public:

    //Function to find minimum number of pages.

    int findPages(int A[], int N, int M) 

    {

        //No of students are more than the no of books

        if(M>N)return -1;

        //search space is between 0 to sum of the array elements

        int start=0;
        int end=0;
        for(int i=0;i<N;i++)end+=A[i];
        int mid=start+(end-start)/2;
        int ans=-1;
        while(start<=end){

            if(isPossible(A,N,M,mid)){

                //store the ans

                ans=mid;

                //as we requried the minimum ans so going into the left-part
                //ie mid can be a possible ans
                //this means that values to the right of mid are all possible solutions
                //in order to reach the most optimal/closest value we need to reduce search space
                //so search in the left part
                end=mid-1;

            }

            else{

            //this means that answers to the left of mid are all discarded and are completely wrong
            //so discarding that portion, we only search for the solution in the right part of mid
                start=mid+1;
            }
            mid=start+(end-start)/2;
        }
        return ans;

    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
