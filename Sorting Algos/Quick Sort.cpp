int partition(vector<int> &arr,int start, int end)
{
    int pivot=arr[start];
    int count=0;
    for(int i=start+1;i<=end;i++)
    {
        if(arr[i]<=pivot)
        {
            count++;
        }
    }
    int pivot_index=count+start;
    swap(arr[start],arr[pivot_index]);
    
    //left part sambhalo
    //right part sambhalo
    
    int i=start;
    int j=end;
    while(i<pivot_index && j>pivot_index)
    {
        while(arr[i]<=pivot)
        {
            i++;
        }
        while(arr[j]>pivot)
        {
            j--;
        }
        if(i<pivot_index && j>pivot_index)
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return pivot_index;
}

void quicksortt(vector<int> &arr, int start, int end)
{
    //base case
    if(start>=end)
    {
        return ;
    }
    
    //partition element dhundho
    int p=partition(arr,start,end);
    
    //left part mei quicksort lagado 
    quicksortt(arr,start,p-1);
    
    //right part mei quicksort lagado
    quicksortt(arr,p+1,end);
}

vector<int> quickSort(vector<int> arr)
{
    quicksortt(arr,0,arr.size()-1);
    return arr;
}
