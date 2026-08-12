class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;

        for (char c : s) {
            if (c == '(') {
                ++low;
                ++high;
            }
            else if (c == ')') {
                --high;
                if (low > 0)
                    --low;
            }
            else {  // '*'
                if (low > 0)
                    --low;
                ++high;
            }

            if (high < 0)
                return false;
        }

        return low == 0;
    }
};