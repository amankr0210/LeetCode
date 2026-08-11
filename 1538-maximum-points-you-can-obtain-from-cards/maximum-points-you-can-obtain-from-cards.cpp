class Solution {
    public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int window = n - k;

        long long total = 0;
        for (int x : cardPoints)
        total += x;

        if (window == 0)
        return total;

        long long cur = 0;
        for (int i = 0; i < window; ++i)
        cur += cardPoints[i];

        long long minSum = cur;

        for (int i = window; i < n; ++i) {
            cur += cardPoints[i] - cardPoints[i - window];
            minSum = min(minSum, cur);
        }

        return total - minSum;
    }
};