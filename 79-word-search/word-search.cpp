class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word,
             int r, int c, int idx) {

        if (idx == word.size())
            return true;

        int m = board.size();
        int n = board[0].size();

        if (r < 0 || r >= m || c < 0 || c >= n ||
            board[r][c] != word[idx])
            return false;

        char temp = board[r][c];
        board[r][c] = '#';

        bool found =
            dfs(board, word, r + 1, c, idx + 1) ||
            dfs(board, word, r - 1, c, idx + 1) ||
            dfs(board, word, r, c + 1, idx + 1) ||
            dfs(board, word, r, c - 1, idx + 1);

        board[r][c] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0] &&
                    dfs(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};