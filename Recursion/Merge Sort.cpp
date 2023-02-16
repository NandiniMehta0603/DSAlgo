//steps to do merge sort
//split the array into 2...keep splitting 
//after it has reached the limit of single element
//start merging in sorted order
//keep merging such that the resultant array is sorted

void merge(vector<int> &arr,int start,int end){
    //steps of merging are as follows:
    //take 2 different pointers
    //1 on left subpart and the other on the right subpart
    //compare them and store them in the original array in sorted order

    int mid=start+(end-start)/2;
    int length1=mid-start+1;
    int length2=end-mid;

    //make arrays in heap
    int *first=new int[length1];
    int *second=new int[length2];

    int index=start;

    //put in array
    for(int i=0;i<length1;i++){
        first[i]=arr[index++];
    }
    index=mid+1;
    for(int i=0;i<length2;i++){
        second[i]=arr[index++];
    }

    //compare and then merge them in sorted order in the original array
    index=start;
    int index1=0;
    int index2=0;
    while(index1<length1 && index2<length2){
        if(first[index1]<second[index2]){
            arr[index++]=first[index1++];
        }
        else{
            arr[index++]=second[index2++];
        }
    }

    //if any list is still not completely empty
    while(index1<length1){
        arr[index++]=first[index1++];
    }
    while(index2<length2){
        arr[index++]=second[index2++];
    }

    //always delete the extra memory used 
    delete []first;
    delete []second;

}

//function for splitting the array
void solve(vector<int> &arr,int start,int end){
    //base case
    if(start>=end){
        return ;
    }
    int mid=start+(end-start)/2;
    //solve for left part
    solve(arr,start,mid);
    //solve for right part
    solve(arr,mid+1,end);

    //merge both of them
    merge(arr,start,end);
}

void mergeSort(vector < int > & arr, int n) {
    solve(arr,0,n-1);
}
