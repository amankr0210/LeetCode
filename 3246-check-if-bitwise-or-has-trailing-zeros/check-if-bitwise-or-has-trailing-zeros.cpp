class Solution {
    public:
    bool hasTrailingZeros(vector<int>& nums) {
        int cnt = 0;

        for (int x : nums) {
            if ((x & 1) == 0)
            ++cnt;

            if (cnt == 2)
            return true;
        }

        return false;
    }
};