class Solution {
public:
    string orderlyQueue(string s, int k) {
        if( k > 1){
            sort(s.begin(), s.end());
            return s;
        }

        string ans = s;
        int n = s.size();

        for(int i = 1; i < n; ++i){
            string cur = s.substr(i) + s.substr(0, i);
            if(cur < ans)
            ans = cur;

        }
        return ans;
        
    }
};