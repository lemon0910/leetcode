class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;

        int index = 1;
        int start = 1;
        while(index < nums.size())
        {
            while(index < nums.size() && nums[index] == nums[index - 1])
                index++;

            if(index == nums.size())
                break;

            nums[start] = nums[index];
            start++;
            index++;
        }

        return start;
    }
};
