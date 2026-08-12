class Solution {
    public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr;
        TreeNode *prev = nullptr, *cur = root;

        while (cur) {
            if (!cur->left) {
                if (prev && prev->val > cur->val) {
                    if (!first)
                    first = prev;
                    second = cur;
                }

                prev = cur;
                cur = cur->right;
            }
            else {
                TreeNode* pred = cur->left;

                while (pred->right && pred->right != cur)
                pred = pred->right;

                if (!pred->right) {
                    pred->right = cur;
                    cur = cur->left;
                }
                else {
                    pred->right = nullptr;

                    if (prev && prev->val > cur->val) {
                        if (!first)
                        first = prev;
                        second = cur;
                    }

                    prev = cur;
                    cur = cur->right;
                }
            }
        }

        swap(first->val, second->val);
    }
};