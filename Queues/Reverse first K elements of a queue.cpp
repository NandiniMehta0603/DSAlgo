//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
//steps: reverse first K elements and push them in the queue while returning
//take the first n-k elements, pop them and push them back in queue to get the right ordering

void reverseK(queue<int> &q,int k,int count){
    //base case
    if(count==k){
        return ;
    }
    int element=q.front();
    q.pop();
    reverseK(q,k,count+1);
    q.push(element);
    
}
queue<int> modifyQueue(queue<int> q, int k) {
    int count=0;
    reverseK(q,k,count);
    
    for(int i=0;i<q.size()-k;i++){
        int element=q.front();
        q.pop();
        q.push(element);
    }
    
    return q;
    
}
