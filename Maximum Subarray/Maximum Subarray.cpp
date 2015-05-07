class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int ret = INT_MIN;
        int cur = 0;
        for(int i = 0; i < len; ++i)
        {
            cur = max(cur + nums[i], nums[i]);
            if(cur > ret)
                ret = cur;
        }
        
        return ret;
    }
};
