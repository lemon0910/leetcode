class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board, int x, int y) {
        int row, col;
        
        for (row = 0; row < 9; ++row) 
        {
            if ((x != row) && (board[row][y] == board[x][y])) 
            {
                return false;
            }
        }
        
        for (col = 0; col < 9; ++col) 
        {
            if ((y != col) && (board[x][col] == board[x][y])) 
            {
                return false;
            }
        }
        
        for (row = (x / 3) * 3; row < (x / 3 + 1) * 3; ++row) 
        {
            for (col = (y / 3) * 3; col < (y / 3 + 1) * 3; ++col) 
            {
                if ((x != row) && (y != col) && (board[row][col] == board[x][y])) 
                {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool internalSolveSudoku(vector<vector<char> > &board) {
        for (int row = 0; row < 9; ++row) 
        {
            for (int col = 0; col < 9; ++col) 
            {
                if ('.' == board[row][col]) 
                {
                    for (int i = 1; i <= 9; ++i) 
                    {
                        board[row][col] = '0' + i;
                        
                        if (isValidSudoku(board, row, col)) 
                        {
                            if (internalSolveSudoku(board)) 
                            {
                                return true;
                            }
                        }
                        
                        board[row][col] = '.';
                    }
                    
                    return false;
                }
            }
        }
        
        return true;
    }
    
    void solveSudoku(vector<vector<char> > &board) {
        internalSolveSudoku(board);
    }
};