class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            long long hours = 0;

            for (int x : piles) {
                hours += (x + mid - 1) / mid;

                if (hours > h)
                    break;
            }

            if (hours <= h)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};