class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;

        dfs(1, k, n, path, ans);

        return ans;
    }

private:
    void dfs(int start, int k, int target,
             vector<int>& path,
             vector<vector<int>>& ans) {

        if (path.size() == k) {
            if (target == 0)
                ans.push_back(path);

            return;
        }

        for (int i = start; i <= 9; i++) {

            if (i > target)
                break;

            path.push_back(i);

            dfs(i + 1, k, target - i, path, ans);

            path.pop_back();
        }
    }
};