class Solution {
    public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);

        for (auto& edge : times) {
            graph[edge[0]].push_back({edge[1], edge[2]});
        }

        const int INF = 1e9;
        vector<int> dist(n + 1, INF);

        priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
        > pq;

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d != dist[u])
            continue;

            for (auto [v, w] : graph[u]) {
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int answer = 0;

        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INF)
            return -1;

            answer = max(answer, dist[i]);
        }

        return answer;
    }
};