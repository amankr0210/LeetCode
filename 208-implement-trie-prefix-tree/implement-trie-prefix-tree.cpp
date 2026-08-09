class Trie {
    struct Node {
        Node* child[26];
        bool isEnd;

        Node() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* cur = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!cur->child[idx])
                cur->child[idx] = new Node();

            cur = cur->child[idx];
        }

        cur->isEnd = true;
    }

    bool search(string word) {
        Node* cur = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!cur->child[idx])
                return false;

            cur = cur->child[idx];
        }

        return cur->isEnd;
    }

    bool startsWith(string prefix) {
        Node* cur = root;

        for (char c : prefix) {
            int idx = c - 'a';

            if (!cur->child[idx])
                return false;

            cur = cur->child[idx];
        }

        return true;
    }
};