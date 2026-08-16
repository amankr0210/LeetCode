class Solution {
    public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        using Node = tuple<int, int, int>;
        priority_queue<Node, vector<Node>, greater<Node>> pq;

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        int answer = 0;
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!pq.empty()) {
            auto [height, r, c] = pq.top();
            pq.pop();

            answer = max(answer, height);

            if (r == n - 1 && c == n - 1)
            return answer;

            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                continue;

                if (visited[nr][nc])
                continue;

                visited[nr][nc] = true;
                pq.push({grid[nr][nc], nr, nc});
            }
        }

        return -1;
    }
};