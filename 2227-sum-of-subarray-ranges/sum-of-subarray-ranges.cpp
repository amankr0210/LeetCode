class Solution {
    public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        vector<int> st;

        
        st.clear();
        for (int i = 0; i <= n; ++i) {
            while (!st.empty() &&
            (i == n || nums[st.back()] < nums[i])) {
                int j = st.back();
                st.pop_back();

                int left = st.empty() ? -1 : st.back();
                int right = i;

                ans += 1LL * nums[j] * (j - left) * (right - j);
            }
            st.push_back(i);
        }

        
        st.clear();
        for (int i = 0; i <= n; ++i) {
            while (!st.empty() &&
            (i == n || nums[st.back()] > nums[i])) {
                int j = st.back();
                st.pop_back();

                int left = st.empty() ? -1 : st.back();
                int right = i;

                ans -= 1LL * nums[j] * (j - left) * (right - j);
            }
            st.push_back(i);
        }

        return ans;
    }
};