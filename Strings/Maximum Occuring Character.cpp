//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        //step1: make an array of size 26 storing all the letter's frequency
        int arr[26]={0};
        for(int i=0;i<str.length();i++){
            arr[str[i]-'a']++;
        }
        int freq=-1;
        char ans;
        for(int i=0;i<26;i++){
            if(arr[i]>freq){
                ans=i+'a';
                freq=arr[i];
            }
        }
        return ans;
    }


};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends
