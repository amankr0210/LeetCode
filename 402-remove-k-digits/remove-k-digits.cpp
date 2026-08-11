class Solution {
    public:
    string removeKdigits(string num, int k) {
        string st;

        for (char c : num) {
            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                --k;
            }

            st.push_back(c);
        }

        // Remove remaining digits from the end
        while (k > 0) {
            st.pop_back();
            --k;
        }

        // Remove leading zeros
        int pos = 0;
        while (pos < st.size() && st[pos] == '0')
        ++pos;

        st = st.substr(pos);

        return st.empty() ? "0" : st;
    }
};