class Solution {
public:
    void findSubset(vector<int>& nums, int i,
                    vector<int>& subset,
                    vector<vector<int>>& ans) {

        // Base case: all elements have been considered
        if (i == nums.size()) {
            ans.push_back(subset);
            return;
        }

        // Include nums[i]
        subset.push_back(nums[i]);
        findSubset(nums, i + 1, subset, ans);

        // Backtrack
        subset.pop_back();

        // Exclude nums[i]
        findSubset(nums, i + 1, subset, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;

        findSubset(nums, 0, subset, ans);

        return ans;
    }
};