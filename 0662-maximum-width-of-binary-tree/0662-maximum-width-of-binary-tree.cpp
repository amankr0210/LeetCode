class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        long long ans = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int sz = q.size();
            unsigned long long mn = q.front().second;
            unsigned long long first = 0, last = 0;

            for (int i = 0; i < sz; i++) {
                auto [node, idx] = q.front();
                q.pop();

                idx -= mn;

                if (i == 0) first = idx;
                if (i == sz - 1) last = idx;

                if (node->left)
                    q.push({node->left, 2 * idx + 1});

                if (node->right)
                    q.push({node->right, 2 * idx + 2});
            }

            ans = max(ans, (long long)(last - first + 1));
        }

        return (int)ans;
    }
};