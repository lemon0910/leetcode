class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i = nums.size() - 2; i >= 0; --i)
        {
            int index = findvalue(i + 1, nums.size() - 1, nums, nums[i]);
            int temp = INT_MAX;
            int swapindex = -1;
            int left = index - 1;
            int right = index + 1;
            if(nums[index] == nums[i])
            {
                while(left > i && nums[left] == nums[i])
                {
                    left--;
                }
                while(right < nums.size() && nums[right] == nums[i])
                {
                    right++;
                }
            }
            if(nums[index] > nums[i])
            {
                if(temp > nums[index])
                {
                    temp = nums[index];
                    swapindex = index;
                }
            }
            if(left > i && nums[left] > nums[i])
            {
                if(temp > nums[left])
                {
                    temp = nums[left];
                    swapindex = left;
                }
            }
            if(right < nums.size() && nums[right] > nums[i])
            {
                if(temp > nums[right])
                {
                    temp = nums[right];
                    swapindex = right;
                }
            }

            if(swapindex != -1)
            {
                swap(nums[i], nums[swapindex]);
                vector<int>::iterator it;
                int k;
                for(it = nums.begin(), k = 0; k <= i; k++, it++)
                {}
                sort(it, nums.end());
                return;
            }
        }

        sort(nums.begin(), nums.end());
    }

private:
    int findvalue(int start, int end, vector<int>& nums, int val)
    {
        int left = start;
        int right = end;
        int mid;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if(nums[mid] == val)
                return mid;
            else if(nums[mid] > val)
                left = mid + 1;
            else
                right = mid - 1; 
        }

        return mid;
    }
};
