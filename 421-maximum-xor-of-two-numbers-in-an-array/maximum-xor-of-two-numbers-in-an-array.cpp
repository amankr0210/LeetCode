class Solution {
    struct Node {
        Node* child[2];

        Node() {
            child[0] = child[1] = nullptr;
        }
    };

    Node* root = new Node();

    void insert(int num) {
        Node* cur = root;

        for (int bit = 30; bit >= 0; bit--) {
            int b = (num >> bit) & 1;

            if (!cur->child[b])
                cur->child[b] = new Node();

            cur = cur->child[b];
        }
    }

    int getMaxXor(int num) {
        Node* cur = root;
        int res = 0;

        for (int bit = 30; bit >= 0; bit--) {
            int b = (num >> bit) & 1;
            int opposite = b ^ 1;

            if (cur->child[opposite]) {
                res |= (1 << bit);
                cur = cur->child[opposite];
            } else {
                cur = cur->child[b];
            }
        }

        return res;
    }

public:
    int findMaximumXOR(vector<int>& nums) {
        for (int num : nums)
            insert(num);

        int ans = 0;

        for (int num : nums)
            ans = max(ans, getMaxXor(num));

        return ans;
    }
};