#include <bits/stdc++.h> 
//steps: even rows have to traversed top to bottom 
//  odd rows have to be traversed bottom to top
void traverseTopToBottom(vector<vector<int>>arr,vector<int>&ans,int nRows,int i){
    //ith column
    for(int j=0;j<nRows;j++){
        ans.push_back(arr[j][i]);
    }
}

void traverseBottomToTop(vector<vector<int>>arr, vector<int> &ans,int nRows,int i){
    //ith column
    for(int j=nRows-1;j>=0;j--){
        ans.push_back(arr[j][i]);
    }
}

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    //the traversal dhould be column vise 
    int i=0;
    vector<int> ans;
    while(i<mCols){
        if(i%2==0){
            traverseTopToBottom(arr,ans,nRows,i);
        }
        else{
            traverseBottomToTop(arr,ans,nRows,i);
        }
        i++;
    }
    return ans;
}
