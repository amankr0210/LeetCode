class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int x = it.second.first;
            int y = it.second.second;

            mp[x][y].insert(node->val);

            if (node->left)
                q.push({node->left, {x - 1, y + 1}});

            if (node->right)
                q.push({node->right, {x + 1, y + 1}});
        }

        vector<vector<int>> ans;

        for (auto &col : mp) {
            vector<int> temp;

            for (auto &row : col.second) {
                temp.insert(temp.end(), row.second.begin(), row.second.end());
            }

            ans.push_back(temp);
        }

        return ans;
    }
};