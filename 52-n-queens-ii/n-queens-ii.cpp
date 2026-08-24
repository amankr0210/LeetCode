class Solution {
    int n;

    int dfs(int row, int col, int d1, int d2) {
        if (row == n)
        return 1;

        int mask = (1 << n) - 1;
        int free = mask & ~(col | d1 | d2);
        int ans = 0;

        while (free) {
            int bit = free & -free;
            free -= bit;

            ans += dfs(
                row + 1,
                col | bit,
                (d1 | bit) << 1,
                (d2 | bit) >> 1
            );
        }

        return ans;
    }

    public:
    int totalNQueens(int n) {
        this->n = n;
        return dfs(0, 0, 0, 0);
    }
};