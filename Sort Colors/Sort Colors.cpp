class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
       if(n <= 1)
            return;

       int start = 0, end = n  - 1;
       int current = start;

       while(current <= end)
       {
            if(nums[current] == 0)
            {
                if(current == start)
                {
                    current++;
                    start++;
                }
                else
                    swap(nums[start++], nums[current]);
            }
            else if(nums[current] == 2)
            {
                if(current == end)
                {
                    return;
                }
                else
                {
                    swap(nums[end--], nums[current]);
                }
            }
            else
                current++;
       }
    }
};