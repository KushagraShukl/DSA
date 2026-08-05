class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans = nums[0] + nums[1] + nums[2], sum = 0;
        int i, j, k;

        for(i = 0; i<nums.size()-2; i++){
            j = i+1;
            k = nums.size()-1;
            while(j<k){
                sum = nums[i] + nums[j] + nums[k];
                if(abs(sum - target) < abs(ans - target)) ans = sum;
                if(sum>target){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return ans;
    }
};