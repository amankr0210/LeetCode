class Solution {
    public:
    bool checkPrimeFrequency(vector<int>& nums) {
        int freq[101] = {};

        for (int x : nums)
        ++freq[x];

        for (int f : freq) {
            if (f < 2)
            continue;

            bool prime = true;

            for (int d = 2; d * d <= f; ++d) {
                if (f % d == 0) {
                    prime = false;
                    break;
                }
            }

            if (prime)
            return true;
        }

        return false;
    }
};