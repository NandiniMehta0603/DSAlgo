//steps: first create an empty ans set
//we will store all the answer subsets in this part
//make a recursive tree having 2 calls- include and exclude
//move the i pointer
//base case-when the i pointer reaches length pf the array
//upon returning, store the output vector into ans vector an also explore other calls if left on a particular level
//return the ans

class Solution {
public:
    void solve(vector<int>nums,vector<vector<int>>&ans,int i,vector<int> output){
        //base case
        if(i>=nums.size()){
            ans.push_back(output);
            return ;
        }

        //call for exclude
        solve(nums,ans,i+1,output);

        //call for include
        int element=nums[i];
        output.push_back(element);
        solve(nums,ans,i+1,output);
    }



    vector<vector<int>> subsets(vector<int>& nums) {
        //ans is the vector of vector storing all the subsets
        vector<vector<int>> ans;
        //this i pointer will traverse the nums array
        int i=0;
        //output will be the final subset at the end of each recusrive call
        //which gets stored in ans set
        vector<int> output;
        solve(nums,ans,i,output);//pass ans by reference so that changes are saved on every call
        return ans;
    }
};
