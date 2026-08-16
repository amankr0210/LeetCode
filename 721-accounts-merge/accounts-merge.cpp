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
    vector<vector<string>> accountsMerge(
        vector<vector<string>>& accounts) {

            int n = accounts.size();

            parent.resize(n);
            sz.assign(n, 1);
            iota(parent.begin(), parent.end(), 0);

            unordered_map<string, int> owner;

            // Connect accounts having common emails
            for (int i = 0; i < n; ++i) {
                for (int j = 1; j < accounts[i].size(); ++j) {
                    const string& email = accounts[i][j];

                    if (owner.count(email))
                    unite(i, owner[email]);
                    else
                    owner[email] = i;
                }
            }

            unordered_map<int, vector<string>> groups;

            for (auto& [email, id] : owner)
            groups[find(id)].push_back(email);

            vector<vector<string>> ans;

            for (auto& [root, emails] : groups) {
                sort(emails.begin(), emails.end());

                vector<string> current;
                current.push_back(accounts[root][0]);

                for (const string& email : emails)
                current.push_back(email);

                ans.push_back(move(current));
            }

            return ans;
        }
};