class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> count;
        int ans = INT_MIN;

        for(int high = 0, low = 0; high<fruits.size(); high++){
            count[fruits[high]]++;
            while(count.size()>2){
                
                count[fruits[low]]--;
                if(count[fruits[low]] == 0) count.erase(fruits[low]);
                low++;

            }
            ans = max(ans, high - low + 1);
            
        }
        return ans;

    }
};