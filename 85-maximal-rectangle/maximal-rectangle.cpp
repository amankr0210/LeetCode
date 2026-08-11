class Solution {
    public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> st;
        int ans = 0;

        for (int i = 0; i <= h.size(); ++i) {
            int cur = (i == h.size() ? 0 : h[i]);

            while (!st.empty() && h[st.top()] > cur) {
                int height = h[st.top()];
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;

                ans = max(ans, height * width);
            }

            st.push(i);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
        return 0;

        int n = matrix[0].size();
        vector<int> height(n, 0);
        int ans = 0;

        for (auto& row : matrix) {
            for (int j = 0; j < n; ++j) {
                height[j] = (row[j] == '1') ? height[j] + 1 : 0;
            }

            ans = max(ans, largestRectangleArea(height));
        }

        return ans;
    }
};