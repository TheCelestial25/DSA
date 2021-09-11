bool fun(vector<vector<char>>& board, string word, int r, int c, int i) {
    if(i >= word.length()) return true;
    if(r < board.size() and r >= 0 and c < board[0].size() and c >= 0 and board[r][c] == word[i]) {
        char cr = board[r][c];
        board[r][c] = '.';
        bool flag = fun(board, word, r-1, c, i+1) or
            fun(board, word, r, c-1, i+1) or
            fun(board, word, r+1, c, i+1) or
            fun(board, word, r, c+1, i+1);
        board[r][c] = cr;
        return flag;
    }
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    int n = board.size();
    int m = board[0].size();
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] == word[0]) {
                if(fun(board, word, i, j, 0))
                    return true;
            }
        }
    }
    return false;
}