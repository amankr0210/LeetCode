class Solution {
    public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int row = 0;

            for (int i = 1; i < m; ++i) {
                if (mat[i][mid] > mat[row][mid])
                row = i;
            }

            int current = mat[row][mid];
            int l = (mid > 0) ? mat[row][mid - 1] : -1;
            int r = (mid + 1 < n) ? mat[row][mid + 1] : -1;

            if (current > l && current > r)
            return {row, mid};

            if (l > current)
            right = mid - 1;
            else
            left = mid + 1;
        }

        return {-1, -1};
    }
};