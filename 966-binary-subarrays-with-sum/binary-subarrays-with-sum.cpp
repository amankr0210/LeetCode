class Solution {
    public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        vector<int> freq(n + 1, 0);
        freq[0] = 1;

        int sum = 0;
        int ans = 0;

        for (int x : nums) {
            sum += x;

            if (sum >= goal)
            ans += freq[sum - goal];

            freq[sum]++;
        }

        return ans;
    }
};