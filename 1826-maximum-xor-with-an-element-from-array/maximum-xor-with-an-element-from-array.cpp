class Solution {
    struct Node {
        Node* child[2];

        Node() {
            child[0] = child[1] = nullptr;
        }
    };

    Node* root = new Node();

    void insert(int x) {
        Node* cur = root;

        for (int bit = 31; bit >= 0; bit--) {
            int b = (x >> bit) & 1;

            if (!cur->child[b])
                cur->child[b] = new Node();

            cur = cur->child[b];
        }
    }

    int getMaxXor(int x) {
        Node* cur = root;
        int ans = 0;

        for (int bit = 31; bit >= 0; bit--) {
            int b = (x >> bit) & 1;
            int want = b ^ 1;

            if (cur->child[want]) {
                ans |= (1 << bit);
                cur = cur->child[want];
            } else {
                cur = cur->child[b];
            }
        }

        return ans;
    }

public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());

        vector<array<int, 3>> q;

        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i][1], queries[i][0], i});
        }

        sort(q.begin(), q.end());

        vector<int> ans(queries.size());
        int j = 0;

        for (auto &[m, x, idx] : q) {
            while (j < nums.size() && nums[j] <= m) {
                insert(nums[j]);
                j++;
            }

            if (j == 0)
                ans[idx] = -1;
            else
                ans[idx] = getMaxXor(x);
        }

        return ans;
    }
};