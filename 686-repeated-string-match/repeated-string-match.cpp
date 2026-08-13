class Solution {
    public:
    int repeatedStringMatch(string a, string b) {
        string s = "";
        int count = 0;

        // Repeat 'a' until its length is at least equal to 'b'
        while (s.length() < b.length()) {
            s += a;
            count++;
        }

        // Check if 'b' is a substring
        if (s.find(b) != string::npos) {
            return count;
        }

        // Check with one more repetition (to handle offset/alignment)
        s += a;
        count++;
        if (s.find(b) != string::npos) {
            return count;
        }

        // Check with a second extra repetition
        s += a;
        count++;
        if (s.find(b) != string::npos) {
            return count;
        }

        return -1;
    }
};