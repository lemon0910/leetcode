class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len = prices.size();
        if(len <= 1)
            return 0;

        int i = 0;
        int res = 0;
        while(i < len - 1)
        {
            int buy, sell;
            while(i+1 < len && prices[i+1] < prices[i])
                i++;
            buy = i++;
            while(i < len && prices[i] >= prices[i-1])
                i++;
            sell = i-1;
            res += prices[sell] - prices[buy];
        }

        return res;
    }
};