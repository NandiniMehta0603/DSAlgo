//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

//steps: take a queue of size K and process the queue at every step
//use the concept of sliding window

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
    //step1: take first window
    deque<int> dq;//we have to push the index value position of the negative numbers
    vector<long long> ans;
    for(int i=0;i<K;i++){
        if(A[i]<0){
            dq.push_back(i);
        }
    }
    //processing for the first window
    if(dq.size()>0){
        ans.push_back(A[dq.front()]);
    }
    else{
        ans.push_back(0);
    }
    
    //processing for the next windows
    for(int i=K;i<N;i++){
        //as we have to maintain dq of size K only, so delete the excessive members
        if(dq.size()>0 && i-dq.front()>=K){
            dq.pop_front();
        }
        //add new member if condition is satisfied
        if(A[i]<0){
            dq.push_back(i);
        }
        
        //process for the nest windows 
        if(dq.size()>0){
            ans.push_back(A[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
    }
    return ans;
    
                                              
 }
