class LFUCache {
    struct Node {
        int key, val, freq;
        Node *prev, *next;
        Node(int k, int v) : key(k), val(v), freq(1), prev(nullptr), next(nullptr) {}
    };

    struct DLL {
        Node *head, *tail;
        int size;

        DLL() {
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        void addFront(Node* node) {
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
            size++;
        }

        void remove(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            size--;
        }

        Node* removeLast() {
            if (size == 0) return nullptr;
            Node* node = tail->prev;
            remove(node);
            return node;
        }
    };

    int capacity, minFreq;
    unordered_map<int, Node*> keyNode;
    unordered_map<int, DLL*> freqList;

    void update(Node* node) {
        int freq = node->freq;
        freqList[freq]->remove(node);

        if (freq == minFreq && freqList[freq]->size == 0)
            minFreq++;

        node->freq++;

        if (!freqList.count(node->freq))
            freqList[node->freq] = new DLL();

        freqList[node->freq]->addFront(node);
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (!keyNode.count(key))
            return -1;

        Node* node = keyNode[key];
        update(node);
        return node->val;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (keyNode.count(key)) {
            Node* node = keyNode[key];
            node->val = value;
            update(node);
            return;
        }

        if (keyNode.size() == capacity) {
            Node* node = freqList[minFreq]->removeLast();
            keyNode.erase(node->key);
            delete node;
        }

        Node* node = new Node(key, value);
        minFreq = 1;

        if (!freqList.count(1))
            freqList[1] = new DLL();

        freqList[1]->addFront(node);
        keyNode[key] = node;
    }
};