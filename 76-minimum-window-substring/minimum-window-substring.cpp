class Solution {
    public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        int need[128] = {};
        int window[128] = {};

        for (char c : t)
        ++need[c];

        int required = t.size();
        int left = 0;
        int start = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < s.size(); ++right) {
            char c = s[right];

            if (++window[c] <= need[c])
            --required;

            while (required == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char x = s[left++];

                if (--window[x] < need[x])
                ++required;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};