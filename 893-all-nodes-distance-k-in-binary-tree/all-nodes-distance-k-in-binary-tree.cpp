class Solution {
    public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);

        int dist = 0;

        while (!q.empty() && dist < k) {
            int size = q.size();

            while (size--) {
                TreeNode* node = q.front();
                q.pop();

                TreeNode* next[3] = {
                    node->left,
                    node->right,
                    parent.count(node) ? parent[node] : nullptr
                };

                for (TreeNode* x : next) {
                    if (x && !visited.count(x)) {
                        visited.insert(x);
                        q.push(x);
                    }
                }
            }

            ++dist;
        }

        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};