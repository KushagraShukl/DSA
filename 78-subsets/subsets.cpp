class Solution {
public:
    void findSubset(int i, vector<int> nums, vector<int>& subset,
                     vector<vector<int>>& ans){

                        if( i == nums.size()) {
                            ans.push_back(subset);
                            return;
                        }
                        subset.push_back(nums[i]);
                        findSubset(i + 1, nums, subset,ans);
                        subset.pop_back();
                        findSubset(i + 1, nums, subset,ans);
                     }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> ans;
        findSubset(0, nums, subset,ans);
        return ans;
    }
};