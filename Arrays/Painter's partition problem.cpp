//mini time to paint the whole wall

bool isPossible(vector<int> &boards, int k,int mid){
    int count=1;
    //initialising that there is atleast 1 painter
    int painted_wall=0;
    //the area of wall that is being painted

    for(int i=0;i<boards.size();i++){
        if(painted_wall+boards[i]<=mid){
            painted_wall+=boards[i];
        }
        else{
            //partition the wall and distribute the rest of the walls to other painters
            count++;
            //check if the no of painters are exhausted
            //or if the next wall has size bigger than what has to be done in mini amount
            if(count>k || boards[i]>mid){
                return false;//ie this partition size is not the optimal one
            }
            //else we can allot the next wall to the next painter
            painted_wall=boards[i];//next if he satisfies the cindition, next areas can be added to it and so on
        }

        //check for the condition again
        if(count>k){
            return false;
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //max time taken is sum of boards array
    //we have to partition it to such a way that the time taken is mini
    //among k painters

    int start=0;
    //total time = end time
    int end=0;
    for(int i=0;i<boards.size();i++){
        end=end+boards[i];
    }
    int ans=-1;
    int mid=start+(end-start)/2;
    //check if the mid value is capable to partitioning the array such that time taken is mini

    while(start<=end){
        if(isPossible(boards,k,mid)){
            //thus one of the potential answers is mid
            //so store this ans
            ans=mid;
            //to the right of mid, all can be answers
            //to find the closest answer to the actual answer
            //search in the left half
            end=mid-1;
        }
        else{
            //there is no answer in the left atleast
            //seach for a bigger number to partition
            start=mid+1;
        }
        mid=start+(end-start)/2;
    }
    return ans;
}
