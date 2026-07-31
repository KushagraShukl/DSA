class Solution {
public:
    void allSubsets(int i, vector<int> nums, vector<int> &subset, vector<vector<int>> &ans){
        if(i == nums.size()){
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        allSubsets(i+1, nums, subset, ans);
        subset.pop_back();
        allSubsets(i+1, nums, subset, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> ans;

        allSubsets(0, nums, subset, ans);
        
        return ans;
    }
};