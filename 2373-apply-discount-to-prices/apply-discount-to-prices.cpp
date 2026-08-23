class Solution {
    public:
    string discountPrices(string sentence, int discount) {
        stringstream ss(sentence);
        string word, ans;

        while (ss >> word) {
            if (word.size() > 1 && word[0] == '$') {
                bool ok = true;

                for (int i = 1; i < word.size(); ++i) {
                    if (!isdigit(word[i])) {
                        ok = false;
                        break;
                    }
                }

                if (ok) {
                    long long price = stoll(word.substr(1));
                    long long value = price * (100 - discount);

                    word = "$" + to_string(value / 100) + "." +
                    (value % 100 < 10 ? "0" : "") +
                    to_string(value % 100);
                }
            }

            if (!ans.empty())
            ans += ' ';

            ans += word;
        }

        return ans;
    }
};