class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> numSum1(n,0),numSum2(n,0);
        for(int i = 1; i<n; i++){
            numSum1[i] = numSum1[i-1] + nums[i-1];
        }
        for(int i = n-2; i>=0; i--){
            numSum2[i] = numSum2[i+1] + nums[i+1];
        }

        for(int i = 0; i<n; i++){
            if (numSum1[i] == numSum2[i]) return i;
        }
        return -1;

    }
};