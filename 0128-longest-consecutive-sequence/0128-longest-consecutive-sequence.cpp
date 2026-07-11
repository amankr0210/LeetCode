class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for (int num : st) {
            // Start only from the beginning of a sequence
            if (!st.count(num - 1)) {
                int curr = num;
                int cnt = 1;

                while (st.count(curr + 1)) {
                    curr++;
                    cnt++;
                }

                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};