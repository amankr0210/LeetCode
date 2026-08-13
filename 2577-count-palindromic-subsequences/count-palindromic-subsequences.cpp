class Solution {
    public:
    int countPalindromes(string s) {
        constexpr int kMod = 1'000'000'007;
        constexpr int kPatternSize = 5;
        long ans = 0;

        // Iterate over all possible pairs of digits (a, b) from '0' to '9'
        for (char a = '0'; a <= '9'; ++a) {
            for (char b = '0'; b <= '9'; ++b) {
                vector<char> pattern = {a, b, '.', b, a};
                vector<long> dp(kPatternSize + 1, 0);
                dp[kPatternSize] = 1; // Base case: successfully matched the pattern

                for (char c : s) {
                    for (int i = 0; i < kPatternSize; ++i) {
                        if (pattern[i] == '.' || pattern[i] == c) {
                            dp[i] += dp[i + 1];
                        }
                    }
                }
                ans += dp[0];
                ans %= kMod;
            }
        }

        return ans;
    }
};