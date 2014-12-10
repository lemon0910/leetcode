class Solution {
public:
    int* dp;
    int jump(int A[], int n) {
        if(n == 0)
        {
            return INT_MAX;
        }

        dp = new int[n];
        dp[0] = 0;

        for(int i = 1;i < n; i++)
            dp[i] = INT_MAX;

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(j + A[j] >= i)
                {
                    int tmp = dp[j] + 1;
                    if(tmp < dp[i])
                    {
                        dp[i] = tmp;
                        break;
                    }
                }
            }
        }
        
        return dp[n-1];
    }
};
