#include <bits/stdc++.h> 
void selectionSort(vector<int>& arr, int n)
{   
    //selection sort is that at every iteration the mini value will come to is right place
    for(int i=0;i<arr.size()-1;i++){
        int mini_index=i;
        for(int j=i+1;j<arr.size();j++){
            if(arr[mini_index]>arr[j]){
                mini_index=j;
            }
        }
        swap(arr[i],arr[mini_index]);
    }
}
