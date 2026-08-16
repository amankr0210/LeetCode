class Solution {
    public:
    int n;
    vector<vector<int>> grid;
    vector<int> area;

    int dfs(int r, int c, int id) {
        if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] != 1)
        return 0;

        grid[r][c] = id;

        return 1
        + dfs(r + 1, c, id)
        + dfs(r - 1, c, id)
        + dfs(r, c + 1, id)
        + dfs(r, c - 1, id);
    }

    int largestIsland(vector<vector<int>>& g) {
        grid = g;
        n = grid.size();

        area.assign(2, 0);

        int id = 2;
        int best = 0;

        // Label every island and store its area
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    area.push_back(dfs(r, c, id));
                    best = max(best, area[id]);
                    ++id;
                }
            }
        }

        // Try converting each 0 into 1
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] != 0)
                continue;

                int total = 1;
                int ids[4];
                int count = 0;

                int dr[] = {1, -1, 0, 0};
                int dc[] = {0, 0, 1, -1};

                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                    continue;

                    int island = grid[nr][nc];

                    bool duplicate = false;
                    for (int i = 0; i < count; ++i) {
                        if (ids[i] == island) {
                            duplicate = true;
                            break;
                        }
                    }

                    if (island > 1 && !duplicate) {
                        ids[count++] = island;
                        total += area[island];
                    }
                }

                best = max(best, total);
            }
        }

        return best;
    }
};