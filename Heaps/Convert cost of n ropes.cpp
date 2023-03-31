//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//steps: make a min heap, take the 2 smallest elements, add them and then add their sum to the cost and then push the addition back to the heap
//repeat this process till heap size is reduced to one ie only 1 element is left in the heap
//return the cost

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        //step1: make a min heap
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        //push all the elements in the heap
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        
        //do the while loop
        long long cost=0;
        while(pq.size()>1){
            long long a=pq.top();
            pq.pop();
            
            long long b=pq.top();
            pq.pop();
            
            long long new_ele=a+b;
            cost+=new_ele;
            
            pq.push(new_ele);
        }
        
        return cost;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
