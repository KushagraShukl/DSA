class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right(n);
        vector<int> left(n);
        stack<int> st;
        //left smaller value
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(st.empty()) left[i] = -1;
            else left[i] = st.top();
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(st.empty()) right[i] = n;
            else right[i] = st.top();
            st.push(i);
        }
        int area,maxArea = 0;
        for(int i = 0; i<n; i++){
            area = heights[i] * (right[i] - left[i] -1);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};