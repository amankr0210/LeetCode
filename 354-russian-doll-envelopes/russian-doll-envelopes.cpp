class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return a[0] < b[0];
             });

        int n = envelopes.size();
        vector<int> temp;
        temp.push_back(envelopes[0][1]);
        for (int i = 1; i < n; i++) {
            if (envelopes[i][1] > temp.back())
                temp.push_back(envelopes[i][1]);
            else {
                int ind =
                    lower_bound(temp.begin(), temp.end(), envelopes[i][1]) -
                    temp.begin();
                temp[ind] = envelopes[i][1];
            }
        }
        return temp.size();
    }
};