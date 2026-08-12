class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int removed = 0;
        int end = INT_MIN;

        for (const auto& cur : intervals) {
            if (cur[0] < end) {
                ++removed;
            } else {
                end = cur[1];
            }
        }

        return removed;
    }
};