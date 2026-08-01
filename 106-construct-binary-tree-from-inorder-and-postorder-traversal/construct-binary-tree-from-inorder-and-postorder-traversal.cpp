class Solution {
public:
    unordered_map<int, int> mp;
    int idx;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int left, int right) {
        if (left > right)
            return nullptr;

        TreeNode* root = new TreeNode(postorder[idx--]);

        int mid = mp[root->val];

        root->right = build(inorder, postorder, mid + 1, right);
        root->left = build(inorder, postorder, left, mid - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;

        idx = n - 1;

        return build(inorder, postorder, 0, n - 1);
    }
};