class Solution {
    public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;

    void build(string word, string& beginWord) {
        if (word == beginWord) {
            ans.push_back({beginWord});
            return;
        }

        for (string& p : parent[word]) {
            vector<vector<string>> temp;
            build(p, beginWord);

            for (auto path : ans) {
                if (path.back() == p) {
                    path.push_back(word);
                    temp.push_back(path);
                }
            }

            ans = temp;
        }
    }

    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList) {

            unordered_set<string> words(wordList.begin(), wordList.end());

            if (!words.count(endWord))
            return {};

            unordered_set<string> current{beginWord};
            bool found = false;

            while (!current.empty() && !found) {
                for (const string& w : current)
                words.erase(w);

                unordered_set<string> next;

                for (const string& word : current) {
                    string temp = word;

                    for (int i = 0; i < temp.size(); ++i) {
                        char original = temp[i];

                        for (char c = 'a'; c <= 'z'; ++c) {
                            if (c == original) continue;

                            temp[i] = c;

                            if (words.count(temp)) {
                                next.insert(temp);
                                parent[temp].push_back(word);

                                if (temp == endWord)
                                found = true;
                            }
                        }

                        temp[i] = original;
                    }
                }

                current = move(next);
            }

            if (!found)
            return {};

            ans.clear();

            // Build paths with a simpler DFS
            vector<string> path{endWord};

            function<void(string)> dfs = [&](string word) {
                if (word == beginWord) {
                    vector<string> result = path;
                    reverse(result.begin(), result.end());
                    ans.push_back(result);
                    return;
                }

                for (const string& p : parent[word]) {
                    path.push_back(p);
                    dfs(p);
                    path.pop_back();
                }
            };

            dfs(endWord);
            return ans;
        }
    
};