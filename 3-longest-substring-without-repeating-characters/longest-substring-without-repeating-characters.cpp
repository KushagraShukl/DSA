class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> count;
        int size = 0;

        for(int high = 0, low = 0; high<s.size(); high++){
            count[s[high]]++;
            while(count[s[high]]>1){
                count[s[low]]--;
                low++;
            }
            size = max(size, high - low + 1);

        }
        return size;
        
    }
};