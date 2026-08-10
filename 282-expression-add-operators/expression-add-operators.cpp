class Solution {
public:
    vector<string> ans;

    void dfs(string& num, long long target, int pos,
             long long value, long long prev, string& expr) {

        if (pos == num.size()) {
            if (value == target)
                ans.push_back(expr);
            return;
        }

        long long cur = 0;
        int len = expr.size();

        for (int i = pos; i < num.size(); i++) {
            
            if (i > pos && num[pos] == '0')
                break;

            cur = cur * 10 + (num[i] - '0');

            if (pos == 0) {
                expr.append(num, pos, i - pos + 1);
                dfs(num, target, i + 1, cur, cur, expr);
                expr.resize(len);
            } else {
                // +
                expr.push_back('+');
                expr.append(num, pos, i - pos + 1);
                dfs(num, target, i + 1, value + cur, cur, expr);
                expr.resize(len);

                // -
                expr.push_back('-');
                expr.append(num, pos, i - pos + 1);
                dfs(num, target, i + 1, value - cur, -cur, expr);
                expr.resize(len);

                // *
                expr.push_back('*');
                expr.append(num, pos, i - pos + 1);
                dfs(num, target, i + 1,
                    value - prev + prev * cur,
                    prev * cur,
                    expr);
                expr.resize(len);
            }

            
            if (cur > LLONG_MAX / 10)
                break;
        }
    }

    vector<string> addOperators(string num, int target) {
        string expr;
        dfs(num, target, 0, 0, 0, expr);
        return ans;
    }
};