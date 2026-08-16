class Solution {
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] == x)
        return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
        return;

        if (sz[a] < sz[b])
        swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
    }

    public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        parent.resize(n);
        sz.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (stones[i][0] == stones[j][0] ||
                stones[i][1] == stones[j][1]) {
                    unite(i, j);
                }
            }
        }

        int components = 0;

        for (int i = 0; i < n; ++i) {
            if (find(i) == i)
            ++components;
        }

        return n - components;
    }
};