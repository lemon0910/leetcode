class Solution {
public:
    string longestPalindrome(string s) {
        int dp[1000][1000];
        memset(dp, 0, sizeof(dp));

        int len = s.size();
        if(0 == len)
        	return "";

        for(int i = 0; i < len; ++i)
        {
        	dp[i][i] = 1;
        }

        int maxlen = 1;
        int start = 0;
        int end = 0;

        for(int i = 0; i < len - 1; ++i)
        {
        	if(s[i] == s[i + 1])
        	{
        		dp[i][i + 1] = 1;
        		maxlen = 2;
        		start = i;
        		end = i + 1;
        	}
        }

        for(int i = 3; i <= len; ++i)
        {
        	for(int j = 0; j < len; j++)
        	{
        		if(j + i - 1 >= len)
        			break;
        		if(s[j] == s[j + i - 1] && dp[j + 1][j + i - 2])
        		{
        			dp[j][j + i - 1] = 1;
        			if(maxlen < i)
        			{
        				maxlen = i;
        				start = j;
        				end = j + i - 1;
        			}
        		}
        	}
        } 

        return s.substr(start, end -start + 1);
    }
};