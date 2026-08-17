class MyLinkedList {
    struct Node {
        int val;
        Node* next;

        Node(int v) : val(v), next(nullptr) {}
    };

    Node* dummy;
    int size;

public:
    MyLinkedList() {
        dummy = new Node(0);
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size)
            return -1;

        Node* cur = dummy->next;

        while (index--)
            cur = cur->next;

        return cur->val;
    }

    void addAtHead(int val) {
        Node* node = new Node(val);

        node->next = dummy->next;
        dummy->next = node;

        ++size;
    }

    void addAtTail(int val) {
        Node* cur = dummy;

        while (cur->next)
            cur = cur->next;

        cur->next = new Node(val);
        ++size;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size)
            return;

        Node* cur = dummy;

        for (int i = 0; i < index; ++i)
            cur = cur->next;

        Node* node = new Node(val);
        node->next = cur->next;
        cur->next = node;

        ++size;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
            return;

        Node* cur = dummy;

        for (int i = 0; i < index; ++i)
            cur = cur->next;

        Node* del = cur->next;
        cur->next = del->next;

        delete del;
        --size;
    }
};