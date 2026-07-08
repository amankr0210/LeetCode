class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void solve(int idx, int target, vector<int>& candidates) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = idx; i < candidates.size() && candidates[i] <= target; i++) {
            curr.push_back(candidates[i]);
            solve(i, target - candidates[i], candidates);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(0, target, candidates);
        return ans;
    }
};