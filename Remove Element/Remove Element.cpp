class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int start = -1;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(start == -1 && nums[i] == val)
            {
                start = i;
            }
            else if(nums[i] == val)
            {
                continue;
            }
            else
            {
                if(start != -1)
                    nums[start++] = nums[i];
            }
        }
        if(start == -1)
            return nums.size();
        return start;
    }
};
