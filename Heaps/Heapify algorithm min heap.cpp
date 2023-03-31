#include <bits/stdc++.h> 
//just like heapify algorithm...build a min heap
//since they have done 0 based indexing
void heapify(vector<int> &arr,int n,int i){
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left < n && arr[smallest] > arr[left]) {
      smallest = left;
    }
    if(right< n && arr[smallest]>arr[right]){
        smallest=right;
    }
    if(smallest!=i){
        swap(arr[smallest],arr[i]);
        heapify(arr,n,smallest);
    }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    int n=arr.size();
    //from n/2-->nth node,all are root nodes
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    return arr;
}
