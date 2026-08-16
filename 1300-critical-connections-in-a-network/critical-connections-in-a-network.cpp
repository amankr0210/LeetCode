class Solution {
    vector<vector<int>> graph;
    vector<int> tin, low;
    vector<vector<int>> ans;
    int timer = 0;

    void dfs(int u, int parent) {
        tin[u] = low[u] = timer++;

        for (int v : graph[u]) {
            if (v == parent)
                continue;

            if (tin[v] != -1) {
                low[u] = min(low[u], tin[v]);
            } else {
                dfs(v, u);

                low[u] = min(low[u], low[v]);

                if (low[v] > tin[u])
                    ans.push_back({u, v});
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(
        int n, vector<vector<int>>& connections) {

        graph.assign(n, {});
        tin.assign(n, -1);
        low.assign(n, -1);
        ans.clear();
        timer = 0;

        for (auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int i = 0; i < n; ++i) {
            if (tin[i] == -1)
                dfs(i, -1);
        }

        return ans;
    }
};