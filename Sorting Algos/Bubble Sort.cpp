#include <bits/stdc++.h> 
void bubbleSort(vector<int>& arr, int n)
{   
    //bubble sort is basically the largest element bubbles itself and reaches its correct position in each iteration
    //no of rounds
    //starting from round 1
    //in each round, the ith largest element reaches its right position
    for(int i=1;i<arr.size();i++){
        bool swapped=1;
        // j traverses till j-ith position as the ith position from the last is already correct
        for(int j=0;j<arr.size()-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=0;
            }
        }
        if(swapped==1){
            //this means that the array is already sorted
            //best case scenario
            break;
        }
    }
}
