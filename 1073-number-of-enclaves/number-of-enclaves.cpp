class Solution {
    public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        auto add = [&](int r, int c) {
            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) {
                grid[r][c] = 0;
                q.push({r, c});
            }
        };

        // Start BFS from all boundary land cells
        for (int i = 0; i < m; ++i) {
            add(i, 0);
            add(i, n - 1);
        }

        for (int j = 0; j < n; ++j) {
            add(0, j);
            add(m - 1, j);
        }

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int d = 0; d < 4; ++d)
            add(r + dr[d], c + dc[d]);
        }

    // Remaining land cells are enclaves
    int ans = 0;

    for (auto& row : grid)
    for (int cell : row)
    ans += cell;

    return ans;
    }
};    