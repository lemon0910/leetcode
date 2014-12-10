class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int row = board.size();
        if(row < 2)
            return;
        int col = board[0].size();
        if(col < 2)
            return;
        
        for(int i=0;i<col;i++)
        {
            if(board[0][i] == 'O')
            {
                board[0][i] = '#';
                dfs(board, 0, i, row, col);
            }
        }

        for(int i=0;i<col;i++)
        {
            if(board[row-1][i] == 'O')
            {
                board[row-1][i] = '#';
                dfs(board, row-1, i, row, col);
            }
        }

        for(int i=1;i<row-1;i++)
        {
            if(board[i][0] == 'O')
            {
                board[i][0] = '#';
                dfs(board, i, 0, row, col);
            }
        }

        for(int i=1;i<row-1;i++)
        {
            if(board[i][col-1] == 'O')
            {
                board[i][col-1] = '#';
                dfs(board, i, col-1, row, col);
            }
        }
        
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
    }
    
    void dfs(vector<vector<char>> &board, int i, int j, int row, int col)
    {
        if(i > 1 && board[i-1][j] == 'O')
        {
            board[i-1][j] = '#';
            dfs(board, i-1, j, row, col);
        }
        if(i < row-1 && board[i+1][j] == 'O')
        {
            board[i+1][j] = '#';
            dfs(board, i+1, j, row, col);
        }
        if(j > 1 && board[i][j-1] == 'O')
        {
            board[i][j-1] = '#';
            dfs(board, i, j-1, row, col);
        }
        if(j < col-1 && board[i][j+1] == 'O')
        {
            board[i][j+1] = '#';
            dfs(board, i, j+1, row, col);
        }
    }
};