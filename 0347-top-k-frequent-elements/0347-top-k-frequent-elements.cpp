class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int num : nums)
            mp[num]++;

        vector<vector<int>> bucket(nums.size() + 1);

        for (auto &it : mp)
            bucket[it.second].push_back(it.first);

        vector<int> ans;

        for (int i = nums.size(); i >= 0 && k > 0; i--) {
            for (int num : bucket[i]) {
                ans.push_back(num);
                if (--k == 0)
                    return ans;
            }
        }

        return ans;
    }
};