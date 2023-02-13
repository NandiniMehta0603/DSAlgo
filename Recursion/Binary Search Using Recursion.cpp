//just replace the iterative approach by recursive calls and do the changes accordingly

int solveBS(int *input, int start,int end,int val){
    int mid=start+(end-start)/2;
    //base case
    if(start>end){
        return -1;
    }

    if(input[mid]==val){
         return mid;
    }
    else if(input[mid]>val){
         return solveBS(input,start,mid-1,val);
    }
    else{
         return solveBS(input,mid+1,end,val);
    }
}

int binarySearch(int *input, int n, int val)
{
    int start=0;
    int end=n-1;
    int ans=solveBS(input,start,end,val);
    return ans;
}
