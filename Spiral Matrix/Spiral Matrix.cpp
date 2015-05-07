class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = 0;
        vector<int> result;
        if(n == 0)
            return result;
        if(matrix[0].size() == 0)
            return result;
        if(n > 0)
            m = matrix[0].size();
        
        if(n == 1)
        {
            for(int i = 0; i < m; ++i)
                result.push_back(matrix[0][i]);
            return result;
        }
        if(m == 1)
        {
            for(int i = 0; i < n; ++i)
                result.push_back(matrix[i][0]);
                
           return result;
        }
        for(int i = 0; i < n / 2; ++i)
        {
            if(i > m - i - 1 || i > n - i - 1)
                break;
            for(int j = i; j < m - i; ++j)
                result.push_back(matrix[i][j]);
            for(int j = i + 1; j < n - i; ++j)
                result.push_back(matrix[j][m - i - 1]);
            for(int j = m - i - 2; j >= i; --j)
                result.push_back(matrix[n - i - 1][j]);
            for(int j = n - i - 2; j > i; --j)
                result.push_back(matrix[j][i]);
        }
        if(n % 2 == 1)
        {
            for(int j = n / 2; j < m - n / 2; ++j)
                result.push_back(matrix[n / 2][j]);
        }
        
        return result;
    }
};
