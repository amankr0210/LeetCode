class Solution {
public:
    const int dirs[5] = {0, 1, 0, -1, 0};

    bool bfs(vector<int>& start, vector<int>& finish,
             unordered_set<long long>& blockedSet, int limit) {

        unordered_set<long long> vis;
        queue<pair<int, int>> q;

        auto encode = [](int x, int y) {
            return 1LL * x * 1000000 + y;
        };

        q.push({start[0], start[1]});
        vis.insert(encode(start[0], start[1]));

        while (!q.empty() && vis.size() <= limit) {
            auto [x, y] = q.front();
            q.pop();

            if (x == finish[0] && y == finish[1])
                return true;

            for (int k = 0; k < 4; k++) {
                int nx = x + dirs[k];
                int ny = y + dirs[k + 1];

                if (nx < 0 || ny < 0 || nx >= 1000000 || ny >= 1000000)
                    continue;

                long long key = encode(nx, ny);

                if (blockedSet.count(key) || vis.count(key))
                    continue;

                vis.insert(key);
                q.push({nx, ny});
            }
        }

        return vis.size() > limit;
    }

    bool isEscapePossible(vector<vector<int>>& blocked,
                          vector<int>& source,
                          vector<int>& target) {

        unordered_set<long long> blockedSet;

        auto encode = [](int x, int y) {
            return 1LL * x * 1000000 + y;
        };

        for (auto &b : blocked)
            blockedSet.insert(encode(b[0], b[1]));

        int n = blocked.size();
        int limit = n * (n - 1) / 2;

        return bfs(source, target, blockedSet, limit) &&
               bfs(target, source, blockedSet, limit);
    }
};