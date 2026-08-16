class Solution {
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] == x)
        return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
        return false;

        if (sz[a] < sz[b])
        swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];

        return true;
    }

    public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
        return -1;

        parent.resize(n);
        sz.assign(n, 1);

        iota(parent.begin(), parent.end(), 0);

        int components = n;

        for (auto& edge : connections) {
            if (unite(edge[0], edge[1]))
            --components;
        }

        return components - 1;
    }
};