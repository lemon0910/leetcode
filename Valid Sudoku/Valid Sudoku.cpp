class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int len = board.size();

        int flag[10];

        for (int i = 0; i < len; ++i)
        {
            memset(flag, 0, sizeof(flag));

            for (int j = 0; j < len; ++j)
            {
                if (board[i][j] == '.')
                    continue;
                int temp = board[i][j] - '0';
                if (flag[temp])
                    return false;
                flag[temp] = 1;
            }
        }

        for (int i = 0; i < len; ++i)
        {
            memset(flag, 0, sizeof(flag));

            for (int j = 0; j < len; ++j)
            {
                if (board[j][i] == '.')
                    continue;
                int temp = board[j][i] - '0';
                if (flag[temp])
                    return false;
                flag[temp] = 1;
            }
        }

        for (int i = 0; i < len; i += 3)
        {
            for (int j = 0; j < len; j += 3)
            {
                memset(flag, 0, sizeof(flag));

                for (int k = 0; k < 3; ++k)
                {
                    for (int l = 0; l < 3; ++l)
                    {
                        if (board[i + k][j + l] == '.')
                            continue;
                        int temp = board[i + k][j + l] - '0';
                        if (flag[temp])
                            return false;
                        flag[temp] = 1;
                    }
                }
            }
        }

        return true;
    }
};
