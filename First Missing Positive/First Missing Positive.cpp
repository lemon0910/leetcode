class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty())
        {
            return 1;
        }
        
        int len = nums.size();
        int *flag = new int[len + 1];
        memset(flag, 0, sizeof(int) * (len + 1));
        
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] > len || nums[i] <= 0)
                continue;
            flag[nums[i]] = 1;
        }
        
        for(int i = 1; i <= len; ++i)
        {
            if(flag[i] == 0)
                return i;
        }
        
        return len + 1;
    }
};
