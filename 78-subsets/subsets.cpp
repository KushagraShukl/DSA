class Solution {
public:
    void allSubsets(int i, vector<int>& subset, vector<vector<int>>& ans, vector<int> nums){
        if(i == nums.size()){
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        allSubsets(i+1, subset, ans, nums);
        subset.pop_back();
        allSubsets(i+1, subset, ans, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        allSubsets(0, subset, ans, nums);
        return ans;
    }
};