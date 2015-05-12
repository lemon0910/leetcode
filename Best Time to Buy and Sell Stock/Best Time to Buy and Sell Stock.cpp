class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int ret = 0;
        int minn = prices[0];
        for(int i = 1; i < prices.size(); ++i)
        {
            if(prices[i] - minn > ret)
                ret = prices[i] - minn;
            if(minn > prices[i])
                minn = prices[i];
        }

        return ret;
    }
};