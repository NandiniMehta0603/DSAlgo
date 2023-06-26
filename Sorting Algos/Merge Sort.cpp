void merge(vector<int> &arr,int start,int end){
    int mid=(start+end)/2;
    
    int length1=mid-start+1;
    int length2=end-mid;

    int *first=new int[length1];
    int *second=new int[length2];

    int i=start;
    for(int k=0;k<length1;k++){
        first[k]=arr[i];
        i++;
    }
    i=mid+1;
    for(int k=0;k<length2;k++){
        second[k]=arr[i];
        i++;
    }

    int index1=0;
    int index2=0;
    int index=start;

    while(index1<length1 && index2<length2){
        if(first[index1]<=second[index2]){
            arr[index]=first[index1];
            index1++;
            index++;
        }
        else{
            arr[index]=second[index2];
            index++;
            index2++;
        }
    }
    while(index1<length1){
        arr[index]=first[index1];
        index++;
        index1++;
    }
    while(index2<length2){
        arr[index]=second[index2];
        index2++;
        index++;
    }

    delete []first;
    delete []second;
}

void mergeeSort(vector<int> &arr,int s,int e){
    //base case
    if(s>=e){
        return ;
    }
    int mid=(s+e)/2;
    
    mergeeSort(arr,s,mid);
    mergeeSort(arr,mid+1,e);

    merge(arr,s,e);
    
}

void mergeSort(vector < int > & arr, int n) {
    mergeeSort(arr,0,n-1);
}
