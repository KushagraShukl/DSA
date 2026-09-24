class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> ans;

        // Max heap:
        // {value, index}
        // Largest value will always be at the top
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < nums.size(); i++) {

            // Add current element with its index
            pq.push({nums[i], i});

            // Once we have a complete window
            if (i >= k - 1) {

                // Remove elements that are outside
                // the current window
                while (pq.top().second <= i - k) {
                    pq.pop();
                }

                // The top element is the maximum
                // of the current window
                ans.push_back(pq.top().first);
            }
        }

        return ans;
    }
};