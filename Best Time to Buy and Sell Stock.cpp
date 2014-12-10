class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = prices.size();
        if(len <= 1)
            return 0;
        int res = prices[1] - prices[0], minprice = prices[0];

        for(int i = 2; i < len; i++)
        {
            minprice = min(prices[i-1], minprice);
            if(res < prices[i] - minprice)
                res = prices[i] - minprice;
        }

        if(res < 0)return 0;
        return res;
    }
};