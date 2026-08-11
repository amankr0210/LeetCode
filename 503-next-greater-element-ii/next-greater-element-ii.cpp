class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        vector<int> st;

        for (int i = 2 * n - 1; i >= 0; --i) {
            int x = nums[i % n];

            while (!st.empty() && st.back() <= x)
                st.pop_back();

            if (i < n && !st.empty())
                ans[i] = st.back();

            st.push_back(x);
        }

        return ans;
    }
};