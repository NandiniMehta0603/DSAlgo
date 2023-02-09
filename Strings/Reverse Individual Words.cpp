//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//steps: take 3 pointers i and j...
//position i on first letter, position j on just the next word's first letter
//and k on the last letter of the particular word
//start swapping using recursion

class Solution
{
  public:
    string reverseWords (string s)
    {
        int j=0;
        int i=0;
        int k=0;
        s=s+".";
        while(j<s.size()){
            
            if(s[j]=='.'){
                //function apply kardo
                k=j-1;
                // swapped(i,k,s);
                while(i<=k){
                    swap(s[k],s[i]);
                    i++;
                    k--;
                }
                if(j+1!=s.size()){
                i=j+1;}
            }
            j++;
        }
        return s.substr(0, s.size()-1);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
