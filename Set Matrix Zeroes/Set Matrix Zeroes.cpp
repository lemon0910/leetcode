class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int flag = 0;
        int num = 0;

        for (int i = 0; i < m; ++i)
        {
            if (num >= m + n)
                break;

            if (matrix[i][0] == 0)
            {
                num++;
                if (0 == flag)
                {
                    flag = 1;
                    num++;
                }
            }

            for (int j = 1; j < n; ++j)
            {
                if (!matrix[i][j])
                {
                    if (matrix[i][0] != 0)
                    {
                        num++;
                        matrix[i][0] = 0;
                    }
                    if (matrix[0][j] != 0)
                    {
                        num++;
                        matrix[0][j] = 0;
                    }
                }
            }
        }

        for (int i = 1; i < m; ++i)
        {
            if (!matrix[i][0])
            {
                for (int j = 1; j < n; ++j)
                    matrix[i][j] = 0;
            }
        }

        for (int j = 1; j < n; ++j)
        {
            if (!matrix[0][j])
            {
                for (int i = 0; i < m; ++i)
                    matrix[i][j] = 0;
            }
        }

        if (!matrix[0][0])
        {
            for (int j = 0; j < n; ++j)
                matrix[0][j] = 0;
        }

        if (flag)
        {
            for (int i = 0; i < m; ++i)
                matrix[i][0] = 0;
        }
    }
};