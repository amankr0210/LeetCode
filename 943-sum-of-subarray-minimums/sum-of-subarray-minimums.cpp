class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const long long MOD = 1000000007;
        int n = arr.size();

        vector<int> st;
        long long ans = 0;

        for (int i = 0; i <= n; ++i) {
            while (!st.empty() &&
                   (i == n || arr[st.back()] > arr[i])) {

                int j = st.back();
                st.pop_back();

                int left = st.empty() ? -1 : st.back();
                int right = i;

                long long leftCount = j - left;
                long long rightCount = right - j;

                ans = (ans +
                       (long long)arr[j] * leftCount % MOD * rightCount) % MOD;
            }

            if (i < n)
                st.push_back(i);
        }

        return ans;
    }
};