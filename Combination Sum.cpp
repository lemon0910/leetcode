class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &can, int target) {
        sort(can.begin(), can.end());
        int k = 0;
        while(k < can.size() && can[k] <= target)
            k++;
        if(k <= 0)
            return vector<vector<int> >();
        vector<vector<bool> > dp(k,vector<bool>(target+1,false));
        for(int i = 0; i <= target; i++)
            if(i % can[0]==0)
                dp[0][i] = true;
        
        for(int i = 1; i < k; i++)
        {
            for(int j = 0;j < can[i]; j++)
                dp[i][j] = dp[i-1][j];
            for(int j = can[i]; j <= target; j++)
                dp[i][j] = dp[i-1][j] || dp[i][j - can[i]];
        }
        vector<vector<int> > ans;
        vector<int> path;
        createPath(ans, path, k - 1, target, dp, can);
        return ans;
    }
    void createPath(vector<vector<int> >& ans, vector<int>& path, int k, int tar, vector<vector<bool> >& dp, vector<int>& can)
    {
        if(tar == 0)
        {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return ;
        }
        if(k < 0 || !dp[k][tar])
            return ;
        if(k > 0 && dp[k-1][tar])
            createPath(ans, path, k - 1, tar, dp, can);
        if (tar >= can[k] && dp[k][tar-can[k]])
        {
            path.push_back(can[k]);
            createPath(ans, path, k, tar - can[k], dp, can);
            path.pop_back();
        }
    }
};