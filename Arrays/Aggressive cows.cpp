//step1:find the search space
//      mini dist=0
//      maxi dist=max-min
//      apply binary seach between this mini and maxi dist to find the closest/most optimal solution
//brute force approach says apply 2 for loops and calculate dist between each stall and then give the maxi dist

bool isPossible(vector<int> &stalls,int mini_dist,int maxi_dist,int mid,int k){
    int count=1;
    //assuming that there will be atleast 1 cow
    int lastPos=stalls[0];
    //we are going to compare position of every stall with respect to the first one and then compare to the mid value if its max dist

    for(int i=0;i<stalls.size();i++){
        if(stalls[i]-lastPos>=mid){
            //ie this can be a possible solution
            count++;
            if(count==k){
                return true;
            }
            lastPos=stalls[i];//update the position
        }
    }
    return false;
    
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int mini_dist=0;
    sort(stalls.begin(),stalls.end());
    int maxi_dist=stalls[stalls.size()-1];

    int mid=mini_dist+(maxi_dist-mini_dist)/2;
    int ans=-1;
    while(mini_dist<=maxi_dist){
        if(isPossible(stalls,mini_dist,maxi_dist,mid,k)){
            ans=mid;
            //ie this can be a possible solution
            //explore the right end
            //bec we want to maximise the distance between them
            mini_dist=mid+1;
        }
        else{
            maxi_dist=mid-1;
        }
        mid=mini_dist+(maxi_dist-mini_dist)/2;
    }
    return ans;

}
