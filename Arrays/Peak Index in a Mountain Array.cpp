class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        //apply binary search logic
        int low=0;
        int high=arr.size()-1;
        int mid=low+(high-low)/2;
        while(low<high){
            if(arr[mid]>arr[mid+1]){
                high=mid;
            }
            else{
                low=mid+1;
            }
            mid=low+(high-low)/2;
        }
        return low;
    }
};
