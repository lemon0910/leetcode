class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1)
            return true;
        if(nums[0] > nums.size() - 1)
            return true;
            
        int maxlen = nums[0];
        if(maxlen == 0)
            return false;
            
        for(int i = 0; i < nums.size(); ++i)
        {
            if(maxlen >= i && nums[i] + i >= nums.size() - 1)
                return true;
            if(maxlen < i)
                return false;
            if(nums[i] + i > maxlen)
                maxlen = nums[i] + i;
        }
        
        return false;
    }
};
