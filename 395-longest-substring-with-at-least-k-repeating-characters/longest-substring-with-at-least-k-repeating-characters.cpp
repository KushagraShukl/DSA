class Solution {
public:
    int longestSubstring(string s, int k) {

        int n = s.size();
        int ans = 0;

        // We try every possible number of unique characters
        for(int uniqueRequired = 1; uniqueRequired <= 26; uniqueRequired++) {

            // Frequency of each character
            vector<int> freq(26, 0);

            int left = 0;
            int right = 0;

            // Number of characters having frequency >= k
            int countAtLeastK = 0;

            // Number of unique characters in current window
            int unique = 0;

            while(right < n) {

                // Add s[right]
                int index = s[right] - 'a';

                if(freq[index] == 0)
                    unique++;

                freq[index]++;

                // If character has just reached k occurrences
                if(freq[index] == k)
                    countAtLeastK++;

                right++;

                // Shrink window if unique characters exceed required
                while(unique > uniqueRequired) {

                    int removeIndex = s[left] - 'a';

                    // If this character had exactly k occurrences,
                    // removing it makes its frequency less than k
                    if(freq[removeIndex] == k)
                        countAtLeastK--;

                    freq[removeIndex]--;

                    // Character completely removed from window
                    if(freq[removeIndex] == 0)
                        unique--;

                    left++;
                }

                // Valid window:
                // 1. Exactly required number of unique characters
                // 2. Every unique character occurs at least k times
                if(unique == uniqueRequired &&
                   unique == countAtLeastK) {

                    ans = max(ans, right - left);
                }
            }
        }

        return ans;
    }
};