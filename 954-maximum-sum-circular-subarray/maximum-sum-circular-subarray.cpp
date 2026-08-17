class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxi = nums[0];
        int ans = nums[0];

        int mini = nums[0];
        int minAns = nums[0];

        int sum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            int a = maxi + nums[i];
            int b = nums[i];
            maxi = max(a, b);
            ans = max(ans, maxi);

            int c = mini + nums[i];
            int d = nums[i];
            mini = min(c, d);
            minAns = min(minAns, mini);

            sum += nums[i];
        }

        if (ans < 0)
            return ans;

        return max(ans, sum - minAns);
    }
};