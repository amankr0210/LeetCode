class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";

        while (--n) {
            string cur = "";

            for (int i = 0; i < ans.size(); ) {
                int j = i;

                while (j < ans.size() && ans[j] == ans[i])
                    j++;

                cur += to_string(j - i);
                cur += ans[i];

                i = j;
            }

            ans = cur;
        }

        return ans;
    }
};