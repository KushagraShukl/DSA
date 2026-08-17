class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int bestVal  = nums[0];
        int worstVal = nums[0];
        int ans = nums[0];
        for(int i = 1; i<nums.size(); i++){
            int a = bestVal * nums[i];
            int b = worstVal * nums[i];
            int c = nums[i];

            bestVal = max(a, max(b, c));
            worstVal = min(a, min(b,c));

            ans = max(ans,bestVal);
        }
        return ans;
    }
};