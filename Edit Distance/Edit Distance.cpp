class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();

        if(len2 == 0)
            return len1;
        if(len1 == 0)
            return len2;

        vector<vector<int> > dp(len1, vector<int>(len2, 0));
        if(word1[0] == word2[0])
            dp[0][0] = 0;
        else
            dp[0][0] = 1;
        for(int i = 1; i < len2; ++i)
        {
            if(word1[0] == word2[i])
                dp[0][i] = min(i, dp[0][i - 1] + 1);
            else
                dp[0][i] = dp[0][i - 1] + 1;
        }
        for(int i = 1; i < len1; ++i)
        {
            if(word1[i] == word2[0])
                dp[i][0] = min(i, dp[i - 1][0] + 1);
            else
                dp[i][0] = dp[i - 1][0] + 1;
        }

        for(int i = 1; i < len1; ++i)
        {
            for(int j = 1; j < len2; ++j)
            {
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + 1;
                int temp = (word1[i] == word2[j] ? dp[i - 1][j - 1] : dp[i - 1][j - 1] + 1);
                dp[i][j] = min(dp[i][j], temp);
            }
        }

        return dp[len1 - 1][len2 - 1];
    }
};