class Solution {
public:
    struct Info {
        bool isBST;
        int minVal;
        int maxVal;
        int sum;
    };

    int ans = 0;

    Info dfs(TreeNode* root) {
        if (!root)
            return {true, INT_MAX, INT_MIN, 0};

        Info left = dfs(root->left);
        Info right = dfs(root->right);

        if (left.isBST && right.isBST &&
            root->val > left.maxVal &&
            root->val < right.minVal) {

            int currSum = left.sum + right.sum + root->val;
            ans = max(ans, currSum);

            return {
                true,
                min(root->val, left.minVal),
                max(root->val, right.maxVal),
                currSum
            };
        }

        return {false, INT_MIN, INT_MAX, 0};
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};