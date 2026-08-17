class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            int a = maxi + nums[i];
            int b = nums[i];

            maxi = max(a, b);
            ans = max(ans, maxi);
        }

        return ans;
    }
};