class Solution {
public:
    void solve(vector<int> nums, int start,vector<vector<int>> &ans){
        //base case
        if(start>=nums.size()){
            ans.push_back(nums);
            return ;
        }
        for(int i=start;i<nums.size();i++){
            swap(nums[start],nums[i]);
            solve(nums,start+1,ans);

            //backtrack
            swap(nums[start],nums[i]);
        }
        

    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        //take a starting index
        int start=0;

        vector<vector<int>> ans;

        solve(nums,start,ans);
        return ans;
    }
};
