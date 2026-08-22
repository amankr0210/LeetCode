class Solution {
    public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<long long> pq;
        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            long long d = llabs((long long)q[0]) + llabs((long long)q[1]);

            pq.push(d);

            if (pq.size() > k)
            pq.pop();

            if (pq.size() == k)
            ans.push_back((int)pq.top());
            else
            ans.push_back(-1);
        }

        return ans;
    }
};