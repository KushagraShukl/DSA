class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans(score.size()); 

        priority_queue<pair<int,int>> pq; 

        for(int i = 0 ; i < score.size() ; i++) {
            pq.push(make_pair(score[i],i)); 
        } 
        
        ans[pq.top().second] = "Gold Medal"; 
        pq.pop(); 

        if(!pq.empty()) {
            ans[pq.top().second] = "Silver Medal"; 
            pq.pop(); 
        }
        if(!pq.empty()) {
            ans[pq.top().second] = "Bronze Medal"; 
            pq.pop(); 
        }
        
        int pos = 4 ; 


        while(!pq.empty()) {
            pair<int,int> curr = pq.top(); 
            pq.pop(); 
            ans[curr.second] = to_string(pos); 
            pos++; 
        }

        return ans; 
    }
};