class Solution {
    public:
    int numComponents(ListNode* head, vector<int>& nums){
        unordered_set<int> present(nums.begin(),nums.end());

        int components = 0;

        while (head){
            if (present.count(head->val) && (head->next == nullptr || !present.count(head->next->val))){
                ++components;
            }
            head = head->next;
        }
        return components;
    }
};