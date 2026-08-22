class Solution {
public:
    int maxDistinct(string s) {
        bool seen[26] = {};
        int ans = 0;

        for (char c : s){
            int x = c - 'a';

            if (!seen[x]){
                seen[x] = true;
                ++ans;

            }
        }

        return ans;
        
    }
};