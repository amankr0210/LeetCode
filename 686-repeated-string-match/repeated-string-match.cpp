class Solution {
    public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size(), m = b.size();

        string text;
        int times = (m + n - 1) / n;

        text.reserve((times + 1) * n);

        for (int i = 0; i < times; ++i)
        text += a;

        if (kmp(text, b))
        return times;

        text += a;

        if (kmp(text, b))
        return times + 1;

        return -1;
    }

    private:
    bool kmp(const string& text, const string& pattern) {
        int m = pattern.size();
        vector<int> lps(m, 0);

        for (int i = 1, j = 0; i < m; ++i) {
            while (j > 0 && pattern[i] != pattern[j])
            j = lps[j - 1];

            if (pattern[i] == pattern[j])
            ++j;

            lps[i] = j;
        }

        for (int i = 0, j = 0; i < text.size(); ++i) {
            while (j > 0 && text[i] != pattern[j])
            j = lps[j - 1];

            if (text[i] == pattern[j])
            ++j;

            if (j == m)
            return true;
        }

        return false;
    }
};