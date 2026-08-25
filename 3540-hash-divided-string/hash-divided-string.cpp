class Solution {
public:
    string stringHash(string s, int k) {
        string ans;
        int sum = 0;
    
    for (int i = 0; i < s.size(); ++i){
        sum += s[i] - 'a';

        if ((i +1) % k == 0){
            ans += char('a' + sum % 26);
            sum = 0;
        }
    }
    return ans;
        
    }
};