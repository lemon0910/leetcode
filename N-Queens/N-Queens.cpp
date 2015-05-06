class Solution {
public:
    bool isValid(vector<string> &board, int x, int y) 
    {
        for (int i = 0; i < x; ++i) 
        {
            if (board[i][y] == 'Q') return false;
        }

        for (int i = 0; i < board.size(); ++i) 
        {
            for (int j = 0; j < board.size(); ++j) 
            {
                if (i != x && j != y && i-j == x-y && board[i][j] == 'Q')
                    return false;
                if (i != x && j != y && i+j == x+y && board[i][j] == 'Q')
                    return false;
            }
        }
        return true;
    }
    
    void solveHelper(vector<vector<string> > &res, vector<string> &board, int idx) 
    {
        if (idx == board.size()) 
        {
            res.push_back(board);
            return;
        }
        for (int i = 0; i < board.size(); ++i) 
        {
            board[idx][i] = 'Q';
            if (isValid(board, idx, i)) 
            {
                solveHelper(res, board, idx + 1);
            }
            board[idx][i] = '.';
        }
    }
    
    vector<vector<string> > solveNQueens(int n) 
    {
        vector<vector<string> > res;
        vector<string> board;
        string row;
        for (int i = 0; i < n; ++i) 
        {
            row.push_back('.');
        }
        for (int i = 0; i < n; ++i) 
        {
            board.push_back(row);
        }
        solveHelper(res, board, 0);
        return res;
    }
};
