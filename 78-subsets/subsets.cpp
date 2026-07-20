class Solution {
public:
    vector<vector<int>> ans;
    void findSubset(vector<int>& nums, int i,
                    vector<int>& subset) {

        // Base case: all elements have been considered
        if (i == nums.size()) {
            ans.push_back(subset);
            return;
        }

        // Include nums[i]
        subset.push_back(nums[i]);
        findSubset(nums, i + 1, subset);

        // Backtrack
        subset.pop_back();

        // Exclude nums[i]
        findSubset(nums, i + 1, subset);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> subset;

        findSubset(nums, 0, subset);

        return ans;
    }
};