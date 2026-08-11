class Solution {
    public:
    vector<vector<int>> ans;
    vector<int> path;

    void backtrack(int start, int k, int target) {
        if (k == 0) {
            if (target == 0)
            ans.push_back(path);
            return;
        }

        if (target <= 0)
        return;

        // Not enough numbers remaining
        if (10 - start < k)
        return;

        for (int i = start; i <= 9; ++i) {
            if (i > target)
            break;

            path.push_back(i);
            backtrack(i + 1, k - 1, target - i);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(1, k, n);
        return ans;
    }
};