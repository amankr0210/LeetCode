class Solution {
    public:
    int change(int amount, vector<int>& coins) {
        // Use unsigned long long to handle massive intermediate sums
        // that exceed the 32-bit integer limit.
        vector<unsigned long long> dp(amount + 1, 0);

        dp[0] = 1;

        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }

        // The problem guarantees the final answer fits in a 32-bit signed int
        return static_cast<int>(dp[amount]);
    }
};